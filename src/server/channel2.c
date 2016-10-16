/*
** channel2.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 00:09:16 2016 
** Last update Mon May 30 12:54:03 2016 
*/

#include "channel.h"

static void		list_users_chan(void *data, void *arg)
{
  t_handle_client	*client_chan;
  t_handle_client	*client_srv;
  char			buff[256];

  client_chan = (t_handle_client *)data;
  client_srv = (t_handle_client *)arg;
  if (client_chan && client_chan->_nickname)
    {
      sprintf(buff, " :%s", client_chan->_nickname);
      client_srv->send_msg(client_srv, buff);
    }
}

static void		send_msg_cl(void *data, void *arg)
{
  int			ret;
  t_handle_client	*client;
  char			*msg;

  client = (t_handle_client *)data;
  msg = (char *)arg;
  ret = write(client->_fd, msg, strlen(msg));
  ret = write(client->_fd, "\r\n", 2);
  (void)ret;
}

void	chan_send_msg_to_users(t_chan *this, char *msg)
{
  this->_users->for_each_arg(this->_users, &send_msg_cl, msg);
}

void	chan_list_users(t_chan *this, t_handle_client *client)
{
  char	buff[256];

  if (this->_name)
    {
      sprintf(buff, "= %s", this->_name);
      client->send_msg(client, buff);
    }
  this->_users->for_each_arg(this->_users,
			     &list_users_chan, client);
}

char		*chan_get_list_users(t_chan *this)
{
  t_elem	*tmp;
  char		*buff;
  char		tmpb[4096];

  if (!this || !this->_users || !this->_users->_sz)
    return ("");
  buff = malloc(sizeof(char) * 4096);
  memset(buff, 0, 4096);
  tmp = this->_users->begin(this->_users);
  sprintf(buff, "= %s ", this->_name);
  while (tmp != this->_users->end(this->_users))
    {
      memset(tmpb, 0, 4096);
      sprintf(tmpb, ":%s ",
	      ((t_handle_client *)tmp->data(tmp))->_nickname);
      buff = strcat(buff, tmpb);
      tmp = tmp->next(tmp);
    }
  memset(tmpb, 0, 4096);
  sprintf(tmpb, ":%s",
	  ((t_handle_client *)tmp->data(tmp))->_nickname);
  buff = strcat(buff, tmpb);
  return (buff);
}
