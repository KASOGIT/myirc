/*
** commands_part.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 03:07:41 2016 
** Last update Sun Jun  5 13:22:48 2016 
*/

#include "commands.h"

static int		is_same_fd(void *data, void *elem)
{
  t_handle_client	*this;
  t_handle_client	*other;

  this = (t_handle_client *)data;
  other = (t_handle_client *)elem;
  if (this->_fd == other->_fd)
    return (1);
  return (0);
}

static void	detach(t_handle_client *this, t_server *server,
		       void *elem)
{
  t_chan	*chan;
  char		msg[256];

  chan = (t_chan *)elem;
  sprintf(msg, ":%s PART %s", this->_nickname, chan->_name);
  chan->send_msg_to_users(chan, msg);
  chan->_users->erase_by_elem_pred(chan->_users, &is_same_fd, this);
  if (chan->_users->size(chan->_users) == 0)
    server->_chans->erase_by_elem(server->_chans, chan);
}

void		part_cmd(t_handle_client *this, t_server *server)
{
  void		*elem;
  int		i;

  if (size_wordtab(this->_args_chan) < 1)
    this->send_err(this, ERR_NEEDMOREPARAMS, "not enough params", 1);
  else if (!this->_registered)
    this->send_err(this, ERR_NOSUCHNICK, "not registered", 1);
  else
    {
      i = 0;
      while (this->_args_chan[i])
	{
	  if ((elem = server->get_chan_from_name(server,
	       this->_args_chan[i])) != NULL)
	    detach(this, server, elem);
	  else
	    this->send_err(this, ERR_NOSUCHCHANNEL, "NO CHAN FOUND", 1);
	  i++;
	}
    }
}
