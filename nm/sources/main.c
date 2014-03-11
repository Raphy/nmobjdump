/*
** main.c for nm in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/nm/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Mar 11 11:34:37 2014 raphael defreitas
** Last update Tue Mar 11 11:58:01 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

int		main(int argc, char **argv)
{
  printf("%s with %d parameter%c\n", argv[0], argc, (argc > 1 ? 's' : '\0'));
  return (EXIT_SUCCESS);
}
