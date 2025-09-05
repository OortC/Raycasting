# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeblee <jaeblee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 16:34:44 by jaeblee           #+#    #+#              #
#    Updated: 2024/09/23 19:44:43 by jaeblee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----STANDARD-----#
NAME = cub3d

CC = cc
CFLAG = -Wall -Wextra -Werror
CMLX = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

FT_DIR =	./libft
FT_FLAG =	-L $(FT_DIR) -l ft

#------COLORS------#
RED =		\033[0;31m
BLUE =		\033[0;34m
GREEN =		\033[1;32m
YELLOW =	\033[0;33m
RESET =		\033[0m

#-------FILES-------#
FILES =	main			\
		mini_map		\
		hook			\
		event			\
		image			\
		error			\
		draw			\
		init			\
		map				\
		map_ck_first	\
		map_ck			\
		map_dfs			\
		map_stack		\
		setting			\
		utils			\

INCS =	cub				\
		parse			\

#------SOURCE------#
DIR_SRC = ./src/

SRC_FILE =	$(addprefix $(DIR_SRC), $(FILES))
SRC_INC =	$(addprefix $(DIR_SRC), $(INCS))

SRC_SRCS =	$(addsuffix .c, $(SRC_FILE))
SRC_OBJS =	$(addsuffix .o, $(SRC_FILE))
SRC_INCS =	$(addsuffix .h, $(SRC_INC))

#------FUCTION------#
all : $(NAME)

$(DIR_SRC)%.o : $(DIR_SRC)%.c
	@echo "$(YELLOW)Compiling... $<$(RESET)"
	@$(CC) $(CFLAG) -I $(DIR_SRC) -c $< -o $@

$(NAME) : $(SRC_OBJS) $(SRC_INCS)
	@echo "$(GREEN)Linking Files...$(RESET)"
	@make -C $(FT_DIR)
	@$(CC) $(CFLAG) $(FT_FLAG) $(CMLX) $(SRC_SRCS) -o $(NAME)
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	@echo "$(GREEN)Build Complete! - $(NAME)$(RESET)"

clean :
	@echo "$(RED)Cleaning Object Files...$(RESET)"
	@make clean -C $(FT_DIR)
	@rm -rf $(SRC_OBJS)

fclean : clean
	@echo "$(RED)Removing Executable $(NAME)...$(RESET)"
	@make fclean -C $(FT_DIR)
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re