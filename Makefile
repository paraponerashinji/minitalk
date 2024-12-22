NAME= client
CC= cc
CFLAGS = -Wall -Wextra -Werror
SRCS= client.c
OBJS= $(SRCS:.c=.o)
LIBS= libft.a libftprintf.a
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
server:
	$(CC) $(CFLAGS) -c server.c -o server.o
	$(CC) $(CFLAGS) -o server server.o $(LIBS)
sclean:
	rm -f server.o
	rm -f server
all: $(NAME)
re: fclean all
.PHONY: clean fclean all re
