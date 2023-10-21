# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 14:52:33 by mtoof             #+#    #+#              #
#    Updated: 2023/10/21 21:49:43 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
SRC = PhoneBook.cpp Contact.cpp main.cpp
HEADER = Contact.hpp PhoneBook.hpp
FLAG =  -Wall -Wextra -Werror -std=c++98
OBJ_DIR = obj/
OBJS = $(SRC:%.cpp=$(OBJ_DIR)%.o)
# ANSI escape sequences for text formatting
BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)$(BOLD)Make outfiles...$(NC)"
	@g++ $(FLAG) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@g++ $(FLAG) -c $< -o $@

clean:
	@echo "$(CYAN)$(BOLD)Cleaning object files...$(NC)"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)$(BOLD)Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) successfully cleaned!$(NC)"

re: fclean all