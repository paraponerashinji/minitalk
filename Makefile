CC= cc
CFLAGS = -Wall -Wextra -Werror
SRCS= client.c server.c server_utilities.c
OBJS= $(SRCS:.c=.o)
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(OBJS) $(LIBFT) server client
client:
	$(CC) $(CFLAGS) -c client.c -o client.o
	$(CC) $(CFLAGS) -o client client.o $(LIBFT)
server:
	$(CC) $(CFLAGS) -c server.c -o server.o
	$(CC) $(CFLAGS) -c server_utilities.c -o server_utilities.o
	$(CC) $(CFLAGS) -o server server.o server_utilities.o $(LIBFT)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
	make -C $(LIBFTDIR)
serverclean:
	rm -f server.o server
clientclean:
	rm -f client.o client
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
fclean: clean 
	rm -f client server
	make fclean -C $(LIBFTDIR)
all: $(NAME)
re: fclean all
.PHONY: clean fclean all re
