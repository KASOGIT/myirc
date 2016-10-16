/*
** server_func2.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 01:16:43 2016 
** Last update Mon May 30 13:01:13 2016 
*/

#include "server.h"

static char	*fill_buff(char *buff, t_elem *tmp, int end)
{
  char		tmpb[4096];

  memset(tmpb, 0, 4096);
  if (((t_chan *)tmp->data(tmp))->_topic)
    {
      if (!end)
	sprintf(tmpb, "%s :%s ",
		((t_chan *)tmp->data(tmp))->_name,
		((t_chan *)tmp->data(tmp))->_topic);
      else
	sprintf(tmpb, "%s :%s",
		((t_chan *)tmp->data(tmp))->_name,
		((t_chan *)tmp->data(tmp))->_topic);
      buff = strcat(buff, tmpb);
    }
  return (buff);
}

char		*server_get_all_chan_topic(t_server *this)
{
  char		*buff;
  t_elem	*tmp;

  if (this->_chans->size(this->_chans) > 0)
    {
      buff = malloc(sizeof(char) * 4096);
      memset(buff, 0, 4096);
      tmp = this->_chans->begin(this->_chans);
      while (tmp != this->_chans->end(this->_chans))
	{
	  buff = fill_buff(buff, tmp, 0);
	  tmp = tmp->next(tmp);
	}
      buff = fill_buff(buff, tmp, 1);
      return (buff);
    }
  return ("");
}

static char	*fill_buff2(char *buff, t_elem *tmp, int end)
{
  char		tmpb[4096];

  if (((t_handle_client *)tmp->data(tmp))->_nickname)
    {
      memset(tmpb, 0, 4096);
      if (!end)
	sprintf(tmpb, ":%s ",
		((t_handle_client *)tmp->data(tmp))->_nickname);
      else
	sprintf(tmpb, ":%s",
		((t_handle_client *)tmp->data(tmp))->_nickname);
      buff = strcat(buff, tmpb);
    }
  return (buff);
}

char		*server_get_users(t_server *this)
{
  char		*buff;
  t_elem	*tmp;

  if (this->_users->size(this->_users) > 0)
    {
      buff = malloc(sizeof(char) * 4096);
      tmp = this->_users->begin(this->_users);
      while (tmp != this->_users->end(this->_users))
	{
	  buff = fill_buff2(buff, tmp, 0);
	  tmp = tmp->next(tmp);
	}
      buff = fill_buff2(buff, tmp, 1);
      return (buff);
    }
  return ("");
}

void		server_epur_chans(t_server *this)
{
  t_elem	*tmp;

  tmp = this->_chans->begin(this->_chans);
  while (tmp != this->_chans->end(this->_chans))
    {
      if (((t_chan *)tmp)->_users->_sz == 0)
	{
	  this->_chans->erase_by_elem(this->_chans,
				      (t_chan *)tmp);
	  tmp = this->_chans->begin(this->_chans);
	}
      else
	tmp = tmp->next(tmp);
    }
}
