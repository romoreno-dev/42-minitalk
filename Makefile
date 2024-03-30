# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 23:55:27 by romoreno          #+#    #+#              #
#    Updated: 2023/10/29 23:55:27 by romoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
LIBFT_ROUTE 		:= include/libft
COMPILER 			:= gcc -Wall -Wextra -Werror -I./$(LIBFT_ROUTE)/include
REMOVER				:= rm -rf

CLIENT_MAIN 		:= src/client/main.c
SERVER_MAIN 		:= src/server/main.c

CLIENT_MAIN_BONUS 	:= src/client/main_bonus.c
SERVER_MAIN_BONUS 	:= src/server/main_bonus.c

LIBFT 				:= $(LIBFT_ROUTE)/libft.a

# Styles
PRINT_TEXT			:= \033[0m
BOLD 				:= \033[1m
GREEN				:= \033[0;32m
BLUE				:= \033[0;94m

# Rules
all: client server

server: $(LIBFT)
		@echo "Creating server..."
		@$(COMPILER) $(SERVER_MAIN) $(LIBFT) -o server
		@echo "$(GREEN)$(BOLD)server created!$(PRINT_TEXT)"

client: $(LIBFT)
		@echo "Creating client..."
		@$(COMPILER) $(CLIENT_MAIN) $(LIBFT) -o client
		@echo "$(GREEN)$(BOLD)client created!$(PRINT_TEXT)"

bonus: $(LIBFT) client_bonus server_bonus

client_bonus: $(LIBFT)
		@echo "Creating client_bonus..."
		@$(COMPILER) $(CLIENT_MAIN_BONUS) $(LIBFT) -o client
		@echo "$(GREEN)$(BOLD)client_bonus created!$(PRINT_TEXT)"

server_bonus: $(LIBFT)
		@echo "Creating server_bonus..."
		@$(COMPILER) $(SERVER_MAIN_BONUS) $(LIBFT) -o server
		@echo "$(GREEN)$(BOLD)server_bonus created!$(PRINT_TEXT)"

$(LIBFT):
		@make -C $(LIBFT_ROUTE)

clean:
		@echo "Cleaning..."
		@make clean -C $(LIBFT_ROUTE)
		@echo "$(BLUE)All objects files were cleaned!$(PRINT_TEXT)"

fclean:
		@make fclean -C $(LIBFT_ROUTE)
		@$(REMOVER) client server
		@echo "$(BLUE)All compiled files were cleaned!$(PRINT_TEXT)"

re: 	fclean all

.PHONY: all clean fclean re
