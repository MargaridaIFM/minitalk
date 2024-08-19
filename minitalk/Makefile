.SILENT:

CLIENT_NAME     =   client

SERVER_NAME     =   server

BONUS_CLIENT    =   client_bonus

BONUS_SERVER    =   server_bonus

CC              =   cc

CFLAGS          =   -Wall -Wextra -Werror -gdwarf-4 #-fsanitize=address

RM              =   rm -rf

INC_DIR         =   includes/

SRC_DIR         =   sources/

OBJ_DIR         =   objs/

CLIENT_DIR      =   client/

SERVER_DIR      =   server/

LIBS_DIR        =   libraries/

LFT_PATH        =   $(addprefix $(LIBS_DIR), libft/)

# Arquivos de origem
CLIENT_SRC      =   $(addprefix $(SRC_DIR)$(CLIENT_DIR), client.c)
SERVER_SRC      =   $(addprefix $(SRC_DIR)$(SERVER_DIR), server.c)
BONUS_CLIENT_SRC =  $(addprefix $(SRC_DIR)$(CLIENT_DIR), client_bonus.c)
BONUS_SERVER_SRC =  $(addprefix $(SRC_DIR)$(SERVER_DIR), server_bonus.c)

# Arquivos de objeto
CLIENT_OBJ      =   $(CLIENT_SRC:$(SRC_DIR)$(CLIENT_DIR)%.c=$(OBJ_DIR)$(CLIENT_DIR)%.o)
SERVER_OBJ      =   $(SERVER_SRC:$(SRC_DIR)$(SERVER_DIR)%.c=$(OBJ_DIR)$(SERVER_DIR)%.o)
BONUS_CLIENT_OBJ =  $(BONUS_CLIENT_SRC:$(SRC_DIR)$(CLIENT_DIR)%.c=$(OBJ_DIR)$(CLIENT_DIR)%.o)
BONUS_SERVER_OBJ =  $(BONUS_SERVER_SRC:$(SRC_DIR)$(SERVER_DIR)%.c=$(OBJ_DIR)$(SERVER_DIR)%.o)

OBJ_DIRS        =   $(OBJ_DIR) $(addprefix $(OBJ_DIR), $(CLIENT_DIR))

all:                $(LFT_PATH)libft.a $(SERVER_NAME) $(CLIENT_NAME)

# Compilação dos binários principais
$(CLIENT_NAME):  $(CLIENT_OBJ) 
					printf 'Compiling $(CLIENT_NAME)\n'
					$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $@ -I $(INC_DIR) -L$(LFT_PATH) -lft

$(SERVER_NAME):  $(SERVER_SRC)
					printf 'Compiling $(SERVER_NAME)\n'
					$(CC) $(CFLAGS) $(SERVER_SRC) -o $@ -I $(INC_DIR) -L$(LFT_PATH) -lft

bonus:              $(BONUS_CLIENT) $(BONUS_SERVER)
# Compilação dos binários de bônus
$(BONUS_CLIENT): $(BONUS_CLIENT_OBJ) | $(OBJ_DIRS)
					printf 'Compiling $(BONUS_CLIENT)\n'
					$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJ) -o $@ -I $(INC_DIR) -L$(LFT_PATH) -lft

$(BONUS_SERVER): $(BONUS_SERVER_OBJ) | $(OBJ_DIRS)
					printf 'Compiling $(BONUS_SERVER)\n'
					$(CC) $(CFLAGS) $(BONUS_SERVER_OBJ) -o $@ -I $(INC_DIR) -L$(LFT_PATH) -lft

# Compilação dos objetos
$(OBJ_DIR)$(CLIENT_DIR)%.o: $(SRC_DIR)$(CLIENT_DIR)%.c | $(OBJ_DIRS)
					printf "Compiling $(CLIENT_NAME) objects... %-33.33s\r" $(notdir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

# $(OBJ_DIR)$(SERVER_DIR)%.o: $(SERVER_SRC) $(OBJ_DIRS)
# 	printf "Compiling $(SERVER_NAME) objects... %-33.33s\r" $(notdir $@)
# 	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

# Criação dos diretórios de objetos
$(OBJ_DIRS):
					mkdir -p $@

# Regras padrão

$(LFT_PATH)libft.a:
					make -s -C $(LFT_PATH)

clean:
					if [ -d $(OBJ_DIR) ]; then $(RM) $(OBJ_DIR); fi

fclean:             clean
					$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(BONUS_CLIENT) $(BONUS_SERVER)
					make fclean -C $(LFT_PATH)

re:                 fclean all


.PHONY:             all clean fclean re bonus
