
NAME = libftls.a
FLAGS = -Wall -Werror -Wextra
CC = gcc
OPTION = -c -I ft_printf -I ft_printf/libft
SRC = dir_count.c sort_ascending.c sort_descending.c init_dirent.c parse_flag.c format_l.c \
      sort_ltime.c sort_etime.c ft_timecmp.c init_files.c print_flag.c format_R.c
OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(OPTION) $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all


