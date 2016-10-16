/*
** handle_client.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myftp
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Wed May  4 14:49:03 2016 
** Last update Fri Jun  3 18:51:34 2016 
*/

#include "handle_client.h"

void	handle_client_set_methods(t_handle_client *this)
{
  this->read_cmd = &handle_client_read_cmd;
  this->send_msg = &handle_client_send_msg;
  this->fill_buff = &handle_client_fill_buff;
  this->routine_cmd = &handle_client_routine_cmd;
  this->send_err = &handle_client_send_err;
  this->send_rpl = &handle_client_send_rpl;
}

void	handle_client_routine_cmd(t_handle_client *this,
				  t_server *server)
{
  int	i;

  i = 0;
  if (this->_cmd)
    {
      while (i < NB_CMD)
	{
	  if (strncmp(this->_cmd, g_cmd[i].cmd,
		      strlen(g_cmd[i].cmd)) == 0)
	    {
	      g_cmd[i].func_cmd(this, server);
	      i = NB_CMD;
	    }
	  i++;
	}
    }
}

void	handle_client_send_err(t_handle_client *this,
			       int c_err, const char *msg, int end)
{
  char	buff_msg[256];
  int	ret;

  if (end)
    sprintf(buff_msg, "%03d %s\r\n", c_err, msg);
  else
    sprintf(buff_msg, "%03d %s\r\n", c_err, msg);
  ret = write(this->_fd, buff_msg, strlen(buff_msg));
  if (ret == -1)
    perror("write");
}

void	handle_client_send_rpl(t_handle_client *this,
			       int c_rpl, const char *msg, int end)
{
  char	buff_msg[256];
  int	ret;

  if (end)
    sprintf(buff_msg, "%03d %s\r\n", c_rpl, msg);
  else
    sprintf(buff_msg, "%03d %s\r\n", c_rpl, msg);
  ret = write(this->_fd, buff_msg, strlen(buff_msg));
  if (ret == -1)
    perror("write");
}
