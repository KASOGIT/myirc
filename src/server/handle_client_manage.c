/*
** handle_client_manage.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myftp
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 15 10:48:51 2016 
** Last update Fri Jun  3 17:41:19 2016 
*/

#include "handle_client.h"

void	handle_client_error(t_handle_client *this,
			    const char *err_msg)
{
  if (DEBUG)
    {
      fprintf(stderr,
	      "[%d] Handle client error on func: %s\n",
	      (int)getpid(), err_msg);
    }
  handle_client_destroy(this);
  exit(EXIT_FAILURE);
}

void	handle_client_init(t_handle_client *this)
{
  handle_client_set_methods(this);
  this->_fd = -1;
  this->_registered = 0;
  this->_cmd = NULL;
  this->_args = NULL;
  this->_args_chan = NULL;
  this->_nickname = NULL;
  this->_username = NULL;
  this->_realname = NULL;
  circular_buffer_init(&this->_buffer);
}

t_handle_client		*handle_client_copy(t_handle_client *this)
{
  t_handle_client	*cpy;

  handle_client_set_methods(this);
  cpy = malloc(sizeof(t_handle_client));
  cpy->_fd = this->_fd;
  cpy->_registered = this->_registered;
  cpy->_nickname = strdup(this->_nickname);
  cpy->_username = strdup(this->_username);
  cpy->_realname = strdup(this->_realname);
  return (cpy);
}

void	handle_client_destroy(t_handle_client *this)
{
  if (close(this->_fd) == -1)
    {
      fprintf(stderr,
	      "[%d] Handle client error on func: close\n",
	      (int)getpid());
      exit(EXIT_FAILURE);
    }
}
