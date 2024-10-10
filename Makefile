NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=thread
SRC = src/ft_check_thread.c src/ft_philo.c src/main.c\
utile/ft_check_eat_all.c utile/ft_check_error.c utile/ft_die.c utile/ft_free.c\
utile/ft_init_mutex_thread.c utile/ft_init_struct.c utile/ft_lock_unlock.c\
utile/ft_philo_actions.c utile/ft_printf_action.c utile/ft_utile_timer.c

OBJ = $(SRC:.c=.o)
TOTAL_FILES := $(words $(SRC))

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m #No Color

all : $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
		$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
		@$(CC) $(CFLAGS) -c $< -o $@
		@PROGRESS=$$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES))); \
		BAR=$$(( $(COMPILED_FILES) * 50 / $(TOTAL_FILES) )); \
		BAR_GRAPH=""; \
		i=0; \
		while [ $$i -lt $$BAR ]; do \
				BAR_GRAPH=$${BAR_GRAPH}/; \
				i=$$((i + 1)); \
		done; \
		i=$$((50 - $$BAR)); \
		while [ $$i -gt 0 ]; do \
				BAR_GRAPH="$${BAR_GRAPH} "; \
				i=$$((i - 1)); \
		done; \
		if [ $$PROGRESS -eq 100 ]; then \
				tput cuu1; tput el; echo "Compiling: [  ${GREEN}$$BAR_GRAPH${NC}] $$PROGRESS%"; \
		else \
				tput cuu1; tput el; echo  "Compiling: [  ${RED}$$BAR_GRAPH${NC}] $$PROGRESS%"; \
		fi

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
