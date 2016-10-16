/*
** commands_join_utils.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/server
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 02:28:30 2016 
** Last update Sun May 29 02:29:21 2016 
*/

#include "commands.h"

int		check_chan_fmt(char *name)
{
  int		i;

  i = 1;
  if (strlen(name) > 1 && strlen(name) < MAX_CHAN_LEN)
    {
      if (name[0] == '&'
	  || name[0] == '#'
	  || name[0] == '+'
	  || name[0] == '!')
	{
	  while (name[i])
	    {
	      if (name[i] == ' ' || name[i] == ',')
		return (1);
	      i++;
	    }
	  return (0);
	}
    }
  return (1);
}
