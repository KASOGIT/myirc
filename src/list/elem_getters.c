/*
** elem_getters.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 11:47:12 2016 
** Last update Sun May 29 11:47:49 2016 
*/

#include "elem.h"

void	*elem_data(t_elem *this)
{
  return (this->_data);
}

t_elem	*elem_next(t_elem *this)
{
  return (this->_next);
}

t_elem	*elem_prev(t_elem *this)
{
  return (this->_prev);
}
