/*
** list_utils.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 22:05:03 2016 
** Last update Fri Jun  3 17:32:41 2016 
*/

#include "list.h"

void	list_warning(__attribute__((unused))t_list *this,
		     const char *func,
		     const char *file,
		     int line)
{
  if (DEBUG)
    {
      fprintf(stderr, "Warning: file: %s, line: %d, func: %s\n",
	      file,
	      line,
	      func);
    }
}

void	list_error(t_list *this,
		   const char *func,
		   const char *file,
		   int line)
{
  if (DEBUG)
    {
      fprintf(stderr, "Error: file: %s, line: %d, func: %s\n",
	      file,
	      line,
	      func);
    }
  list_destroy(this);
  exit(EXIT_FAILURE);
}
