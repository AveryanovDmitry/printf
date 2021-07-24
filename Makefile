LIBFT = libft/libft.a

NAME = libftprintf.a

SRCS			=	ft_printf.c \
					spec_efect.c \
					char_processing.c \
					init_only_flags.c \
					int_processing.c \
					str_processing.c \
					here_width.c \
					ft_u_itoa.c \
					hex_processing.c \
					pointer_processing.c \
					for_unsigned_int.c \
					ull_processing.c \
					ft_putchar.c \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

