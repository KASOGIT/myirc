/*
** list_rm.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 22:19:19 2016 
** Last update Mon May 30 18:14:08 2016 
*/

#include "list.h"

static void	detach(t_list *this, t_elem *tmp)
{
  if (tmp == this->_back)
    this->pop_back(this);
  else if (tmp == this->_head)
    this->pop_front(this);
  else
    {
      tmp->_prev->_next = tmp->_next;
      tmp->_next->_prev = tmp->_prev;
      elem_destroy(tmp);
      this->_sz--;
    }
}

void		list_erase(t_list *this, int pos)
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->_head;
      while (pos && tmp != this->_back)
	{
	  tmp = tmp->_next;
	  pos--;
	}
      if (pos == 0)
	detach(this, tmp);
      else
	list_warning(this, "erase", __FILE__, __LINE__);
    }
  else
    list_warning(this, "erase", __FILE__, __LINE__);
}

void		list_erase_by_elem(t_list *this, void *elem)
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->_head;
      while (tmp->_data != elem && tmp != this->_back)
	tmp = tmp->_next;
      if (tmp->_data == elem)
	detach(this, tmp);
      else
	list_warning(this, "erase_by_elem", __FILE__, __LINE__);
    }
  else
    list_warning(this, "erase_by_elem", __FILE__, __LINE__);
}

static void	detach_pred(t_list *this, t_elem *tmp, int pos)
{
  if (pos == this->size(this) - 1)
    this->pop_back(this);
  else if (pos == 0)
    this->pop_front(this);
  else
    {
      tmp->_prev->_next = tmp->_next;
      tmp->_next->_prev = tmp->_prev;
      elem_destroy(tmp);
      this->_sz--;
    }
}

void		list_erase_by_elem_pred(t_list *this,
					int (*pred)(void *data, void *elem),
					void *elem)
{
  t_elem	*tmp;
  int		pos;

  if (this && this->_head)
    {
      pos = 0;
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  if ((*pred)(tmp->data(tmp), elem))
	    {
	      detach_pred(this, tmp, pos);
	      return ;
	    }
	  tmp = tmp->_next;
	  pos++;
	}
      if ((*pred)(tmp->data(tmp), elem))
	if (pos == this->size(this) - 1)
	  this->pop_back(this);
    }
  else
    list_warning(this, "erase_by_elem", __FILE__, __LINE__);
}
