NAME=ft_ls
CC=gcc
DEPS=libft ft_printf
ARCHIVES=libft/libft.a ft_printf/libftprintf.a
CFLAGS= -Wall -Wextra -Werror -I. $(DEPS:%=-I %) -Ofast
CFILES=	ft_ls.c			list_sorting.c ls_print.c main.c print_permissions.c \
		print_time.c	set_flags.c		compare_dirent.c	errors.c
OBJ=$(CFILES:%.c=build/%.o)

$(NAME): $(OBJ) $(ARCHIVES)
	@$(CC) $(CFLAGS) $^ -o $@

$(ARCHIVES):
	@$(MAKE) -C $(dir $@)

build/%.o: %.c ft_ls.h
	@mkdir -p build
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME);

clean:
	@for dep in $(DEPS); do	$(MAKE) -C $$dep $@; done
 
fclean: clean
	@rm -rf $(NAME)
	@for dep in $(DEPS); do	$(MAKE) -C $$dep $@; done

re: fclean all

.PHONY: clean fclean re all