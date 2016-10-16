/*
** handle_client_utils.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myftp/src
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 15 11:04:46 2016 
** Last update Mon May 30 16:29:44 2016 
*/

#include "handle_client.h"

void		handle_client_send_msg(t_handle_client *this,
				       const char *msg)
{
  ssize_t	ret;

  ret = write(this->_fd, msg, strlen(msg));
  if (ret == -1)
    handle_client_error(this, "write");
}

void	handle_client_fill_buff(t_handle_client *this, t_server *server)
{
  char	buff[512];
  int	rd;

  memset(buff, 0, 512);
  rd = read(this->_fd, buff, 512);
  if (rd == -1)
    perror("read");
  else if (rd == 0)
    quit_cmd(this, server);
  buff[rd] = '\0';
  this->_buffer.write(&this->_buffer, buff);
}

void	handle_client_read_cmd(t_handle_client *this)
{
  char	*cmd;
  char	**split_cmd;

  cmd = this->_buffer.read_cmd(&this->_buffer);
  if (cmd && strlen(cmd) >= 4)
    {
      split_cmd = str_to_wordtab(strdup(cmd));
      this->_cmd = split_cmd[0];
      this->_args = split_cmd + 1;
      this->_args_chan = str_to_wordtab_chan(cmd + strlen(this->_cmd));
      this->_recipient = split_cmd[1];
      this->_msg = get_msg(strdup(cmd));
      free(cmd);
    }
  else
    {
      this->_cmd = NULL;
      this->_args = NULL;
    }
}
