/*
** server_exec.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 00:29:49 2016 
** Last update Sun May 29 01:08:50 2016 
*/

#include "server.h"

void	*comp_fd_client(void *c1, void *c2)
{
  return (((t_handle_client *)c1)->_fd > ((t_handle_client *)c2)->_fd ?
	  c1 : c2);
}

static void		exec_cmd_client(void *arg1, void *arg2)
{
  t_handle_client	*client;
  t_server		*server;

  client = (t_handle_client *)arg1;
  server = (t_server *)arg2;
  client->read_cmd(client);
  while (client->_cmd != NULL)
    {
      client->routine_cmd(client, server);
      client->read_cmd(client);
    }
}

void	server_exec_cmd_clients(t_server *this)
{
  this->_users->for_each_arg(this->_users, &exec_cmd_client, this);
}
