/*
** server_manage.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myftp
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 15 10:41:54 2016 
** Last update Fri Jun  3 17:40:43 2016 
*/

#include "server.h"

void	server_error(t_server *this, const char *err_msg)
{
  if (DEBUG)
    {
      fprintf(stderr, "[%d] Server error on func: %s\n",
	      (int)getpid(),
	      err_msg);
    }
  server_destroy(this);
  exit(EXIT_FAILURE);
}

void	server_destroy(t_server *this)
{
  if (this->_sock != NULL)
    {
      socket_destroy(this->_sock);
      free(this->_sock);
    }
  list_destroy(this->_users);
  list_destroy(this->_chans);
}

void	server_init(t_server *this, int port)
{
  server_set_methods(this);
  if ((this->_sock = malloc(sizeof(t_socket))) == NULL)
    server_error(this, "malloc");
  socket_init(this->_sock, port, NULL);
  this->_users = list_create();
  this->_chans = list_create();
}
