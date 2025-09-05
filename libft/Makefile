#-----STANDARD-----#
NAME = libft.a

CC = cc
CFLAG = -Wall -Wextra -Werror -I

SRC_DIR =	src/
OBJ_DIR =	obj/
INCLUDE =	includes/

#------SOURCE------#

DIR_IS_TO =	ft_is_to/
SRC_IS_TO =	ft_isalnum			\
			ft_isalpha			\
			ft_isascii 			\
			ft_isdigit 			\
			ft_isprint 			\
			ft_tolower 			\
			ft_toupper 			\

DIR_STR =	ft_str/
SRC_STR =	ft_strchr 			\
			ft_strdup 			\
			ft_striteri 		\
			ft_strjoin 			\
			ft_strlcat 			\
			ft_strlcpy 			\
			ft_strlen 			\
			ft_strmapi 			\
			ft_strncmp 			\
			ft_strnstr 			\
			ft_strrchr 			\
			ft_strtrim 			\
			ft_substr 			\

DIR_MEM =	ft_mem/
SRC_MEM =	ft_memchr 			\
			ft_memcmp 			\
			ft_memcpy 			\
			ft_memmove 			\
			ft_memset			\
			ft_bzero 			\
			ft_calloc 			\

DIR_PUT =	ft_put/
SRC_PUT =	ft_putchar_fd 		\
			ft_putendl_fd 		\
			ft_putnbr_fd 		\
			ft_putstr_fd 		\

DIR_LST =	ft_lst/
SRC_LST =	ft_lstnew	 		\
			ft_lstsize 			\
			ft_lstlast 			\
			ft_lstadd_back		\
			ft_lstadd_front 	\
			ft_lstiter 			\
			ft_lstdelone 		\
			ft_lstclear 		\
			ft_lstmap 			\

DIR_ETC =	ft_etc/
SRC_ETC =	ft_atoi 			\
			ft_itoa 			\
			ft_utoa				\
			ft_split 			\

DIR_GNL =	gnl/
SRC_GNL =	get_next_line		\
			get_next_line_utils

SRC_FILE +=	$(addprefix $(DIR_IS_TO), $(SRC_IS_TO))
SRC_FILE +=	$(addprefix $(DIR_STR), $(SRC_STR))
SRC_FILE +=	$(addprefix $(DIR_MEM), $(SRC_MEM))
SRC_FILE +=	$(addprefix $(DIR_PUT), $(SRC_PUT))
SRC_FILE +=	$(addprefix $(DIR_LST), $(SRC_LST))
SRC_FILE +=	$(addprefix $(DIR_ETC), $(SRC_ETC))
SRC_FILE +=	$(addprefix $(DIR_GNL), $(SRC_GNL))

SRCS =		$(addprefix $(SRC_DIR),$(addsuffix .c, $(SRC_FILE)))
OBJS =		$(addprefix $(OBJ_DIR),$(addsuffix .o, $(SRC_FILE)))

#------FUCTION------#

all : $(NAME)

$(NAME) : make_dir make_ar

make_dir :
	@mkdir -p $(OBJ_DIR);
	@mkdir -p $(OBJ_DIR)$(DIR_IS_TO);
	@mkdir -p $(OBJ_DIR)$(DIR_STR);
	@mkdir -p $(OBJ_DIR)$(DIR_MEM);
	@mkdir -p $(OBJ_DIR)$(DIR_PUT);
	@mkdir -p $(OBJ_DIR)$(DIR_LST);
	@mkdir -p $(OBJ_DIR)$(DIR_ETC);
	@mkdir -p $(OBJ_DIR)$(DIR_GNL);
	@touch $@

make_ar : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@touch $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@

clean :
	@rm -rf make_dir make_ar
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re