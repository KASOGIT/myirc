/*
** main.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/server
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu May 19 19:54:31 2016 
** Last update Sun May 29 01:37:10 2016 
*/

#include "server.h"

static void	usage()
{
  fprintf(stderr, "Usage: ./server port\n");
  exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
  t_server	server;

  if (ac != 2)
    usage();
  server_init(&server, atoi(av[1]));
  server.server_handle_client(&server);
  server_destroy(&server);
  return (0);
}
