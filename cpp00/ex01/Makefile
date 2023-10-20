# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 14:52:33 by mtoof             #+#    #+#              #
#    Updated: 2023/10/17 10:30:50 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Phonebook
SRC = Phonebook.cpp Contac.cpp main.cpp
FLAG =  -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)
# ANSI escape sequences for text formatting
BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m

%.o: %.cpp
	@g++ $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)$(BOLD)Make outfiles...$(NC)"
	@g++ $(FLAG) $(OBJ) -o $(NAME)

clean:
	@echo "$(CYAN)$(BOLD)Cleaning object files...$(NC)"
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "$(CYAN)$(BOLD)Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) successfully cleaned!$(NC)"

re: fclean all