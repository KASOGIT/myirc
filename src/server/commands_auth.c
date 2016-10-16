/*
** commands_auth.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 29 01:44:39 2016 
** Last update Fri Jun  3 18:11:03 2016 
*/

#include "commands.h"

void	user_cmd(t_handle_client *this,
		 __attribute__((unused))t_server *server)
{
  if (this->_registered)
    this->send_err(this, ERR_ALREADYREGISTRED,
		   "already registered", 1);
  else if (!this->_nickname)
    this->send_err(this, ERR_NONICKNAMEGIVEN,
		   "no nickname given", 1);
  else if (size_wordtab(this->_args) < 4)
    this->send_err(this, ERR_NEEDMOREPARAMS,
		   "not enough params", 1);
  else
    {
      this->_registered = 1;
      this->_username = strdup(this->_args[0]);
      this->_realname = strdup(this->_args[3]);
      this->send_rpl(this, RPL_WELCOME,
		     ":Welcome to the Internet Relay Network", 0);
      this->send_rpl(this, RPL_YOURHOST, ":Your host is 127.0.0.1", 0);
      this->send_rpl(this, RPL_CREATED, ":hi Gildas", 0);
    }
}

static int		comp_nick(void *d1, void *d2)
{
  char			*n1;
  t_handle_client	*c2;

  n1 = (char *)d1;
  c2 = (t_handle_client *)d2;
  if (c2->_nickname
      && strncmp(n1, c2->_nickname, strlen(n1)) == 0)
    return (1);
  return (0);
}

static int	check_nick(char *nick)
{
  if (strlen(nick) <= 9)
    return (0);
  return (1);
}

void	nick_cmd(t_handle_client *this, t_server *server)
{
  if (size_wordtab(this->_args) < 1)
    this->send_err(this, ERR_NONICKNAMEGIVEN, "no nick given", 1);
  else if (check_nick(this->_args[0]))
    this->send_err(this, ERR_ERRONEUSNICKNAME, "bad formed nick", 1);
  else if (server->_users->any_of(server->_users, &comp_nick, this->_args[0]))
    this->send_err(this, ERR_NICKNAMEINUSE, "nick in use", 1);
  else
    this->_nickname = strdup(this->_args[0]);
}
