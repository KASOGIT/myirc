/*
** commands_join.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 02:00:07 2016 
** Last update Sun Jun  5 20:17:50 2016 
*/

#include "commands.h"

static void	join_exist(t_handle_client *this,
			   t_chan *chan, void *elem)
{
  char		msg[256];

  chan = (t_chan *)elem;
  if (!chan->is_already_in_chan(chan, this->_nickname))
    {
      chan->_users->push_back(chan->_users, handle_client_copy(this));
      sprintf(msg, ":%s JOIN %s", this->_nickname, chan->_name);
      chan->send_msg_to_users(chan, msg);
      if (chan->_topic)
	{
	  sprintf(msg, "%s :%s", chan->_name, chan->_topic);
	  this->send_rpl(this, RPL_TOPIC, msg, 1);
	}
      else
	{
	  sprintf(msg, "%s :No topic is set", chan->_name);
	  this->send_rpl(this, RPL_NOTOPIC, msg, 1);
	}
      this->send_rpl(this, RPL_NAMREPLY, chan->get_list_users(chan), 1);
      memset(msg, 0, 256);
      sprintf(msg, "%s :End of /NAMES list", chan->_name);
      this->send_rpl(this, RPL_ENDOFNAMES, msg, 1);
    }
  else
    this->send_err(this, ERR_BADCHANNELKEY, "already in chan", 1);
}

static void	join_create(t_handle_client *this,
			    t_chan *chan, t_server *server, int i)
{
  char		msg[256];

  chan = malloc(sizeof(t_chan));
  chan_init(chan, strdup(this->_args_chan[i]));
  server->_chans->push_back(server->_chans, chan);
  chan->_users->push_back(chan->_users, handle_client_copy(this));
  sprintf(msg, ":%s JOIN %s", this->_nickname, chan->_name);
  chan->send_msg_to_users(chan, msg);
  sprintf(msg, "%s :No topic is set", chan->_name);
  this->send_rpl(this, RPL_NOTOPIC, msg, 1);
  memset(msg, 0, 256);
  sprintf(msg, "= %s :%s", chan->_name, this->_nickname);
  this->send_rpl(this, RPL_NAMREPLY, msg, 1);
  memset(msg, 0, 256);
  sprintf(msg, "%s :End of /NAMES list", chan->_name);
  this->send_rpl(this, RPL_ENDOFNAMES, msg, 1);
}

static void	run_search(t_handle_client *this, t_server *server, int i)
{
  void		*elem;
  t_chan	*chan;

  if ((elem = server->get_chan_from_name(server,
       this->_args_chan[i])) != NULL)
    join_exist(this, chan, elem);
  else
    join_create(this, chan, server, i);
}

void		join_cmd(t_handle_client *this, t_server *server)
{
  int		i;

  if (size_wordtab(this->_args_chan) < 1)
    this->send_err(this, ERR_NEEDMOREPARAMS, "not enough params", 1);
  else if (!this->_registered)
    this->send_err(this, ERR_NOSUCHNICK, "not registered", 1);
  else if (this->_args[0][0] == '0')
    server->_chans->for_each_arg(server->_chans, &leave_chans, this);
  else
    {
      i = 0;
      while (this->_args_chan[i])
	{
	  if (!(check_chan_fmt(this->_args_chan[i])))
	    run_search(this, server, i);
	  else
	    this->send_err(this, ERR_NOSUCHCHANNEL, "bad chan name fmt", 1);
	  i++;
	}
    }
}
