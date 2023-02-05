CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

NAME		=	libftprintf.a

SRCS		=	ft_printf.c		\
				ft_char_str.c	\
				ft_nbr_ptr.c

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 