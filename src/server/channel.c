/*
** channel.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 22 15:08:13 2016 
** Last update Sun May 29 22:24:18 2016 
*/

#include "channel.h"

void	set_methods(t_chan *this)
{
  this->is_already_in_chan = &chan_is_already_in_chan;
  this->list_users = &chan_list_users;
  this->get_list_users = &chan_get_list_users;
  this->send_msg_to_users = &chan_send_msg_to_users;
}

void	chan_init(t_chan *this, char *name)
{
  set_methods(this);
  this->_name = name;
  this->_topic = NULL;
  this->_users = list_create();
}

void	chan_destroy(t_chan *this)
{
  list_destroy(this->_users);
}

static int		comp_nick(void *arg, void *data)
{
  t_handle_client	*client;
  char			*nick;

  client = (t_handle_client *)data;
  nick = (char *)arg;
  if (client && client->_nickname && nick)
    if (strcmp(client->_nickname, nick) == 0)
      return (1);
  return (0);
}

int	chan_is_already_in_chan(t_chan *this, char *nickname)
{
  return (this->_users->any_of(this->_users, &comp_nick, nickname));
}
