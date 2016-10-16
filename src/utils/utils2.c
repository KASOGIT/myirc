/*
** utils2.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/utils
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 23:41:24 2016 
** Last update Sun May 29 14:45:58 2016 
*/

#include "utils.h"

static int	count_word_chan(char *str)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (str[i] && str[i] != '\r')
    {
      while (str[i] == ','
	     || str[i] == ' '
	     || str[i] == '\t'
	     || str[i] == '\r'
	     || str[i] == '\n')
	i++;
      if (!str[i])
	return (count);
      count++;
      while (str[i]
	     && str[i] != ','
	     && str[i] != '\r'
	     && str[i] != ' '
	     && str[i] != '\t')
	i++;
    }
  return (count);
}

static char	*epur_space(char *str)
{
  int		i;
  int		j;
  char		*epur;

  epur = malloc(sizeof(char) * (strlen(str) + 1));
  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  epur[j] = str[i];
	  j++;
	}
      i++;
    }
  epur[j] = '\0';
  return (epur);
}

char		**str_to_wordtab_chan(char *str)
{
  char		**tab;
  char		*tmp;
  int		nb_word;
  int		i;

  i = 0;
  nb_word = count_word_chan(str);
  if ((tab = malloc(sizeof(char *) * (nb_word + 1))) == NULL)
    return (NULL);
  while ((tmp = strsep(&str, ",")) != NULL)
    {
      tab[i] = strdup(tmp);
      tab[i] = epur_space(tab[i]);
      if (tab[i][0])
	i++;
    }
  tab[i] = NULL;
  return (tab);
}
