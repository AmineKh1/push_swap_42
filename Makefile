NAME = push_swap
NAMEB = checker_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap_instruction.c push_swap_instruction1.c push_swap_instruction2.c push_swap_instruction3.c push_swap_instruction4.c push_swap_instruction5.c func_sort.c push_swap.c push_instra.c print_stack.c
SRCB = push_swap_instruction.c push_swap_instruction1.c push_swap_instruction2.c push_swap_instruction3.c push_swap_instruction4.c push_swap_instruction5.c func_sort.c instruction_checker_bonus.c push_instra.c instruction_checker1_bonus.c push_swap_bonus.c get_next_line.c print_stack.c
OBJ = ${SRC:.c=.o}
OBJB = ${SRCB:.c=.o}
RM = rm -f

all: ${NAME}
bonus: ${NAMEB}
${NAME}: libftt ${OBJ}
	${CC} libft/libft.a ${OBJ}  -o ${NAME}
${NAMEB}: libftt ${OBJB}
	${CC} libft/libft.a ${OBJB}  -o ${NAMEB}
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
	${RM} ${NAME} ${NAMEB}

re: fclean all
	$(MAKE) -C libft re

.PHONY: clean all bonus fclean re