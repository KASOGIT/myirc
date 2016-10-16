/*
** server.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myftp
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Wed May  4 13:03:19 2016 
** Last update Mon May 30 12:36:25 2016 
*/

#include "server.h"

static void	server_listen(t_server *this);
static void	server_accept(t_server *this, t_handle_client *client);

void	server_set_methods(t_server *this)
{
  this->server_listen = &server_listen;
  this->server_handle_client = &server_handle_client;
  this->server_accept = &server_accept;
  this->exec_cmd_clients = &server_exec_cmd_clients;
  this->get_chan_from_name = &server_get_chan_from_name;
  this->list_all_users_on_chans = &server_list_all_users_on_chans;
  this->get_all_chan_topic = &server_get_all_chan_topic;
  this->get_users = &server_get_users;
  this->get_user_from_name = &server_get_user_from_name;
  this->get_all_users_on_chans = &server_get_all_users_on_chans;
  this->epur_chans = &server_epur_chans;
}

static void	server_listen(t_server *this)
{
  this->_sock->socket_listen(this->_sock);
}

static void	server_accept(t_server *this,
			      t_handle_client *client)
{
  this->_sock->socket_accept(this->_sock, client);
}

int			is_name_match(void *data, void *arg)
{
  t_handle_client	*client;
  char			*name;

  client = (t_handle_client *)data;
  name = (char *)arg;
  if (client->_nickname &&
      strncmp(name, client->_nickname,
	      strlen(client->_nickname)) == 0)
    return (1);
  return (0);
}

void	*server_get_user_from_name(t_server *this, char *name)
{
  return (this->_users->get_elem_by_pred_arg(this->_users,
					     &is_name_match,
					     name));
}
