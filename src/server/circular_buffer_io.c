/*
** circular_buffer_io.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/server
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 23:56:19 2016 
** Last update Sun May 29 13:22:17 2016 
*/

#include "circular_buffer.h"

static int	calc_offset_write(t_circular_buffer *this)
{
  if (this->_idx_write >= this->_idx_read)
    {
      return (SIZE_BUFF - (int)(this->_idx_write - this->_idx_read));
    }
  else
    {
      return ((int)(this->_idx_read - this->_idx_write));
    }
}

static int	calc_offset_read(t_circular_buffer *this)
{
  if (this->_idx_read >= this->_idx_write)
    {
      return (SIZE_BUFF - (int)(this->_idx_read - this->_idx_write));
    }
  else
    {
      return ((int)(this->_idx_write - this->_idx_read));
    }
}

void	circular_buffer_write(t_circular_buffer *this, char *to_write)
{
  int	i;
  int	offset;

  i = 0;
  offset = calc_offset_write(this);
  while (i < offset && to_write[i])
    {
      this->_idx_write[0] = to_write[i];
      this->_idx_write++;
      i++;
      if (this->_idx_write == this->_idx_end)
	this->_idx_write = this->_buff;
    }
  if (to_write[i] != '\0')
    this->warning(this, "write", __FILE__, __LINE__);
}

static int	is_cmd_available(t_circular_buffer *this, int offset)
{
  int		i;
  char		*tmp;

  i = 0;
  tmp = this->_idx_read;
  while (i < offset)
    {
      if (i > 0 && tmp[i - 1] == '\r' && tmp[i] == '\n')
	return (1);
      i++;
      if (tmp + i == this->_idx_end)
	tmp = this->_buff;
    }
  return (0);
}

char	*circular_buffer_read_cmd(t_circular_buffer *this)
{
  char	*cmd;
  int	i;
  int	offset;

  i = -1;
  offset = calc_offset_read(this);
  if (!is_cmd_available(this, offset))
    return (NULL);
  cmd = malloc(sizeof(char) * (offset + 1));
  while (++i < offset)
    {
      cmd[i] = this->_idx_read[0];
      this->_idx_read[0] = '\0';
      if (i > 0 && cmd[i - 1] == '\r' && cmd[i] == '\n')
	{
	  this->_idx_read++;
	  cmd[i - 1] = '\0';
	  return (cmd);
	}
      this->_idx_read++;
      if (this->_idx_read == this->_idx_end)
	this->_idx_read = this->_buff;
    }
  this->warning(this, "read", __FILE__, __LINE__);
  return (NULL);
}
