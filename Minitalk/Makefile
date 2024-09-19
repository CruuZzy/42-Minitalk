# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scruz-ra <scruz-ra@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 19:12:30 by scruz-ra          #+#    #+#              #
#    Updated: 2024/06/13 19:12:30 by scruz-ra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client

INCLUDES	= ./includes/minitalk.h
LIBFT 		= ./libft/libft.a
SRCDIR 		= ./src/
OBJFILES	= ./obj/

SERVER_SRC	= $(SRCDIR)server.c
CLIENT_SRC	= $(SRCDIR)client.c

SERVER_OBJ	= $(SERVER_SRC:$(SRCDIR)%.c=$(OBJFILES)%.o)
CLIENT_OBJ	= $(CLIENT_SRC:$(SRCDIR)%.c=$(OBJFILES)%.o)

PURPLE		= \033[38;5;93m
LIGHT_PURPLE = \033[38;5;99m
LIGHT_PINK 	= \033[38;5;213m
CYAN		= \033[38;5;45m
PINK		= \033[38;5;207m
RED			= \033[31m
YELLOW		= \033[33m
GREEN		= \033[32m
RESET		= \033[0m

all: $(NAME_SERVER) $(NAME_CLIENT)
	@echo "\n"
	@echo "		$(PURPLE)███$(CYAN)╗   $(PURPLE)███$(CYAN)╗$(PURPLE)██$(CYAN)╗$(PURPLE)███$(CYAN)╗   $(PURPLE)██$(CYAN)╗$(PURPLE)██$(CYAN)╗$(PURPLE)████████$(CYAN)╗ $(PURPLE)█████$(CYAN)╗ $(PURPLE)██$(CYAN)╗     $(PURPLE)██$(CYAN)╗  $(PURPLE)██$(CYAN)╗$(RESET)"
	@echo "		$(PURPLE)████$(CYAN)╗ $(PURPLE)████$(CYAN)║$(PURPLE)██$(CYAN)║$(PURPLE)████$(CYAN)╗  $(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)║╚══$(PURPLE)██$(CYAN)╔══╝$(PURPLE)██$(CYAN)╔══$(PURPLE)██$(CYAN)╗$(PURPLE)██$(CYAN)║     $(PURPLE)██$(CYAN)║ $(PURPLE)██$(CYAN)╔╝$(RESET)"
	@echo "		$(PURPLE)██$(CYAN)╔$(PURPLE)████$(CYAN)╔$(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)╔$(PURPLE)██$(CYAN)╗ $(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)║   $(PURPLE)██$(CYAN)║   $(PURPLE)███████$(CYAN)║$(PURPLE)██$(CYAN)║     $(PURPLE)█████$(CYAN)╔╝ $(RESET)"
	@echo "		$(PURPLE)██$(CYAN)║╚$(PURPLE)██$(CYAN)╔╝$(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)║╚$(PURPLE)██$(CYAN)╗$(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)║   $(PURPLE)██$(CYAN)║   $(PURPLE)██$(CYAN)╔══$(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)║     $(PURPLE)██$(CYAN)╔═$(PURPLE)██$(CYAN)╗ $(RESET)"
	@echo "		$(PURPLE)██$(CYAN)║ ╚═╝ $(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)║$(PURPLE)██$(CYAN)║ ╚$(PURPLE)████$(CYAN)║$(PURPLE)██$(CYAN)║   $(PURPLE)██$(CYAN)║   $(PURPLE)██$(CYAN)║  $(PURPLE)██$(CYAN)║$(PURPLE)███████$(CYAN)╗$(PURPLE)██$(CYAN)║  $(PURPLE)██$(CYAN)╗$(RESET)"
	@echo "		$(CYAN)╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝$(RESET)"
	@echo "\n"

$(NAME_SERVER): $(SERVER_OBJ)
	@echo "$(YELLOW)LIBFT        |$(RESET)"
	@cd libft && $(MAKE) 2>&1 | grep -E "Compiling|error|fatal" || true
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(NAME_SERVER)
	@echo "$(YELLOW)COMPILATION  $(GREEN)| OK!$(RESET)"
	@echo "$(YELLOW)FILE:        $(GREEN)| $(NAME_SERVER)$(RESET)"

$(NAME_CLIENT): $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(NAME_CLIENT)
	@echo "$(YELLOW)COMPILATION  $(GREEN)| OK!$(RESET)"
	@echo "$(YELLOW)FILE:        $(GREEN)| $(NAME_CLIENT)$(RESET)"

$(OBJFILES)%.o: $(SRCDIR)%.c $(INCLUDES)
	@echo "$(PURPLE)Compiling... | $<$(RESET)"
	@mkdir -p $(OBJFILES)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@cd libft && make clean 2>&1 | grep -E "Compiling|error|fatal" || true
	@rm -rf $(OBJFILES)
	@echo "$(RED)OBJECTS:     | CLEANED!$(RESET)"

fclean: clean
	@cd libft && make fclean 2>&1 | grep -E "Compiling|error|fatal" || true
	@rm -rf $(NAME_SERVER) $(NAME_CLIENT)
	@echo "$(RED)All:	     | CLEANED!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
