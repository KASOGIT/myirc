/*
** channel.h for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sun May 22 15:02:41 2016 
** Last update Fri Jun  3 17:27:42 2016 
*/

#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "handle_client.h"
#include "list.h"

#define DEBUG 0

typedef struct s_handle_client t_handle_client;

typedef struct	s_chan
{
  char		*_name;
  char		*_topic;
  t_list	*_users;
  int		(*is_already_in_chan)(struct s_chan *this, char *nickname);
  void		(*list_users)(struct s_chan *this, t_handle_client *client);
  char		*(*get_list_users)(struct s_chan *this);
  void		(*send_msg_to_users)(struct s_chan *this, char *msg);
}		t_chan;

void	chan_init(t_chan *this, char *name);
void	chan_destroy(t_chan *this);
void	chan_error(t_chan *this,
		   const char *func,
		   const char *file,
		   int line);
void	chan_warning(t_chan *this,
		     const char *func,
		     const char *file,
		     int line);
int	chan_is_already_in_chan(t_chan *this, char *nickname);
void	chan_list_users(t_chan *this, t_handle_client *client);
char	*chan_get_list_users(t_chan *this);
void	chan_send_msg_to_users(t_chan *this, char *msg);

#endif /* !CHANNEL_H_ */
