##
## EPITECH PROJECT, 2018
## Defender
## File description:
## Makefile
##

NAME	=		navy
CC		=		gcc
RM 		=		rm
SRCDIR	=		src
SRCEXT	=		c

SRC 	:=	$(shell find $(SRCDIR) -name "*.$(SRCEXT)")
OBJ		:= 	$(patsubst %.$(SRCEXT),%.o,$(SRC))

INCLUDE =	-I./include
CFLAGS	=	-Wall -Wextra $(INCLUDE) -lm -g

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -C ./lib/my
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L./lib/my -lmy

clean:
	$(MAKE) -C ./lib/my clean
	$(RM) -f $(OBJ)

debug: CFLAGS += -g
debug: re

fclean: clean
	$(MAKE) -C ./lib/my fclean
	$(RM) -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re debug
