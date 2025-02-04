NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ft_printf.c \
	main.c \
	handlers/handle_char.c \
	handlers/handle_string.c \
	handlers/handle_pointer.c \
	handlers/handle_int.c \
	handlers/handle_uint.c \
	handlers/handle_hex.c \
	handlers/handle_oct.c \
	utils/ft_print_char.c \
	utils/ft_print_string.c \
	utils/ft_print_hex.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	ar rcs $@ $(OBJS)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_PATH)

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean :
	@rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean : clean
	@rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re
