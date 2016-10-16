/*
** commands.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Wed May 25 22:51:17 2016 
** Last update Mon May 30 18:38:38 2016 
*/

#include "commands.h"

t_cmd	g_cmd[NB_CMD] =
  {
    {"USERS", &users_cmd},
    {"USER", &user_cmd},
    {"NICK", &nick_cmd},
    {"LIST", &list_cmd},
    {"JOIN", &join_cmd},
    {"PART", &part_cmd},
    {"NAMES", &names_cmd},
    {"PASS", &pass_cmd},
    {"PRIVMSG", &privmsg_cmd},
    {"QUIT", &quit_cmd},
    {"TOPIC", &topic_cmd}
  };

void	users_cmd(t_handle_client *this, t_server *server)
{
  if (server->_users->size(server->_users) == 0)
    this->send_rpl(this, RPL_NOUSERS, "no usrs loggin", 1);
  else
    {
      this->send_rpl(this, RPL_USERS, server->get_users(server), 1);
      this->send_rpl(this, RPL_ENDOFUSERS, "end listing", 1);
    }
}

void		names_cmd(t_handle_client *this, t_server *server)
{
  int		i;
  void		*elem;
  t_chan	*chan;

  if (size_wordtab(this->_args_chan) == 0)
    this->send_rpl(this, RPL_NAMREPLY,
		   server->get_all_users_on_chans(server), 1);
  else
    {
      i = 0;
      while (this->_args_chan[i])
	{
	  if ((elem = server->get_chan_from_name(server,
	       this->_args_chan[i])) != NULL)
	    {
	      chan = (t_chan *)elem;
	      this->send_rpl(this, RPL_NAMREPLY,
			     chan->get_list_users(chan), 1);
	    }
	  i++;
	}
    }
  this->send_rpl(this, RPL_ENDOFNAMES, ":End of NAMES", 1);
}

void	pass_cmd(__attribute__((unused))t_handle_client *this,
		 __attribute__((unused))t_server *server)
{
}

void	display(void *data)
{
  printf("elem : %s\n", ((t_chan *)data)->_name);
}

void	quit_cmd(t_handle_client *this, t_server *server)
{
  server->_chans->for_each_arg(server->_chans, &leave_chans, this);
  server->epur_chans(server);
  server->_users->erase_by_elem(server->_users, this);
  handle_client_destroy(this);
}
