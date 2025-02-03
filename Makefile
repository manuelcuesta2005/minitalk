SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = cc 
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

LIBFT = ./libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

CLIENT_SRC = client.c 
SERVER_SRC = server.c
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_BONUS_SRC = client_bonus.c
SERVER_BONUS_SRC = server_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRC:.c=.o)

all: $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

$(SERVER): $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF) -o $(CLIENT)

$(SERVER_BONUS): $(SERVER_BONUS_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(LIBFT) $(FT_PRINTF) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT) $(FT_PRINTF) -o $(CLIENT_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re