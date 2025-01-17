CC= cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS= client.c server.c
OBJS= $(SRCS:.c=.o)
LIBS= libftprintf.a
all: server client
client:
	$(CC) $(CFLAGS) -c client.c -o client.o
	$(CC) $(CFLAGS) -o client client.o $(LIBS)
server:
	$(CC) $(CFLAGS) -c server.c -o server.o
	$(CC) $(CFLAGS) -o server server.o $(LIBS)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
serverclean:
	rm -f server.o server
clientclean:
	rm -f client.o client
clean:
	rm -f $(OBJS)
fclean: clean 
	rm -f client server
all: $(NAME)
re: fclean all
.PHONY: clean fclean all re
