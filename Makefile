# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 16:25:47 by yait-el-          #+#    #+#              #
#    Updated: 2021/01/31 17:47:00 by yait-el-         ###   ########.fr        #
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

LFTDIR		= library/Libft
SRCSDIR		= src
OBJSDIR		= obj
INCSDIR		:= inc
INCSDIR		+= $(LFTDIR)
MLXDIR		= library/mlx
CHILDDIR    := start
CHILDDIR    += parse
CHILDDIR    += mlx
CHILDDIR    += libvect
CHILDDIR    += raytracing
####################INC

INCS		:= inc/Rtv1.h
INCS		+= inc/Global.h
INCS		+= inc/fuction.c
INCS		+= inc/sdl_rt.h
INCS		+= inc/struct.h
INCS		+= library/Libft/include/libft.h
INCS		+= library/mlx/mlx.h

########################SRC files

SRC			:=start/main.c
SRC			+=mlx/mlx_stuff.c
SRC			+=parse/parse2.c
SRC			+=parse/objs_parse.c
SRC			+=libvect/calc_vect.c

#################### Libraries
LIBS		:= -L$(MLXDIR) -lmlx
LIBS		+= -framework OpenGL
LIBS		+= -framework AppKit
LIBS		+= -lz
LIBS		+= -L$(LFTDIR) -lft

################### 3ya9a li makine lache Oops!... I Did It Again
LFT         = $(LFTDIR)/$(FT)
MLXX		= $(MLXDIR)/$(MLX)
D_SRCS      = $(addsuffix /, $(SRCSDIR))
D_OBJS      = $(addsuffix /, $(OBJSDIR))
C_OBJS      = $(addprefix $(D_OBJS),  $(SRC:.c=.o))
C_INCS      = $(foreach include, $(INCSDIR), -I$(include))
C_CHILDDIR       = $(foreach dir, $(CHILDDIR),$(D_OBJS)$(dir))
################# Compilation flags
CC              = gcc
RM              = rm -rf
CFLAGS          = $(C_INCS) 

#----------------->>>>>>>>>>>>>>>>START<<<<<<<<<<<<<-------------------#
$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(PURPLE)**********>>>Compiling : $(RESET) $(LIGHTPURPLE)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

all:$(OBJSDIR) $(C_CHILDDIR) $(NAME)

########## for D-bug
print-%  : ; @echo $* = $($*)
############################

$(NAME):$(LFT) $(MLXX) $(C_OBJS)
	@echo "$(RED)\n***********>>>Building : $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)

#########  make libft
$(LFT):
	@make -sC $(LFTDIR)
######## create obj dir
$(OBJSDIR):
	@mkdir -p $(OBJSDIR)
####### create sub folder
$(C_CHILDDIR):
	@mkdir -p $(C_CHILDDIR)
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

re: fclean all
.PHONY: all clean fclean re
