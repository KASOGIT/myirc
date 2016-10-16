/*
** commands_privmsg.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 03:16:00 2016 
** Last update Sun May 29 12:19:31 2016 
*/

#include "commands.h"

static void		send_msg(t_handle_client *this, void *elem)
{
  t_handle_client	*client;

  if (elem != NULL)
    {
      client = (t_handle_client *)elem;
      client->send_msg(client, strdup(this->_msg));
      client->send_msg(client, "\r\n");
    }
}

void		privmsg_cmd(t_handle_client *this, t_server *server)
{
  void		*elem;
  t_chan	*chan;

  if (this->_recipient == NULL)
    this->send_err(this, ERR_NORECIPIENT, "no recipient", 1);
  else if (this->_msg == NULL)
    this->send_err(this, ERR_NOTEXTTOSEND, "no text to send", 1);
  else
    {
      elem = server->get_chan_from_name(server, this->_recipient);
      if (elem != NULL)
	{
	  chan = (t_chan *)elem;
	  chan->send_msg_to_users(chan, strdup(this->_msg));
	}
      else
	{
	  elem = server->get_user_from_name(server, this->_recipient);
	  send_msg(this, elem);
	}
    }
}
