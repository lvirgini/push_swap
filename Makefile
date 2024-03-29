# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 16:30:55 by lvirgini          #+#    #+#              #
#    Updated: 2021/07/05 15:30:44 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# -----------------------------------------------------------------------------#

NAME_PUSH_SWAP 	=	push_swap
NAME_CHECKER 	=	checker

LIB_DIR =	libft/
SRC_DIR =	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d) libft/includes
OBJ_DIR =	obj/

LIB		=	ft

SRC_COMMON = init_s_stack.c 	\
			init_lst.c 			\
			lst_utils.c			\
			utils.c				\
			error.c 			\
			get_data.c			\
			rotate.c 			\
			reverse_rotate.c 	\
			push.c 				\
			swap.c 				\
			check_order.c				

SRC_PU	=	$(SRC_COMMON) main_push_swap.c	\
			print_instruction.c \
			dispatch_algo.c		\
			two_datas.c			\
			three_datas.c		\
			tri_test.c			\
			insertion_sort.c	\
			lst_find_closest.c	\
			lst_find_min_max.c	\
			test_instructions.c	\
			rotate_min_instruction.c \
			push_in_order.c		\
			t_opti.c			\
			t_opti_insertion_sort.c 
			
SRC_CH	= $(SRC_COMMON) main_checker.c		\
			get_instruction.c	


OBJ_PU 	=	$(addprefix $(OBJ_DIR),$(SRC_PU:%.c=%.o))
OBJ_CH 	=	$(addprefix $(OBJ_DIR),$(SRC_CH:%.c=%.o))

HEADERS = 	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))

vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)


# ----------------- #
#	 COMPILATION	#
# -----------------------------------------------------------------------------#

CC 		=	gcc

CFLAG 	= 	-Wall -Wextra -Werror -g -fsanitize=leak -fsanitize=address 

IFLAG 	= 	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG 	=	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) )


# ----------------- #
#	  FONCTIONS		#
# -----------------------------------------------------------------------------#

all:		install $(NAME_PUSH_SWAP) $(NAME_CHECKER)


$(OBJ_DIR)%.o: %.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation de ... $(foreach file, $< , $(notdir $<))\033[0m"
			@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $< 
			
$(NAME_CHECKER) : $(OBJ_CH)
			$(CC) $(CFLAG) $(IFLAG) $(OBJ_CH) -o $@ $(LFLAG)

	
$(NAME_PUSH_SWAP) : $(OBJ_PU)
			$(CC) $(CFLAG) $(IFLAG) $(OBJ_PU) -o $@ $(LFLAG)


install :
			@make -C $(LIB_DIR)

re-install :
			@make -C $(LIB_DIR) re
				
bonus :  all

show	:
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "LIB_DIR : $(LIB_DIR)\n"
			@echo "INC_DIR : $(INC_DIR)\n"
			@echo "CFLAG : $(CFLAG)\n"
			@echo "IFLAG : $(IFLAG)\n"
			@echo "LFLAG : $(LFLAG)\n"
			@echo "HEADERS : $(foreach file, $(HEADERS),\n\t$(file))\n"
			@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
			@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"


# ----------------- #
# 		CLEAN		#
# -----------------------------------------------------------------------------#

clean:
			rm -rf $(OBJ_DIR)

fclean: clean
			rm -f $(NAME_CHECKER)
			rm -f $(NAME_PUSH_SWAP)

re: 	fclean all

.PHONY: all clean flcean re
