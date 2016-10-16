/*
** list_misc.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 22:51:20 2016 
** Last update Sat May 28 22:53:47 2016 
*/

#include "list.h"

int	list_empty(t_list *this)
{
  if (this)
    {
      if (this->_sz == 0)
	return (1);
    }
  else
    list_warning(this, "empty", __FILE__, __LINE__);
  return (0);
}

int	list_size(t_list *this)
{
  if (this)
    return (this->_sz);
  else
    list_warning(this, "size", __FILE__, __LINE__);
  return (0);
}
