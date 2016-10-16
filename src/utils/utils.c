/*
** utils.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myftp/src
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu May  5 17:01:19 2016 
** Last update Sat May 28 23:45:26 2016 
*/

#include "utils.h"

static int	count_word(char *str)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (str[i] && str[i] != '\r')
    {
      while (str[i] == ' ' || str[i] == '\t'
	     || str[i] == '\r' || str[i] == '\n')
	i++;
      if (!str[i])
	return (count);
      count++;
      while (str[i]
	     && str[i] != '\r'
	     && str[i] != ' '
	     && str[i] != '\t')
	i++;
    }
  return (count);
}

char		**str_to_wordtab(char *str)
{
  char		**tab;
  char		*tmp;
  int		nb_word;
  int		i;

  i = 0;
  nb_word = count_word(str);
  if ((tab = malloc(sizeof(char *) * (nb_word + 1))) == NULL)
    return (NULL);
  while ((tmp = strsep(&str, " ")) != NULL)
    {
      tab[i] = strdup(tmp);
      if (tab[i][0])
	i++;
    }
  tab[i] = NULL;
  return (tab);
}

int	size_wordtab(char **tab)
{
  int	s;

  s = 0;
  while (tab && tab[s] != NULL)
    {
      s++;
    }
  return (s);
}

char	*get_msg(char *cmd)
{
  int	i;

  i = 0;
  while (i != 2 && strsep(&cmd, " "))
    {
      i++;
    }
  return (cmd);
}
