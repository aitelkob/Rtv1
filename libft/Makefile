# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 06:06:14 by mzaboub           #+#    #+#              #
#    Updated: 2020/12/29 11:08:41 by yait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

BLACK           := $(shell tput -Txterm setaf 0)
RED             := $(shell tput -Txterm setaf 1)
GREEN           := $(shell tput -Txterm setaf 2)
YELLOW          := $(shell tput -Txterm setaf 3)
LIGHTPURPLE     := $(shell tput -Txterm setaf 4)
PURPLE          := $(shell tput -Txterm setaf 5)
BLUE            := $(shell tput -Txterm setaf 6)
WHITE           := $(shell tput -Txterm setaf 7)
RESET           := $(shell tput -Txterm setaf 9)

SRC_PATH= .
SRC_NAME= ft_atoi.c  	ft_bzero.c		ft_charinword.c	ft_isalnum.c	\
		  ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprime.c 	\
		  ft_isprint.c 	ft_itoa.c 		ft_lstadd.c  	ft_lstdel.c		\
		  ft_lstiter.c	ft_lstmap.c		ft_lstnew.c		ft_lstsize.c 	\
		  ft_lstsplit.c	ft_memalloc.c	ft_memccpy.c	ft_memchr.c 	\
		  ft_memcmp.c	ft_memcpy.c		ft_memcpynull.c	ft_memdel.c 	\
		  ft_memmove.c	ft_memset.c		ft_putchar.c	ft_putchar_fd.c \
		  ft_putendl.c	ft_putendl_fd.c	ft_putnbr.c		ft_putnbr_fd.c	\
		  ft_putstr.c	ft_putstr_fd.c	ft_sqrt.c		ft_strcat.c		\
		  ft_strchr.c	ft_strclr.c			ft_strcpy.c		\
		  ft_strdel.c	ft_strdup.c				ft_striter.c	\
		  ft_striteri.c	ft_strjoin.c	ft_strlcat.c	ft_strlen.c		\
		  ft_strmap.c	ft_strmapi.c	ft_strncat.c	 	\
		  ft_strncpy.c		ft_strnew.c		ft_strnstr.c 	\
		  ft_strrchr.c	ft_strrev.c		ft_strsplit.c	ft_strstr.c 	\
		  ft_strsub.c	ft_strtrim.c	ft_tolower.c	ft_toupper.c 	\
		  get_next_line.c	ft_lstdelone.c	ft_atoi_base.c ft_split_whitespaces.c \
		  upper_case.c
SRC= $(addprefix $(SRC_PATH)/, $(SRC_NAME))


OBJ_PATH= obj
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))


CFLAGS=  -Wall -Wextra -Werror
CC= gcc
HDR_FLAGS= -I.


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(PURPLE)*************>>>>libft :   $(LIGHTPURPLE)library compilled$(RESET)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HDR_FLAGS) -o $@ -c $<


clean:
	@rm -fr $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)*************>>>>libft :   files deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)*************>>>>libft :   library deleted"$(RESET)

re: fclean all
	
