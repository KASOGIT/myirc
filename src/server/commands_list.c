/*
** commands_list.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 01:47:36 2016 
** Last update Sun May 29 18:47:04 2016 
*/

#include "commands.h"

static void	display_chan_info(t_handle_client *this, void *elem)
{
  char		buff[4096];
  t_chan	*chan;

  chan = (t_chan *)elem;
  if (chan->_topic)
    {
      memset(buff, 0, 4096);
      sprintf(buff, "%s :%s ", chan->_name, chan->_topic);
      this->send_rpl(this, RPL_LIST, buff, 1);
    }
}

void		list_cmd(t_handle_client *this, t_server *server)
{
  int		i;
  void		*elem;

  if (size_wordtab(this->_args_chan) == 0)
    {
      this->send_rpl(this, RPL_LIST,
		     server->get_all_chan_topic(server), 1);
      this->send_rpl(this, RPL_LISTEND, ":End of LIST", 1);
    }
  else
    {
      i = 0;
      while (this->_args[i])
	{
	  if ((elem =
	       server->get_chan_from_name(server,
	       this->_args_chan[i])) != NULL)
	    display_chan_info(this, elem);
	  i++;
	}
      this->send_rpl(this, RPL_LISTEND, ":End of LIST", 1);
    }
}
