CC					=	gcc
COMPILE_FLAGS		=	-Wall -Wextra -Werror $(INCLUDE_FLAGS) $(DEBUG_FLAGS)
INCLUDE_FLAGS		=	-I $(INCLUCDE_DIR)
DEBUG_FLAGS			=	-g

MAIN_SRC			=	main.c
MAIN_SRC_FULLNAME	=	$(addprefix ./src/main/, $(MAIN_SRC))
MAIN_OBJ			=	$(MAIN_SRC:.c=.o)
MAIN_OBJ_FULLNAME	=	$(addprefix ./obj/, $(MAIN_OBJ))

MAIN_SRC_BONUS			=	main_bonus.c
MAIN_SRC_FULLNAME_BONUS	=	$(addprefix ./src_bonus/main/, $(MAIN_SRC_BONUS))
MAIN_OBJ_BONUS			=	$(MAIN_SRC_BONUS:.c=.o)
MAIN_OBJ_FULLNAME_BONUS	=	$(addprefix ./obj_bonus/, $(MAIN_OBJ_BONUS))

PHILO_SRC			=	philo_behavior.c philo_fork.c philo_pthread.c
PHILO_SRC_FULLNAME	=	$(addprefix ./src/philosopher/, $(PHILO_SRC))
PHILO_OBJ			=	$(PHILO_SRC:.c=.o)
PHILO_OBJ_FULLNAME	=	$(addprefix ./obj/, $(PHILO_OBJ))

PHILO_SRC_BONUS				=	philo_behavior_bonus.c philo_fork_bonus.c philo_create_process_bonus.c
PHILO_SRC_FULLNAME_BONUS	=	$(addprefix ./src_bonus/philosopher/, $(PHILO_SRC_BONUS))
PHILO_OBJ_BONUS				=	$(PHILO_SRC_BONUS:.c=.o)
PHILO_OBJ_FULLNAME_BONUS	=	$(addprefix ./obj_bonus/, $(PHILO_OBJ_BONUS))

CREATE_VARIABLES_SRC				=	table_variables.c fork_variables.c free_variables.c ft_atol.c ft_bzero.c philo_variables.c
CREATE_VARIABLES_SRC_FULLNAME		=	$(addprefix ./src/create_variables/, $(CREATE_VARIABLES_SRC))
CREATE_VARIABLES_OBJ				=	$(CREATE_VARIABLES_SRC:.c=.o)
CREATE_VARIABLES_OBJ_FULLNAME		=	$(addprefix ./obj/, $(CREATE_VARIABLES_OBJ))

CREATE_VARIABLES_SRC_BONUS			=	table_variables_bonus.c free_variables_bonus.c ft_atol_bonus.c ft_bzero_bonus.c philo_variables_bonus.c
CREATE_VARIABLES_SRC_FULLNAME_BONUS	=	$(addprefix ./src/create_variables_bonus/, $(CREATE_VARIABLES_SRC_BONUS))
CREATE_VARIABLES_OBJ_BONUS			=	$(CREATE_VARIABLES_SRC_BONUS:.c=.o)
CREATE_VARIABLES_OBJ_FULLNAME_BONUS	=	$(addprefix ./obj_bonus/, $(CREATE_VARIABLES_OBJ_BONUS))

MONITOR_SRC				=	monitor.c
MONITOR_SRC_FULLNAME	=	$(addprefix ./src/monitor/, $(MONITOR_SRC))
MONITOR_OBJ				=	$(MONITOR_SRC:.c=.o)
MONITOR_OBJ_FULLNAME	=	$(addprefix ./obj/, $(MONITOR_OBJ))

MONITOR_SRC_BONUS			=	monitor_bonus.c
MONITOR_SRC_FULLNAME_BONUS	=	$(addprefix ./src_bonus/monitor/, $(MONITOR_SRC))
MONITOR_OBJ_BONUS			=	$(MONITOR_SRC_BONUS:.c=.o)
MONITOR_OBJ_FULLNAME_BONUS	=	$(addprefix ./obj_bonus/, $(MONITOR_OBJ_BONUS))

WAITER_DIR				=	./src/waiter
WAITER_SRC				=	waiter.c
WAITEER_SRC_FULLNAME	=	$(addprefix ./src/waiter/, $(WAITER_SRC))
WAITER_OBJ				=	$(WAITER_SRC:.c=.o)
WAITER_OBJ_FULLNAME		=	$(addprefix ./obj/, $(WAITER_OBJ))

DEBUG_DIR			=	./src/debug
DEBUG_SRC			=	debug.c
DEBUG_SRC_FULLNAME	=	$(addprefix ./src/debug/, $(DEBUG_SRC))
DEBUG_OBJ			=	$(DEBUG_SRC:.c=.o)
DEBUG_OBJ_FULLNAME	=	$(addprefix ./obj/, $(DEBUG_OBJ))

OBJ_LIST_MAN		=	$(MAIN_OBJ_FULLNAME) \
						$(CREATE_VARIABLES_OBJ_FULLNAME) \
						$(PHILO_OBJ_FULLNAME) \
						$(FORK_OBJ_FULLNAME) \
						$(MONITOR_OBJ_FULLNAME) \
						$(WAITER_OBJ_FULLNAME) \
						$(DEBUG_OBJ_FULLNAME)
OBJ_LIST_BONUS		=	$(MAIN_OBJ_FULLNAME_BONUS) \
						$(CREATE_VARIABLES_OBJ_FULLNAME_BONUS) \
						$(PHILO_OBJ_FULLNAME_BONUS) \
						$(FORK_OBJ_FULLNAME_BONUS) \
						$(MONITOR_OBJ_FULLNAME_BONUS) \

ifdef DO_BONUS
NAME					=	$(PHILO_NAME_DIR)/philo_bonus
PHILO_NAME_DIR			=	./philo_bonus
MAIN_DIR				=	./src_bonus/main
CREATE_VARIABLES_DIR 	=	./src_bonus/create_variables
PHILO_DIR 				=	./src_bonus/philosopher
MONITOR_DIR 			=	./src_bonus/monitor
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
INCLUCDE_DIR			=	./include
OBJ_DIR					=	./obj
OBJ_LIST 				= $(OBJ_LIST_MAN)
endif

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
	rm -rf $(OBJ_LIST_MAN)
	rm -rf $(OBJ_LIST_BONUS)

fclean	:clean
	rm -rf ./philo/philo
	rm -rf ./philo_bonus/philo_bonus

re		:fclean
	all

.PHONY	:all bonus clean fclean re
