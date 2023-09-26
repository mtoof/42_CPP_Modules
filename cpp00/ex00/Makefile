# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 15:59:17 by mtoof             #+#    #+#              #
#    Updated: 2023/08/31 16:24:44 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC = megaphone.cpp
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