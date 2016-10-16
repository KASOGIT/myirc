/*
** list_get.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 23:02:59 2016 
** Last update Sat May 28 23:08:00 2016 
*/

#include "list.h"

void		*list_max(t_list *this,
			  void *(*func_comp)(void *d1, void *d2))
{
  t_elem	*tmp;
  void		*max;

  if (this && this->_sz > 1)
    {
      tmp = this->begin(this)->_next;
      max = this->front(this);
      while (tmp != this->end(this))
	{
	  max = (*func_comp)(max, tmp->_data);
	  tmp = tmp->_next;
	}
      max = (*func_comp)(max, tmp->_data);
      return (max);
    }
  else if (this && this->_sz == 1)
    {
      return (this->front(this));
    }
  else
    list_warning(this, "max", __FILE__, __LINE__);
  return (NULL);
}

void		*list_get_elem(t_list *this, int pos)
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->begin(this);
      while (pos && tmp != this->end(this))
	{
	  tmp = tmp->_next;
	  pos--;
	}
      if (pos == 0)
	{
	  return (tmp->_data);
	}
    }
  list_warning(this, "get_elem", __FILE__, __LINE__);
  return (NULL);
}

void		*list_get_elem_by_pred(t_list *this, int (*pred)(void *data))
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->begin(this);
      while (tmp != this->end(this))
	{
	  if ((*pred)(tmp->_data))
	    return (tmp->_data);
	  tmp = tmp->_next;
	}
      if ((*pred)(tmp->_data))
	return (tmp->_data);
    }
  list_warning(this, "get_elem_by_pred", __FILE__, __LINE__);
  return (NULL);
}

int		list_any_of(t_list *this,
			    int (*pred)(void *d1, void *d2),
			    void *to_cmp)
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->begin(this);
      while (tmp != this->end(this))
	{
	  if ((*pred)(to_cmp, tmp->_data))
	    return (1);
	  tmp = tmp->_next;
	}
      if ((*pred)(to_cmp, tmp->_data))
	return (1);
      return (0);
    }
  list_warning(this, "any_of", __FILE__, __LINE__);
  return (0);
}

void		*list_get_elem_by_pred_arg(t_list *this,
					   int (*pred)(void *data, void *arg),
					   void *arg)
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->begin(this);
      while (tmp != this->end(this))
	{
	  if ((*pred)(tmp->_data, arg))
	    return (tmp->_data);
	  tmp = tmp->_next;
	}
      if ((*pred)(tmp->_data, arg))
	return (tmp->_data);
    }
  list_warning(this, "get_elem_by_pred_arg", __FILE__, __LINE__);
  return (NULL);
}
