/*
** server.h for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myftp/include
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue May  3 13:32:11 2016 
** Last update Fri Jun  3 17:28:09 2016 
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include "handle_client.h"
#include "list.h"
#include "channel.h"
#include "socket.h"

#define DEBUG	0

typedef struct s_socket t_socket;
typedef struct s_handle_client t_handle_client;

typedef struct	s_server
{
  t_socket	*_sock;
  t_list	*_users;
  t_list	*_chans;
  fd_set	_set;
  void		(*server_listen)(struct s_server *this);
  void		(*server_handle_client)(struct s_server *this);
  void		(*server_accept)(struct s_server *this,
				 t_handle_client *client);
  void		(*exec_cmd_clients)(struct s_server *this);
  void		*(*get_chan_from_name)(struct s_server *this, char *name_chan);
  void		(*list_all_users_on_chans)(struct s_server *this,
					   t_handle_client *client);
  char		*(*get_all_chan_topic)(struct s_server *this);
  char		*(*get_users)(struct s_server *this);
  void		*(*get_user_from_name)(struct s_server *this, char *name);
  char		*(*get_all_users_on_chans)(struct s_server *this);
  void		(*epur_chans)(struct s_server *this);
}		t_server;

void	server_handle_client(t_server *this);
void	server_error(t_server *this, const char *err_msg);
void	server_init(t_server *this, int port);
void	server_set_methods(t_server *this);
void	server_destroy(t_server *this);
void	server_exec_cmd_clients(t_server *this);
void	*server_get_chan_from_name(t_server *this, char *name_chan);
void	server_list_all_users_on_chans(t_server *this,
				       t_handle_client *client);
char	*server_get_all_chan_topic(t_server *this);
char	*server_get_users(t_server *this);
void	*server_get_user_from_name(t_server *this, char *name);
void	*comp_fd_client(void *c1, void *c2);
char	*server_get_all_users_on_chans(t_server *this);
void	server_epur_chans(t_server *this);

#endif /* !SERVER_H_ */
