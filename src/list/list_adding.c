/*
** list_adding.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 22:15:01 2016 
** Last update Sat May 28 22:18:50 2016 
*/

#include "list.h"

void		list_push_back(t_list *this, void *data)
{
  t_elem	*new_elem;

  new_elem = elem_create(data);
  if (this && this->_sz == 0)
    {
      this->_head = new_elem;
      this->_back = new_elem;
      new_elem->_next = new_elem;
      new_elem->_prev = new_elem;
      this->_sz++;
    }
  else if (this)
    {
      new_elem->_next = this->_head;
      new_elem->_prev = this->_back;
      this->_back->_next = new_elem;
      this->_head->_prev = new_elem;
      this->_back = new_elem;
      this->_sz++;
    }
  else
    list_warning(this, "push_back", __FILE__, __LINE__);
}

void		list_push_front(t_list *this, void *data)
{
  t_elem	*new_elem;

  new_elem = elem_create(data);
  if (this && this->_sz == 0)
    {
      this->_head = new_elem;
      this->_back = new_elem;
      new_elem->_next = new_elem;
      new_elem->_prev = new_elem;
      this->_sz++;
    }
  else if (this)
    {
      new_elem->_next = this->_head;
      new_elem->_prev = this->_back;
      this->_head->_prev = new_elem;
      this->_back->_next = new_elem;
      this->_head = new_elem;
      this->_sz++;
    }
  else
    list_warning(this, "push_front", __FILE__, __LINE__);
}
