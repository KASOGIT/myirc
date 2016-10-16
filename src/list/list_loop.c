/*
** list_loop.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 22:56:10 2016 
** Last update Sat May 28 22:58:05 2016 
*/

#include "list.h"

void		list_for_each(t_list *this, void (*fun)(void *data))
{
  t_elem	*tmp;

  if (this && this->_sz > 0)
    {
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  (*fun)(tmp->_data);
	  tmp = tmp->_next;
	}
      (*fun)(tmp->_data);
    }
  else
    list_warning(this, "for_each", __FILE__, __LINE__);
}

void		list_for_each_arg(t_list *this,
				  void (*fun)(void *data, void *arg),
				  void *arg)
{
  t_elem	*tmp;

  if (this && this->_sz > 0)
    {
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  (*fun)(tmp->_data, arg);
	  tmp = tmp->_next;
	}
      (*fun)(tmp->_data, arg);
    }
  else
    list_warning(this, "for_each_arg", __FILE__, __LINE__);
}
