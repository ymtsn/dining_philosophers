CC					=	gcc
COMPILE_FLAGS		=	-Wall -Wextra -Werror -pthread $(INCLUDE_FLAGS) $(DEBUG_FLAGS)
INCLUDE_FLAGS		=	-I $(INCLUCDE_DIR)
DEBUG_FLAGS			=

MAIN_SRC			=	main.c
MAIN_SRC_FULLNAME	=	$(addprefix ./src/main/, $(MAIN_SRC))
MAIN_OBJ			=	$(MAIN_SRC:.c=.o)
MAIN_OBJ_FULLNAME	=	$(addprefix ./obj/, $(MAIN_OBJ))

MAIN_SRC_BONUS			=	main_bonus.c
MAIN_SRC_FULLNAME_BONUS	=	$(addprefix ./src_bonus/main/, $(MAIN_SRC_BONUS))
MAIN_OBJ_BONUS			=	$(MAIN_SRC_BONUS:.c=.o)
MAIN_OBJ_FULLNAME_BONUS	=	$(addprefix ./obj_bonus/, $(MAIN_OBJ_BONUS))

PHILO_SRC			=	philo_behavior.c philo_fork.c philo_pthread.c philo_timestamp.c
PHILO_SRC_FULLNAME	=	$(addprefix ./src/philosopher/, $(PHILO_SRC))
PHILO_OBJ			=	$(PHILO_SRC:.c=.o)
PHILO_OBJ_FULLNAME	=	$(addprefix ./obj/, $(PHILO_OBJ))

PHILO_SRC_BONUS				=	philo_behavior_bonus.c philo_confirm_die_bonus.c philo_fork_bonus.c \
								philo_create_process_bonus.c philo_sem_utils.c philo_timestamp_bonus.c
PHILO_SRC_FULLNAME_BONUS	=	$(addprefix ./src_bonus/philosopher/, $(PHILO_SRC_BONUS))
PHILO_OBJ_BONUS				=	$(PHILO_SRC_BONUS:.c=.o)
PHILO_OBJ_FULLNAME_BONUS	=	$(addprefix ./obj_bonus/, $(PHILO_OBJ_BONUS))

CREATE_VARIABLES_SRC				=	create_variables.c fork_variables.c free_variables.c ft_atoi_plus.c ft_bzero.c philo_variables.c
CREATE_VARIABLES_SRC_FULLNAME		=	$(addprefix ./src/create_variables/, $(CREATE_VARIABLES_SRC))
CREATE_VARIABLES_OBJ				=	$(CREATE_VARIABLES_SRC:.c=.o)
CREATE_VARIABLES_OBJ_FULLNAME		=	$(addprefix ./obj/, $(CREATE_VARIABLES_OBJ))

CREATE_VARIABLES_SRC_BONUS			=	create_variables_bonus.c free_variables_bonus.c ft_atoi_plus_bonus.c ft_bzero_bonus.c philo_variables_bonus.c
CREATE_VARIABLES_SRC_FULLNAME_BONUS	=	$(addprefix ./src/create_variables_bonus/, $(CREATE_VARIABLES_SRC_BONUS))
CREATE_VARIABLES_OBJ_BONUS			=	$(CREATE_VARIABLES_SRC_BONUS:.c=.o)
CREATE_VARIABLES_OBJ_FULLNAME_BONUS	=	$(addprefix ./obj_bonus/, $(CREATE_VARIABLES_OBJ_BONUS))

MONITOR_SRC				=	monitor.c
MONITOR_SRC_FULLNAME	=	$(addprefix ./src/monitor/, $(MONITOR_SRC))
MONITOR_OBJ				=	$(MONITOR_SRC:.c=.o)
MONITOR_OBJ_FULLNAME	=	$(addprefix ./obj/, $(MONITOR_OBJ))

MONITOR_SRC_BONUS			=	monitor_bonus.c killer_bonus.c
MONITOR_SRC_FULLNAME_BONUS	=	$(addprefix ./src_bonus/monitor/, $(MONITOR_SRC))
MONITOR_OBJ_BONUS			=	$(MONITOR_SRC_BONUS:.c=.o)
MONITOR_OBJ_FULLNAME_BONUS	=	$(addprefix ./obj_bonus/, $(MONITOR_OBJ_BONUS))

WAITER_SRC				=	waiter.c
WAITEER_SRC_FULLNAME	=	$(addprefix ./src/waiter/, $(WAITER_SRC))
WAITER_OBJ				=	$(WAITER_SRC:.c=.o)
WAITER_OBJ_FULLNAME		=	$(addprefix ./obj/, $(WAITER_OBJ))

