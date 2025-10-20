#!/bin/bash
set -e

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Iniciando las variables de MariaDB..."
    
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    
    envsubst < /tmp/create_db.sql > /tmp/init_db.sql
    
    mysqld --user=mysql --skip-networking &
    MYSQL_PID=$!

    echo "Esperando a que MySQL se inicie..."
    for i in {1..30}; do
        if mysql -uroot -e "SELECT 1" >/dev/null 2>&1; then
            echo "¡MySQL está listo!"
            break
        fi
        echo "Esperando a que MySQL se inicie... ($i/30)"
        sleep 1
    done
    
    # Set root password
    mysql -uroot -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
    
    # Execute the SQL script from create_db.sql
    mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" < /tmp/init_db.sql
    
    # Stop the temporary MySQL instance
    kill $MYSQL_PID
    wait $MYSQL_PID

    echo "La base de datos de MariaDB se ha inicializado correctamente."
fi

echo "Iniciando el servidor de MariaDB..."
exec mysqld --user=mysql --console
