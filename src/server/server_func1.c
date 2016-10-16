/*
** server_func1.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 01:14:28 2016 
** Last update Mon May 30 12:51:07 2016 
*/

#include "server.h"

static int	is_chan_match_name(void *data, void *arg)
{
  t_chan	*chan;
  char		*name;

  chan = (t_chan *)data;
  name = (char *)arg;
  if (strcmp(chan->_name, name) == 0)
    return (1);
  return (0);
}

void	*server_get_chan_from_name(t_server *this, char *name_chan)
{
  return (this->_chans->get_elem_by_pred_arg(this->_chans,
					     &is_chan_match_name,
					     name_chan));
}

static void	display_chan_users(void *data, void *arg)
{
  t_chan	*chan;

  chan = (t_chan *)data;
  chan->list_users(chan, (t_handle_client *)arg);
}

char		*server_get_all_users_on_chans(t_server *this)
{
  char		*buff;
  t_elem	*tmp;

  if (!this || !this->_chans || !this->_chans->_sz)
    return ("");
  buff = malloc(sizeof(char) * 8192);
  memset(buff, 0, 8192);
  tmp = this->_chans->begin(this->_chans);
  while (tmp != this->_chans->end(this->_chans))
    {
      buff = strcat(buff,
		    ((t_chan *)tmp->data(tmp))->
		    get_list_users(((t_chan *)tmp->data(tmp))));
      buff = strcat(buff, " ");
      tmp = tmp->next(tmp);
    }
  buff = strcat(buff,
		((t_chan *)tmp->data(tmp))->
		get_list_users(((t_chan *)tmp->data(tmp))));
  buff = strcat(buff, " ");
  return (buff);
}

void	server_list_all_users_on_chans(t_server *this,
				       t_handle_client *client)
{
  this->_chans->for_each_arg(this->_chans,
			     &display_chan_users, client);
  client->send_msg(client, "\r\n");
}
