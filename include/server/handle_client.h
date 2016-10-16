/*
** handle_client.h for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myftp
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Wed May  4 14:43:11 2016 
** Last update Fri Jun  3 17:27:53 2016 
*/

#ifndef HANDLE_CLIENT_H_
#define HANDLE_CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "server.h"
#include "socket.h"
#include "commands.h"
#include "utils.h"
#include "circular_buffer.h"

#define DEBUG	0

typedef struct s_server	t_server;

typedef struct		s_handle_client
{
  struct sockaddr_in	_s_in;
  int			_fd;
  char			*_ip;
  char			*_nickname;
  char			*_username;
  char			*_realname;
  t_circular_buffer	_buffer;
  char			*_cmd;
  char			**_args;
  char			**_args_chan;
  int			_registered;
  char			*_recipient;
  char			*_msg;
  void	(*read_cmd)(struct s_handle_client *this);
  void	(*send_msg)(struct s_handle_client *this,
				  const char *msg);
  void	(*fill_buff)(struct s_handle_client *this, t_server *server);
  void	(*routine_cmd)(struct s_handle_client *this, t_server *server);
  void	(*send_err)(struct s_handle_client *this, int c_err,
		    const char *msg, int end);
  void	(*send_rpl)(struct s_handle_client *this, int c_rpl,
		    const char *msg, int end);
}			t_handle_client;

void	handle_client_init(t_handle_client *this);
t_handle_client	*handle_client_copy(t_handle_client *this);
void	handle_client_error(t_handle_client *this,
			    const char *err_msg);
void	handle_client_set_methods(t_handle_client *this);
void	handle_client_destroy(t_handle_client *this);
void	handle_client_send_msg(t_handle_client *this,
			       const char *msg);
void	handle_client_send_err(t_handle_client *this, int c_err,
			       const char *msg, int end);
void	handle_client_send_rpl(t_handle_client *this, int c_rpl,
			       const char *msg, int end);
void	handle_client_read_cmd(t_handle_client *this);
void	handle_client_fill_buff(t_handle_client *this, t_server *server);
void	handle_client_routine_cmd(t_handle_client *this, t_server *server);

#endif /* !HANDLE_CLIENT_H_ */
