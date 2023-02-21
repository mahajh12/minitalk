SERVER = server.c minitalk_utils.c
CLIENT = client.c minitalk_utils.c

SERVER_B = server_bonus.c minitalk_utils_bonus.c
CLIENT_B = client_bonus.c minitalk_utils_bonus.c

OBJS = $(SERVER:.c=.o)
OBJC = $(CLIENT:.c=.o)
OBJSB = $(SERVER_B:.c=.o)
OBJCB = $(CLIENT_B:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: server client

server: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o server

client: $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o client

bonus: $(OBJSB) $(OBJCB)
	$(CC) $(CFLAGS) $(OBJSB) -o server
	$(CC) $(CFLAGS) $(OBJCB) -o client

clean:
	$(RM) $(OBJS) $(OBJC) $(OBJSB) $(OBJCB)

fclean: clean
	$(RM) server client bonus

re: fclean all