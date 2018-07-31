NAME=ft_ls
DEPS=libft/libft.a ft_printf/libftprintf.a
LIBFT_DIR=libft
INCLUDES=$(LIBFT_DIR)/includes
REL_DEPS=$(DEPS:%=$(LIBFT_DIR)/%)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -I . -Ofast
CFILES=	ft_ls.c			list_sorting.c 		ls_print.c	 main.c  ls_utils.c	\
		set_flags.c		compare_dirent.c	errors.c	filetype.c

OBJ=$(CFILES:%.c=build/%.o)

$(NAME): $(OBJ) $(REL_DEPS)
	@gcc $(CFLAGS) $(OBJ) $(REL_DEPS) -o $(NAME)

$(REL_DEPS):
	@make -C $(dir $@)

build/%.o: %.c
	@mkdir -p build
	@$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME);

clean fclean re::
	@for file in $(dir $(REL_DEPS)) ; do $(MAKE) -C $$file $@ ; done

clean::
	@rm -rf build/

fclean::
	@rm -rf $(NAME)

re:: fclean all

.PHONY: clean fclean re all $(REL_DEPS)