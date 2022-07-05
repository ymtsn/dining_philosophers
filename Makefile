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
PHILO_SRC			=	philosopher_pthread.c philosopher_behavior.c philosopher_variable.c
PHILO_SRC_FULLNAME	=	$(addprefix ./src/philosopher/, $(PHILO_SRC))
PHILO_OBJ			=	$(PHILO_SRC:.c=.o)
PHILO_OBJ_FULLNAME	=	$(addprefix ./obj/, $(PHILO_OBJ))

FORK_DIR			=	$(SRC_DIR)/fork
FORK_SRC			=	fork.c
FORK_SRC_FULLNAME	=	$(FORK_DIR)/$(FORK_SRC)
FORK_OBJ			=	$(FORK_SRC:.c=.o)
FORK_OBJ_FULLNAME	=	$(OBJ_DIR)/$(FORK_OBJ)

MONITOR_DIR				=	$(SRC_DIR)/monitor
MONITOR_SRC				=	monitor.c
MONITOR_SRC_FULLNAME	=	$(MONITOR_DIR)/$(MONITOR_SRC)
MONITOR_OBJ				=	$(MONITOR_SRC:.c=.o)
MONITOR_OBJ_FULLNAME	=	$(OBJ_DIR)/$(MONITOR_OBJ)

DEBUG_DIR			=	$(SRC_DIR)/debug
DEBUG_SRC			=	debug.c
DEBUG_SRC_FULLNAME	=	$(DEBUG_DIR)/$(DEBUG_SRC)
DEBUG_OBJ			=	$(DEBUG_SRC:.c=.o)
DEBUG_OBJ_FULLNAME	=	$(OBJ_DIR)/$(DEBUG_OBJ)

OBJ_LIST			=	$(MAIN_OBJ_FULLNAME) \
						$(PHILO_OBJ_FULLNAME) \
						$(FORK_OBJ_FULLNAME) \
						$(MONITOR_OBJ_FULLNAME) \
						$(DEBUG_OBJ_FULLNAME)

all		:	$(NAME)
$(NAME)	:	$(OBJ_LIST)
	$(CC) $(OBJ_LIST) -o $(NAME)

$(OBJ_DIR)/%.o:$(MAIN_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(PHILO_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(FORK_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(COMPILE_FLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o:$(MONITOR_DIR)/%.c
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
