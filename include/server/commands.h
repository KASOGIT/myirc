/*
** commands.h for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myftp
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu May  5 17:17:32 2016 
** Last update Fri Jun  3 18:02:49 2016 
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "handle_client.h"
#include "server.h"

#define DEBUG	0
#define NB_CMD	11
#define ERR_NEEDMOREPARAMS	461
#define ERR_ALREADYREGISTRED	462
#define ERR_NONICKNAMEGIVEN	431
#define ERR_NICKNAMEINUSE	433
#define ERR_UNAVAILRESOURCE	437
#define ERR_ERRONEUSNICKNAME	432
#define ERR_NICKCOLLISION	436
#define ERR_RESTRICTED		484
#define ERR_CHANNELISFULL	471
#define ERR_NEEDMOREPARAMS	461
#define ERR_TOOMANYTARGETS	407
#define ERR_TOOMANYCHANNELS	405
#define ERR_NOTONCHANNEL	442
#define ERR_NOSUCHCHANNEL	403
#define ERR_TOOMANYMATCHES	416
#define ERR_NOSUCHSERVER	402
#define ERR_NORECIPIENT		411
#define ERR_CANNOTSENDTOCHAN	404
#define ERR_WILDTOPLEVEL	414
#define ERR_NOSUCHNICK		401
#define ERR_NOTEXTTOSEND	412
#define ERR_NOTOPLEVEL		412
#define ERR_USERSDISABLED	446
#define ERR_FILEERROR		424
#define ERR_UNKNOWNCOMMAND	421
#define ERR_USERNOTINCHANNEL	441
#define ERR_USERONCHANNEL	443
#define ERR_NOLOGIN		444
#define ERR_BADCHANNELKEY	475
#define RPL_USERS		393
#define RPL_ENDOFUSERS		394
#define RPL_WELCOME		001
#define RPL_YOURHOST		002
#define RPL_CREATED		003
#define RPL_USERSSTART		392
#define RPL_NOUSERS		395
#define RPL_AWAY		301
#define RPL_NAMREPLY		353
#define RPL_LISTEND		323
#define RPL_LIST		322
#define RPL_TOPIC		332
#define RPL_ENDOFNAMES		366
#define RPL_NOTOPIC		331
#define	MAX_NICK_LEN		9
#define MAX_CHAN_LEN		50
#define MAX_CMD_PARAMS		15
#define MAX_SERVER_NAME_LEN	63
#define MAX_HOST_NAME_LEN	255

typedef struct s_handle_client	t_handle_client;
typedef struct s_server		t_server;

typedef struct	s_cmd
{
  char		*cmd;
  void		(*func_cmd)(t_handle_client *this, t_server *server);
}		t_cmd;

void	user_cmd(t_handle_client *this, t_server *server);
void	nick_cmd(t_handle_client *this, t_server *server);
void	list_cmd(t_handle_client *this, t_server *server);
void	join_cmd(t_handle_client *this, t_server *server);
int	check_chan_fmt(char *name);
void	leave_chans(void *data, void *arg);
void	part_cmd(t_handle_client *this, t_server *server);
void	users_cmd(t_handle_client *this, t_server *server);
void	names_cmd(t_handle_client *this, t_server *server);
void	pass_cmd(t_handle_client *this, t_server *server);
void	privmsg_cmd(t_handle_client *this, t_server *server);
void	quit_cmd(t_handle_client *this, t_server *server);
void	topic_cmd(t_handle_client *this, t_server *server);

extern struct s_cmd	g_cmd[NB_CMD];

#endif /* !COMMANDS_H_ */
