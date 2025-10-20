#!/bin/bash
set -e

echo "Esperando a que MariaDB esté disponible..."
until mysql -h"${MYSQL_HOST}" -u"${MYSQL_USER}" -p"${MYSQL_PASSWORD}" "${MYSQL_DATABASE}" -e "SELECT 1" >/dev/null 2>&1; do
    echo "MariaDB no está disponible - durmiendo"
    sleep 3
done
echo "¡MariaDB está en funcionamiento!"

cd /var/www/html

if [ ! -f wp-config.php ]; then
    echo "Instalando WordPress..."
    
    wp core download --allow-root
    
    wp config create \
        --dbname="${WORDPRESS_DB_NAME}" \
        --dbuser="${WORDPRESS_DB_USER}" \
        --dbpass="${WORDPRESS_DB_PASSWORD}" \
        --dbhost="${WORDPRESS_DB_HOST}" \
        --dbcharset="utf8" \
        --dbcollate="" \
        --allow-root
    
    wp core install \
        --url="${WORDPRESS_URL}" \
        --title="${WORDPRESS_TITLE}" \
        --admin_user="${WORDPRESS_ADMIN_USER}" \
        --admin_password="${WORDPRESS_ADMIN_PASSWORD}" \
        --admin_email="${WORDPRESS_ADMIN_EMAIL}" \
        --skip-email \
        --allow-root
    
    wp user create \
        "${WORDPRESS_USER}" \
        "${WORDPRESS_USER_EMAIL}" \
        --role=author \
        --user_pass="${WORDPRESS_USER_PASSWORD}" \
        --allow-root

    echo "¡WordPress se ha instalado correctamente!"
else
    echo "WordPress ya está instalado."
fi

chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html

echo "Iniciando PHP-FPM..."
exec php-fpm7.4 -F
