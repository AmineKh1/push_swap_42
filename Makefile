NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap_instruction.c push_swap_instruction1.c push_swap_instruction2.c push_swap_instruction3.c push_swap_instruction4.c push_swap_instruction5.c func_sort.c push_swap.c 

OBJ = ${SRC:.c=.o}

RM = rm -f

all: ${NAME}

${NAME}: libftt ${OBJ}
	${CC} libft/libft.a ${OBJ}  -o ${NAME}
%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

libftt:
	$(MAKE) -C libft
	$(MAKE) -C libft bonus

clean:
	$(MAKE) -C libft clean
	${RM} ${OBJ} ${OBJB}

fclean: clean
	$(MAKE) -C libft fclean
	${RM} ${NAME}

re: fclean all
	$(MAKE) -C libft re

.PHONY: clean all bonus fclean re