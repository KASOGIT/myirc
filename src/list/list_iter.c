/*
** list_iter.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 23:00:40 2016 
** Last update Sat May 28 23:01:27 2016 
*/

#include "list.h"

void	*list_front(t_list *this)
{
  if (this && this->_head)
    return (this->_head->_data);
  else
    list_warning(this, "front", __FILE__, __LINE__);
  return (NULL);
}

void	*list_back(t_list *this)
{
  if (this && this->_back)
    return (this->_back->_data);
  else
    list_warning(this, "back", __FILE__, __LINE__);
  return (NULL);
}

t_elem	*list_begin(t_list *this)
{
  if (this && this->_head)
    {
      return (this->_head);
    }
  else
    list_warning(this, "begin", __FILE__, __LINE__);
  return (NULL);
}

t_elem	*list_end(t_list *this)
{
  if (this && this->_back)
    {
      return (this->_back);
    }
  else
    list_warning(this, "end", __FILE__, __LINE__);
  return (NULL);
}
