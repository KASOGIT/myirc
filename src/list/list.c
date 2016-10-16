/*
** list.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 21 20:19:26 2016 
** Last update Sun Jun  5 19:52:01 2016 
*/

#include "list.h"

void	list_set_methods(t_list *this)
{
  this->pop_back = &list_pop_back;
  this->pop_front = &list_pop_front;
  this->push_back = &list_push_back;
  this->push_front = &list_push_front;
  this->erase = &list_erase;
  this->erase_by_elem = &list_erase_by_elem;
  this->erase_by_elem_pred = &list_erase_by_elem_pred;
  this->empty = &list_empty;
  this->size = &list_size;
  this->for_each = &list_for_each;
  this->for_each_arg = &list_for_each_arg;
  this->front = &list_front;
  this->back = &list_back;
  this->begin = &list_begin;
  this->end = &list_end;
  this->max = &list_max;
  this->get_elem = &list_get_elem;
  this->get_elem_by_pred = &list_get_elem_by_pred;
  this->get_elem_by_pred_arg = &list_get_elem_by_pred_arg;
  this->any_of = &list_any_of;
}

void	list_init(t_list *this)
{
  this->_sz = 0;
  this->_head = NULL;
  this->_back = NULL;
}

t_list		*list_create()
{
  t_list	*new_list;

  new_list = malloc(sizeof(t_list));
  if (new_list == NULL)
    list_error(new_list, "malloc", __FILE__, __LINE__);
  list_init(new_list);
  list_set_methods(new_list);
  return (new_list);
}

void		list_destroy(t_list *this)
{
  t_elem	*tmp;
  t_elem	*to_del;

  if (this && this->_sz > 0)
    {
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  to_del = tmp;
	  tmp = tmp->_next;
	  elem_destroy(to_del);
	}
      elem_destroy(tmp);
      free(this);
    }
  else
    list_warning(this, "list_destroy", __FILE__, __LINE__);
}
