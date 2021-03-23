##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my make file
##

NAME	=	csfml

SRCS	= 	./main.c \
			./src/fire.c \
			./src/wind.c \
			./src/bush.c \
			./src/speed.c \
			./src/eagle.c \
			./src/helpme.c \
			./src/display.c \
			./src/destroy.c \
			./src/colision.c \
			./src/obstacle.c \
			./src/parallax.c \
			./src/update_bush.c \
			./src/backgrounds.c \

OBJS	=	$(SRCS:.c=.o)

NBR_OF_FILES := $(words $(SRCS))

CC = gcc

RM	=	rm -f

CFLAGS += -I ./include/
CFLAGS += -W -Wall -Wextra -g3
CFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJS)
		@ echo "\033[1;36m[ FILES COMPILED ] ➢ \033[0m \033[1;36m$(NBR_OF_FILES)\033[0m"
		@ $(CC) -o $(NAME) $(OBJS) $(CFLAGS)
		@ echo "\033[1;34m●  The executable \033[1;39m$(NAME)\033[1;34m has been created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31m● Removing: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJS)

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)

re: 	fclean all

%.o:	%.c
		@ echo "\033[1;34m[ OK √ ]\033[0m Compiling" $<
		@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re
