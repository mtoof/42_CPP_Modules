# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 15:49:42 by mtoof             #+#    #+#              #
#    Updated: 2024/02/11 11:25:38 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  Form_up_maggots

SRC = main.cpp Bureaucrat.cpp Form.cpp
SRC_DIR = src/
HEADER = header/
FLAG =  -Wall -Wextra -Werror -std=c++14
OBJ_DIR = obj/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
# ANSI escape sequences for text formatting
BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m

vpath %.cpp $(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)$(BOLD)Make outfiles...$(NC)"
	@c++ $(FLAG) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@c++ $(FLAG) -I$(HEADER) -c $< -o $@

clean:
	@echo "$(CYAN)$(BOLD)Cleaning object files...$(NC)"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)$(BOLD)Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) successfully cleaned!$(NC)"

re: fclean all