
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
CC = gcc
OPTION = -c -I libft
SRC = ft_printf.c init_flags.c is_conversion.c insert_string.c insert_decimal.c \
      insert_char.c insert_percent.c insert_wstring.c insert_wchar.c insert_octal.c \
	  insert_hex.c insert_udecimal.c insert_hex_u.c
OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(OPTION) $(FLAGS) $(SRC) 
	@ar rc $(NAME) $(OBJECT) libft/libft.a
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all


