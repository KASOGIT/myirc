/*
** commands_topic.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 11:08:00 2016 
** Last update Sun May 29 18:33:31 2016 
*/

#include "commands.h"

static void	get_topic(t_handle_client *this, t_server *server)
{
  char		msg[256];
  void		*elem;
  t_chan	*chan;

  if ((elem = server->get_chan_from_name(server, this->_args[0])) != NULL)
    {
      chan = (t_chan *)elem;
      if (chan->_topic)
	{
	  sprintf(msg, "%s :%s", chan->_name, chan->_topic);
	  this->send_rpl(this, RPL_TOPIC, msg, 1);
	}
      else
	{
	  sprintf(msg, "%s :No topic is set", chan->_name);
	  this->send_err(this, RPL_NOTOPIC, msg, 1);
	}
    }
  else
    this->send_err(this, ERR_NOTONCHANNEL, "no chan found", 1);
}

static void	set_topic(t_handle_client *this, t_server *server)
{
  char		msg[256];
  void		*elem;
  t_chan	*chan;

  if ((elem = server->get_chan_from_name(server,
					 this->_args[0])) != NULL)
    {
      chan = (t_chan *)elem;
      chan->_topic = strdup(this->_args[1]);
      sprintf(msg, "%s :%s", chan->_name, chan->_topic);
      this->send_rpl(this, RPL_TOPIC, msg, 1);
    }
  else
    this->send_err(this, ERR_NOTONCHANNEL, "no chan found", 1);
}

void		topic_cmd(t_handle_client *this, t_server *server)
{
  if (size_wordtab(this->_args) == 0)
    this->send_err(this, ERR_NEEDMOREPARAMS, "NOT ENOUGH PARAM", 1);
  else if (size_wordtab(this->_args) == 1)
    get_topic(this, server);
  else
    set_topic(this, server);
}