WAITER_SRC_BONUS			=	waiter_bonus.c
WAITEER_SRC_FULLNAME_BONUS	=	$(addprefix ./src_bonus/waiter/, $(WAITER_SRC_BONUS))
WAITER_OBJ_BONUS			=	$(WAITER_SRC_BONUS:.c=.o)
WAITER_OBJ_FULLNAME_BONUS	=	$(addprefix ./obj_bonus/, $(WAITER_OBJ_BONUS))

DEBUG_DIR			=	./src/debug
DEBUG_SRC			=	debug.c
DEBUG_SRC_FULLNAME	=	$(addprefix ./src/debug/, $(DEBUG_SRC))
DEBUG_OBJ			=	$(DEBUG_SRC:.c=.o)
DEBUG_OBJ_FULLNAME	=	$(addprefix ./obj/, $(DEBUG_OBJ))

OBJ_LIST_MAN		=	$(MAIN_OBJ_FULLNAME) \
						$(CREATE_VARIABLES_OBJ_FULLNAME) \
						$(PHILO_OBJ_FULLNAME) \
						$(MONITOR_OBJ_FULLNAME) \
						$(WAITER_OBJ_FULLNAME)
OBJ_LIST_BONUS		=	$(MAIN_OBJ_FULLNAME_BONUS) \
						$(CREATE_VARIABLES_OBJ_FULLNAME_BONUS) \
						$(PHILO_OBJ_FULLNAME_BONUS) \
						$(MONITOR_OBJ_FULLNAME_BONUS) \
						$(WAITER_OBJ_FULLNAME_BONUS)

ifdef DO_BONUS
NAME					=	$(PHILO_NAME_DIR)/philo_bonus
PHILO_NAME_DIR			=	./philo_bonus
MAIN_DIR				=	./src_bonus/main
CREATE_VARIABLES_DIR 	=	./src_bonus/create_variables
PHILO_DIR 				=	./src_bonus/philosopher
MONITOR_DIR 			=	./src_bonus/monitor
WAITER_DIR 				=	./src_bonus/waiter
INCLUCDE_DIR			=	./include_bonus
OBJ_DIR					=	./obj_bonus
OBJ_LIST 				= $(OBJ_LIST_BONUS)
else
NAME					=	$(PHILO_NAME_DIR)/philo
PHILO_NAME_DIR			=	./philo
MAIN_DIR				=	./src/main
CREATE_VARIABLES_DIR 	=	./src/create_variables
PHILO_DIR 				=	./src/philosopher
MONITOR_DIR 			=	./src/monitor
WAITER_DIR 				=	./src/waiter
INCLUCDE_DIR			=	./include
OBJ_DIR					=	./obj
OBJ_LIST 				= $(OBJ_LIST_MAN)
endif

all		:	$(NAME)
$(NAME)	:	$(OBJ_LIST)
	@mkdir -p $(PHILO_NAME_DIR)
	$(CC) $(COMPILE_FLAGS) $(OBJ_LIST) -o $(NAME)

$(OBJ_DIR)/%.o:$(MAIN_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(CREATE_VARIABLES_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(PHILO_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(MONITOR_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(WAITER_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) -c $^ -o $@

bonus	:
	make DO_BONUS=yes

clean	:
	rm -rf $(OBJ_LIST_MAN)
	rm -rf $(OBJ_LIST_BONUS)

fclean	:clean
	rm -rf ./philo/philo
	rm -rf ./philo_bonus/philo_bonus

norm	:
	norminette ./src ./src_bonus ./include ./include_bonus | grep "Error" || true

debug :
	make DEBUG_FLAGS="-g -fsanitize=thread"

valgrind :
	make fclean
	make DEBUG_FLAGS="-g3"
	valgrind valgrind --tool=helgrind ./philo/philo 4 200 100 100

debug-address :
	make DEBUG_FLAGS="-g -fsanitize=address -fsanitize=undefined -fsanitize=integer"

debug-bonus :
	make DO_BONUS=yes DEBUG_FLAGS="-g -fsanitize=thread"

valgrind-bonus:
	make fclean
	make DO_BONUS=yes DEBUG_FLAGS="-g3"
	valgrind valgrind --tool=helgrind ./philo_bonus/philo_bonus 4 200 100 100

debug-bonus-address :
	make DO_BONUS=yes DEBUG_FLAGS="-g -fsanitize=address -fsanitize=undefined -fsanitize=integer"

re		:fclean all

.PHONY	:all bonus clean fclean re
