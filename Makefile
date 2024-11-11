# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 16:43:58 by jfremond          #+#    #+#              #
#    Updated: 2024/09/01 22:36:29 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
#   LIBRARY   #
###############

NAME		=	libasm.a

##################
#   EXECUTABLE   #
##################

EXEC		=	prog

################
#   COMMANDS   #
################

ASM			=	nasm
LINK		=	ar -rcs
CC			=	clang
MKDIR		=	/bin/mkdir -p
RM			=	/bin/rm -rf

#########
# FLAGS #
#########

CFLAGS		=	-c -Wall -Wextra -Werror -g3 -I. -MMD
ASMFLAGS	=	-f elf64 -g -gdwarf

###################
#   DIRECTORIES   #
###################

OBJS_D	=	objs/

###############
#   SOURCES   #
###############

A_SRCS		=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_strcmp.s	\
				ft_write.s	\
				ft_read.s	\
				ft_strdup.s

C_SRCS		=	main.c		\
				utils.c

###############
#   OBJECTS   #
###############

A_OBJS	=	$(A_SRCS:.s=.o)
A_OBJS	:=	$(addprefix $(OBJS_D), $(A_OBJS))

C_OBJS	=	$(C_SRCS:.c=.o)
C_OBJS	:=	$(addprefix $(OBJS_D), $(C_OBJS))

####################
#   DEPENDENCIES   #
####################

DEP = $(C_OBJS:.o=.d)

#############
#   RULES   #
#############

all:			$(NAME) $(EXEC)

$(NAME):		$(A_OBJS)
				$(LINK) $(NAME) $(A_OBJS)

-include		$(DEP)

$(OBJS_D)%.o:	%.s
				$(MKDIR) $(@D)
				$(ASM) $(ASMFLAGS) $(OUTPUT_OPTION) $<

$(OBJS_D)%.o:	%.c
				$(MKDIR) $(@D)
				$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

$(EXEC):		$(C_OBJS)
				$(CC) $(C_OBJS) -L. -lasm -o $(EXEC)

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME) $(EXEC) *.txt

re:				fclean all

.PHONY:			all clean fclean re
