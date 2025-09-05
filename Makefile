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

#FLAG
NAME = cub3d

CC = cc
CFLAG = -Wall -Wextra -Werror
CMLX = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

FT_DIR =	./libft
FT_FLAG =	-L $(FT_DIR) -l ft

#FILES
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

DIR_MDT = ./mandatory/

MDT_FILE = $(addprefix $(DIR_MDT), $(FILES))

MDT_INC =	$(addprefix $(DIR_MDT), $(INCS))

MDT_SRCS = $(addsuffix .c, $(MDT_FILE))

MDT_OBJS = $(addsuffix .o, $(MDT_FILE))

MDT_INCS = $(addsuffix .h, $(MDT_INC))

#FUNCTION
$(NAME) = all

all : make_mdt

$(DIR_MDT)%.o : $(DIR_MDT)%.c
	$(CC) $(CFLAG) -I $(DIR_MDT) -c $< -o $@

make_mdt : $(MDT_OBJS) $(MDT_INCS)
	make -C $(FT_DIR)
	$(CC) $(CFLAG) $(FT_FLAG) $(CMLX) $(MDT_SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	touch $@

clean :
	make clean -C $(FT_DIR)
	rm -rf $(MDT_OBJS)
	rm -rf make_mdt

fclean : clean
	make fclean -C $(FT_DIR)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re