NAME = libftprintf.a

CC = gcc
CFLAGSES = -Wall -Wextra -Werror

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ft_printf.c \
	main.c

OBJS = $(SRCS:.c=.o)

$(LIBFT) :
	cd $(LIBFT_PATH) && make
	cp $(LIBFT) $(NAME)

all : $(NAME)
bonus : all

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

%.o : %.c
	$(CC) $(CFLAGSES) -c $< -o $@



clean :
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

rebonus : fclean bonus
	cd $(LIBFT_PATH) && make fclean

.PHONY : all clean fclean re bonus rebonus






