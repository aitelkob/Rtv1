# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 16:25:47 by yait-el-          #+#    #+#              #
#    Updated: 2021/01/23 19:06:17 by yait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################### Make Makefile  beautiful
BLACK           := $(shell tput -Txterm setaf 0)
RED             := $(shell tput -Txterm setaf 1)
GREEN           := $(shell tput -Txterm setaf 2)
YELLOW          := $(shell tput -Txterm setaf 3)
LIGHTPURPLE     := $(shell tput -Txterm setaf 4)
PURPLE          := $(shell tput -Txterm setaf 5)
BLUE            := $(shell tput -Txterm setaf 6)
WHITE           := $(shell tput -Txterm setaf 7)
RESET           := $(shell tput -Txterm setaf 9)
####################### Project Name

NAME = RTv1

######################Executable / Libraries

MLX  = libmlx.a
FT   = libft.a

######################DIR

LFTDIR		= libft
SRCSDIR		= src
OBJSDIR		= objs
INCSDIR		:= inc
INCSDIR		+= $(LFTDIR)
MLXDIR		= mlx
####################INC

INCS		:= inc/Rtv1.h
INCS		+= libft/libft.h
INCS		+= mlx/mlx.h

########################SRC files

SRC			:=main.c

#################### Libraries
LIBS		:= -lmlx
LIBS		+= -framework OpenGL
LIBS		+= -framework AppKit
LIBS		+= -lz

################### 3ya9a li makine lache but i do it fuck it

MLXX		= $(MLXDIR)/$(MLX)
D_SRCS      = $(addsuffix /, $(SRCSDIR))
D_OBJS      = $(addsuffix /, $(OBJSDIR))
C_OBJS      = $(addprefix $(D_OBJS),  $(SRC:.c=.o))
C_INCS      = $(foreach include, $(INCSDIR), -I$(include))

################# Compilation flags
CC              = gcc
RM              = rm -rf
CFLAGS          = $(C_INCS) -Wall -Wextra -Werror

#----------------->>>>>>>>>>>>>>>>START<<<<<<<<<<<<<-------------------#
$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(PURPLE)**********>>>Compiling : $(RESET) $(LIGHTPURPLE)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

all:$(OBJSDIR) $(C_OBJS) $(NAME)

########## for D-bug
print-%  : ; @echo $* = $($*)
############################

$(NAME): $(MLXX) $(C_OBJS)
	@echo "$(RED)\n***********>>>Building : $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)

#########  make libft
$(LFT):
	@make -sC $(LFTDIR)
######## create obj dir
$(OBJSDIR):
	@mkdir -p $(OBJSDIR)
####### make mlix
$(MLXX):
	make -sC $(MLXDIR)
clean:
	@make -sC $(LFTDIR) clean
	@echo "$(GREEN)**********   Deleting all object from $(NAME) **********\n$(RESET)"
	@$(RM) $(C_OBJS)

fclean: clean
	@make -sC $(LFTDIR) fclean
	@echo "$(GREEN)**********   Deleting $(NAME) **********\n$(RESET)"
	@$(RM) $(NAME)
	@$(RM) $(OBJSDIR)
