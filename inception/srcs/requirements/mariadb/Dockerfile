FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y && apt install apt-utils -y && \
    apt-get install -y mariadb-server mariadb-client gettext-base && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

COPY ./conf/server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/create_db.sql /tmp/create_db.sql

COPY ./tools/entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh && \
    mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    chmod 777 /var/run/mysqld

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

CMD ["mysqld"]
