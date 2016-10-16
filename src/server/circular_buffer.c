/*
** circular_buffer.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/server
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue May 24 17:43:52 2016 
** Last update Fri Jun  3 17:38:30 2016 
*/

#include "circular_buffer.h"

static void	set_methods(t_circular_buffer *this)
{
  this->write = &circular_buffer_write;
  this->read_cmd = &circular_buffer_read_cmd;
  this->warning = &circular_buffer_warning;
}

void	circular_buffer_init(t_circular_buffer *this)
{
  set_methods(this);
  this->_buff = malloc(sizeof(char) * (SIZE_BUFF + 1));
  memset(this->_buff, 0, SIZE_BUFF + 1);
  this->_idx_read = this->_buff;
  this->_idx_write = this->_buff;
  this->_idx_end = this->_buff + SIZE_BUFF;
}

void	circular_buffer_destroy(t_circular_buffer *this)
{
  free(this->_buff);
}

void	circular_buffer_warning(__attribute__((unused))t_circular_buffer *this,
				const char *fun,
				const char *file,
				int line)
{
  if (DEBUG)
    {
      fprintf(stderr, "Warning: file: %s, line: %d, func: %s\n",
	      file,
	      line,
	      fun);
    }
}
