##
## Makefile for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
## 
## Made by adam soto
## Login   <soto_a@epitech.net>
## 
## Started on  Wed Mar  2 12:54:44 2016 
## Last update Sun Oct 16 23:06:11 2016 
##

SERVER	= server

CLIENT	= client

CFLAGS	= -I./include -I./include/client -I./include/server -I./src/list/ -O2 -pipe
#LDFLAGS	= 

CC	= gcc

SRC_UTILS	= utils.c \
		  utils2.c \

SRC_LIST	= elem.c \
		  elem_getters.c \
		  list.c \
		  list_adding.c \
		  list_get.c \
		  list_iter.c \
		  list_loop.c \
		  list_misc.c \
		  list_rm.c \
		  list_rm2.c \
		  list_utils.c \

SRC_SOCKET	= socket.c \
		  socket_manage.c \

SRC_SERVER	= main.c \
		  handle_client.c \
		  handle_client_manage.c \
		  handle_client_utils.c \
		  server.c \
		  server_manage.c \
		  server_handle_client.c \
		  server_func1.c \
		  server_func2.c \
		  server_exec.c \
		  channel.c \
		  channel2.c \
		  circular_buffer.c \
		  circular_buffer_io.c \
		  commands.c \
		  commands_join.c \
		  commands_join_utils.c \
		  commands_list.c \
		  commands_auth.c \
		  commands_part.c \
		  commands_privmsg.c \
		  commands_topic.c \
		  commands_leave_chan.c \

SRC_CLIENT	= main.c \

OBJ_UTILS	= $(addprefix src/utils/, $(SRC_UTILS:.c=.o))

OBJ_LIST	= $(addprefix src/list/, $(SRC_LIST:.c=.o))

OBJ_SOCKET	= $(addprefix src/socket/, $(SRC_SOCKET:.c=.o))

OBJ_SERVER	= $(addprefix src/server/, $(SRC_SERVER:.c=.o))

OBJ_CLIENT	= $(addprefix src/client/, $(SRC_CLIENT:.c=.o))

all:		$(CLIENT) $(SERVER)

$(SERVER):	$(OBJ_SERVER) $(OBJ_SOCKET) $(OBJ_LIST) $(OBJ_UTILS)
		$(CC) $(OBJ_SERVER) $(OBJ_SOCKET) $(OBJ_LIST) $(OBJ_UTILS) $(LDFLAGS) -o $(SERVER)

$(CLIENT):	$(OBJ_CLIENT) $(OBJ_SOCKET)
		$(CC) $(OBJ_CLIENT) $(OBJ_SOCKET) $(LDFLAGS) -o $(CLIENT)
clean:
	rm -rf $(OBJ_CLIENT)
	rm -rf $(OBJ_SERVER)
	rm -rf $(OBJ_LIST)
	rm -rf $(OBJ_SOCKET)
	rm -rf $(OBJ_UTILS)

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re: fclean all
