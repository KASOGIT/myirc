/*
** commands_leave_chan.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/server
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon May 30 16:28:03 2016 
** Last update Mon May 30 16:28:39 2016 
*/

#include "commands.h"

static int		is_name_match(void *data, void *arg)
{
  t_handle_client	*c1;
  t_handle_client	*c2;

  c1 = (t_handle_client *)data;
  c2 = (t_handle_client *)arg;
  if (strcmp(c1->_nickname, c2->_nickname) == 0)
    return (1);
  return (0);
}

void		leave_chans(void *data, void *arg)
{
  t_chan	*chan;

  chan = (t_chan *)data;
  chan->_users->erase_by_elem_pred(chan->_users, &is_name_match, arg);
}
