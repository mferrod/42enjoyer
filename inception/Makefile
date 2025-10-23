NAME=inception
COMPOSE=docker-compose -f srcs/docker-compose.yml
DATA_PATH=/home/$(USER)/data

all: up

up:
	@mkdir -p $(DATA_PATH)/wordpress
	@mkdir -p $(DATA_PATH)/mariadb
	$(COMPOSE) up --build -d

down:
	$(COMPOSE) down

re: fclean all

stop:
	$(COMPOSE) stop

start:
	$(COMPOSE) start

ps:
	$(COMPOSE) ps

logs:
	$(COMPOSE) logs -f

clean:
	$(COMPOSE) down -v --remove-orphans

fclean: clean
	@if [ -d "$(DATA_PATH)" ]; then sudo rm -rf $(DATA_PATH); fi
	@docker system prune -af --volumes

.PHONY: all up down re stop start ps logs clean fclean