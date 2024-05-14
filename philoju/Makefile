NAME		= philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -02 #-fsanitize=thread

SRCS		= main.c \
					parse.c \


OBJS		= $(SRCS:.c=.o)

/* BUILD */

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -f $(NAME)