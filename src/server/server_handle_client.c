/*
** server_handle_client.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 00:38:26 2016 
** Last update Sun May 29 21:29:57 2016 
*/

#include "server.h"

static int	       	is_same_fd(void *data, void *arg)
{
  int			fd;
  t_handle_client	*client;

  client = (t_handle_client *)data;
  fd = *((int *)arg);
  if (fd == client->_fd)
    return (1);
  return (0);
}

static void		fd_set_all(t_server *this)
{
  t_elem		*tmp;

  FD_ZERO(&this->_set);
  FD_SET(this->_sock->_fd, &this->_set);
  if (!this->_users->empty(this->_users))
    {
      tmp = this->_users->begin(this->_users);
      while (tmp != this->_users->end(this->_users))
	{
	  FD_SET(((t_handle_client *)tmp->_data)->_fd, &this->_set);
	  tmp = tmp->_next;
	}
      FD_SET(((t_handle_client *)tmp->_data)->_fd, &this->_set);
    }
}

static void		server_routine(t_server *this, int i)
{
  void			*get_elem;
  t_handle_client	*client;

  if (FD_ISSET(i, &this->_set))
    {
      get_elem = this->_users->get_elem_by_pred_arg(this->_users,
						    &is_same_fd, &i);
      if (get_elem == NULL)
	{
	  client = malloc(sizeof(t_handle_client));
	  handle_client_init(client);
	  this->server_accept(this, client);
	  this->_users->push_back(this->_users, client);
	}
      else
	((t_handle_client *)get_elem)->fill_buff((t_handle_client *)get_elem,
						 this);
    }
}

void		server_handle_client(t_server *this)
{
  void		*max_elem;
  int		max_fd;
  int		i;

  this->server_listen(this);
  while (1)
    {
      fd_set_all(this);
      if ((max_elem = this->_users->max(this->_users,
					&comp_fd_client)) == NULL)
	max_fd = this->_sock->_fd;
      else
	max_fd = ((t_handle_client *)max_elem)->_fd;
      if (select(max_fd + 1, &this->_set, NULL, NULL, NULL) < 0)
	perror("select");
      else
	{
	  i = this->_sock->_fd;
	  while (i < FD_SETSIZE)
	    server_routine(this, i++);
	  this->exec_cmd_clients(this);
	}
    }
}
