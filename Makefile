CC					=	gcc
COMPILE_FLAGS		=	-Wall -Wextra -Werror $(INCLUDE_FLAGS) $(DEBUG_FLAGS)

ifdef DO_BONUS
NAME				=	$(PHILO_NAME_DIR)/philo_bonus
PHILO_NAME_DIR		=	./philo_bonus
SRC_DIR				=	./src_bonus
INCLUCDE_DIR		=	./include_bonus
else
NAME				=	$(PHILO_NAME_DIR)/philo
PHILO_NAME_DIR		=	./philo
SRC_DIR				=	./src
INCLUCDE_DIR		=	./include
endif

OBJ_DIR				=	./obj
INCLUDE_FLAGS		=	-I $(INCLUCDE_DIR)
DEBUG_FLAGS			=	-g

MAIN_DIR			=	$(SRC_DIR)/main
ifdef DO_BONUS
MAIN_SRC			=	main_bonus.c
else
MAIN_SRC			=	main.c
endif
MAIN_SRC_FULLNAME	=	$(MAIN_SRC_DIR)/$(MAIN_SRC)
MAIN_OBJ			=	$(MAIN_SRC:.c=.o)
MAIN_OBJ_FULLNAME	=	$(OBJ_DIR)/$(MAIN_OBJ)

PHILO_DIR			=	$(SRC_DIR)/philosopher
ifdef DO_BONUS
PHILO_SRC			=	philo_behavior_bonus.c philo_fork_bonus.c philo_create_process_bonus.c
PHILO_SRC_FULLNAME	=	$(addprefix ./src_bonus/philosopher/, $(PHILO_SRC))
else
PHILO_SRC			=	philo_behavior.c philo_fork.c philo_pthread_bonus.c
PHILO_SRC_FULLNAME	=	$(addprefix ./src/philosopher/, $(PHILO_SRC))
endif
PHILO_OBJ			=	$(PHILO_SRC:.c=.o)
PHILO_OBJ_FULLNAME	=	$(addprefix ./obj/, $(PHILO_OBJ))

CREATE_VARIABLES_DIR			=	$(SRC_DIR)/create_variables
ifdef DO_BONUS
CREATE_VARIABLES_SRC			=	table_variables_bonus.c free_variables_bonus.c ft_atol_bonus.c ft_bzero_bonus.c philo_variables_bonus.c
CREATE_VARIABLES_SRC_FULLNAME	=	$(addprefix ./src/create_variables_bonus/, $(CREATE_VARIABLES_SRC))
else
CREATE_VARIABLES_SRC			=	table_variables.c fork_variables.c free_variables.c ft_atol.c ft_bzero.c philo_variables.c
CREATE_VARIABLES_SRC_FULLNAME	=	$(addprefix ./src/create_variables/, $(CREATE_VARIABLES_SRC))
endif
CREATE_VARIABLES_OBJ			=	$(CREATE_VARIABLES_SRC:.c=.o)
CREATE_VARIABLES_OBJ_FULLNAME	=	$(addprefix ./obj/, $(CREATE_VARIABLES_OBJ))

MONITOR_DIR				=	$(SRC_DIR)/monitor
ifdef DO_BONUS
MONITOR_SRC				=	monitor_bonus.c
else
MONITOR_SRC				=	monitor.c
endif
MONITOR_SRC_FULLNAME	=	$(MONITOR_DIR)/$(MONITOR_SRC)
MONITOR_OBJ				=	$(MONITOR_SRC:.c=.o)
MONITOR_OBJ_FULLNAME	=	$(OBJ_DIR)/$(MONITOR_OBJ)

WAITER_DIR				=	$(SRC_DIR)/waiter
ifdef DO_BONUS
WAITER_SRC				=	waiter_bonus.c
WAITEER_SRC_FULLNAME	=	$(addprefix ./src_bonus/waiter/, $(WAITER_SRC))
else
WAITER_SRC				=	waiter.c
WAITEER_SRC_FULLNAME	=	$(addprefix ./src/waiter/, $(WAITER_SRC))
endif
WAITER_OBJ				=	$(WAITER_SRC:.c=.o)
WAITER_OBJ_FULLNAME		=	$(addprefix ./obj/, $(WAITER_OBJ))

DEBUG_DIR			=	$(SRC_DIR)/debug
ifdef DO_BONUS
DEBUG_SRC			=	debug_bonus.c
else
DEBUG_SRC			=	debug.c
endif
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
	@mkdir -p $(PHILO_NAME_DIR)
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

bonus	:
	make DO_BONUS=yes

clean	:
	rm -rf $(OBJ_LIST)

fclean	:clean
	rm -rf $(NAME)
	rm -rf ./philo_bonus/philo_bonus

re		:fclean
	all

.PHONY	:all bonus clean fclean re
