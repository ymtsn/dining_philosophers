NAME				=	philo
CC					=	gcc
COMPILE_FLAGS		=	-Wall -Wextra -Werror $(INCLUDE_FLAGS) $(DEBUG_FLAGS)
SRC_DIR				=	./src
OBJ_DIR				=	./obj
INCLUCDE_DIR		=	./include
INCLUDE_FLAGS		=	-I $(INCLUCDE_DIR)
DEBUG_FLAGS			=	-g

MAIN_DIR			=	$(SRC_DIR)/main
MAIN_SRC			=	main.c
MAIN_SRC_FULLNAME	=	$(MAIN_SRC_DIR)/$(MAIN_SRC)
MAIN_OBJ			=	$(MAIN_SRC:.c=.o)
MAIN_OBJ_FULLNAME	=	$(OBJ_DIR)/$(MAIN_OBJ)

PHILO_DIR			=	$(SRC_DIR)/philosopher
PHILO_SRC			=	philo_behavior.c philo_fork.c philo_pthread.c
PHILO_SRC_FULLNAME	=	$(addprefix ./src/philosopher/, $(PHILO_SRC))
PHILO_OBJ			=	$(PHILO_SRC:.c=.o)
PHILO_OBJ_FULLNAME	=	$(addprefix ./obj/, $(PHILO_OBJ))

CREATE_VARIABLES_DIR			=	$(SRC_DIR)/create_variables
CREATE_VARIABLES_SRC			=	create_variables.c fork_variables.c free_variables.c philo_variables.c
CREATE_VARIABLES_SRC_FULLNAME	=	$(addprefix ./src/create_variables/, $(CREATE_VARIABLES_SRC))
CREATE_VARIABLES_OBJ			=	$(CREATE_VARIABLES_SRC:.c=.o)
CREATE_VARIABLES_OBJ_FULLNAME	=	$(addprefix ./obj/, $(CREATE_VARIABLES_OBJ))

MONITOR_DIR				=	$(SRC_DIR)/monitor
MONITOR_SRC				=	monitor.c
MONITOR_SRC_FULLNAME	=	$(MONITOR_DIR)/$(MONITOR_SRC)
MONITOR_OBJ				=	$(MONITOR_SRC:.c=.o)
MONITOR_OBJ_FULLNAME	=	$(OBJ_DIR)/$(MONITOR_OBJ)

WAITER_DIR				=	$(SRC_DIR)/waiter
WAITER_SRC				=	waiter.c
WAITEER_SRC_FULLNAME	=	$(addprefix ./src/waiter/, $(WAITER_SRC))
WAITER_OBJ				=	$(WAITER_SRC:.c=.o)
WAITER_OBJ_FULLNAME		=	$(addprefix ./obj/, $(WAITER_OBJ))

DEBUG_DIR			=	$(SRC_DIR)/debug
DEBUG_SRC			=	debug.c
DEBUG_SRC_FULLNAME	=	$(DEBUG_DIR)/$(DEBUG_SRC)
DEBUG_OBJ			=	$(DEBUG_SRC:.c=.o)
DEBUG_OBJ_FULLNAME	=	$(OBJ_DIR)/$(DEBUG_OBJ)

OBJ_LIST			=	$(MAIN_OBJ_FULLNAME) \
						$(CREATE_VARIABLES_OBJ_FULLNAME) \
						$(PHILO_OBJ_FULLNAME) \
						$(FORK_OBJ_FULLNAME) \
						$(MONITOR_OBJ_FULLNAME) \
						$(WAITER_OBJ_FULLNAME) \
						$(DEBUG_OBJ_FULLNAME)

all		:	$(NAME)
$(NAME)	:	$(OBJ_LIST)
	$(CC) $(OBJ_LIST) -o $(NAME)

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

$(OBJ_DIR)/%.o:$(DEBUG_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) -c $^ -o $@

clean	:
	rm -rf $(OBJ_LIST)

fclean	:clean
	rm -rf $(NAME)

re		:fclean
	all

.PHONY	:all clean fclean re
