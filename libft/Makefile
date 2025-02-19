# Les fonctions de la partie obligatoire
SRC_MAND	= ft_isalnum.c ft_calloc.c ft_atoi.c ft_memchr.c ft_putstr_fd.c ft_putchar_fd.c ft_split.c ft_itoa.c ft_isalpha.c ft_memset.c ft_memcmp.c ft_strjoin.c ft_memcpy.c ft_substr.c ft_strlcpy.c ft_isprint.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_strtrim.c ft_toupper.c ft_memmove.c ft_isascii.c ft_strlcat.c ft_striteri.c ft_putendl_fd.c ft_strlen.c ft_bzero.c ft_putnbr_fd.c ft_strchr.c ft_isdigit.c ft_strnstr.c ft_strncmp.c ft_strrchr.c

# Les fonctions de la partie bonus
SRC_BONUS	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstmap.c

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
AR		= ar rcs

# OBJ_MAND et OBJ_BONUS sont identiques a SRC_MAND et SRC_BONUS
# avec comme difference, leurs suffixe : .c qui deviennent .o
OBJ_MAND	= $(SRC_MAND:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

# $(NAME) ne pourra pas etre executee si $(OBJ_MAND) n'existe pas.
# libft.a est une archive (avec ar rcs) de tout les fichiers .o
$(NAME):	$(OBJ_MAND)
			$(AR) $(NAME) $(OBJ_MAND)

# bonus fera aussi 'ar rcs libft.a ..' avec les fichiers .o du bonus
bonus:		$(OBJ_BONUS)
			$(AR) $(NAME) $(OBJ_BONUS)

# all est la regles par defaut, c'est ce qui sera executee si on fait
# 'make' dans le terminal. Ici, c'est $(NAME) qui sera appelee
all:		$(NAME)

# clean supprimera tout les fichier .o, bonus compris mais pas libft.a
clean:
			$(RM) $(OBJ_MAND) $(OBJ_BONUS)

# fclean (fullclean) supprimera tout les .o, bonus compris mais aussi libft.a
fclean:		clean
			$(RM) $(NAME)

# re executera fclean, puis all. En gros il efface tout, et REcompile tout.
re:			fclean all

# .PHONY sers a eviter les conflits entre noms de fichier et noms de regles.
# Si j'ai un fichier qui s'apelle clean, c'est chiant par exemple, .PHONY s'en occupe
.PHONY:		bonus all clean fclean re