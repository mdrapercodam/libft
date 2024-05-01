# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mdraper <mdraper@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/13 14:57:29 by mdraper       #+#    #+#                  #
#    Updated: 2024/05/01 16:15:21 by mdraper       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

# **************************************|************************************** #
#								   INGREDIENTS									#
# **************************************|************************************** #

INCS		:= inc

SRC_DIR		:= src
OBJ_DIR		:= obj

SRCS		:= $(shell find $(SRC_DIR) -iname "*.c")
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I $(INCS)
AR			:= ar
ARFLAGS		:= -r -c -s

# **************************************|************************************** #
#									 UTENSILS									#
# **************************************|************************************** #

RM			:= rm -f
RM_DIR		:= rm -rf
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

# **************************************|************************************** #
#									 RECIPES									#
# **************************************|************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM_DIR) $(OBJ_DIR)
	$(info REMOVED OBJ $(NAME))

fclean:
	$(RM) $(NAME)
	$(info REMOVED $(NAME))

re:
	$(MAKE) fclean
	$(MAKE) all

# **************************************|************************************** #
#									  SPEC										#
# **************************************|************************************** #

.PHONY: clean fclean re git
.SILENT:
