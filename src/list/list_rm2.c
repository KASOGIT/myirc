/*
** list_rm2.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 22:44:01 2016 
** Last update Mon May 30 18:38:09 2016 
*/

#include "list.h"

void		list_pop_back(t_list *this)
{
  t_elem	*to_del;

  if (this && this->_sz > 1)
    {
      to_del = this->_back;
      this->_back->_prev->_next = this->_head;
      this->_head->_prev = this->_back->_prev;
      this->_back = this->_back->_prev;
      elem_destroy(to_del);
      this->_sz--;
    }
  else if (this && this->_sz == 1)
    {
      this->_sz = 0;
      to_del = this->_back;
      elem_destroy(to_del);
      list_init(this);
    }
  else
    list_warning(this, "pop_back", __FILE__, __LINE__);
}

void		list_pop_front(t_list *this)
{
  t_elem	*to_del;

  if (this && this->_sz > 1)
    {
      to_del = this->_head;
      this->_back->_next = this->_head->_next;
      this->_head->_next->_prev = this->_back;
      this->_head = this->_head->_next;
      this->_sz--;
    }
  else if (this && this->_sz == 1)
    {
      this->_sz = 0;
      to_del = this->_head;
      elem_destroy(to_del);
      list_init(this);
    }
  else
    list_warning(this, "pop_front", __FILE__, __LINE__);
}
