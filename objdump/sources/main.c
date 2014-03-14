/*
** main.c for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/objdump/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Mar 11 11:36:14 2014 raphael defreitas
** Last update Fri Mar 14 03:09:16 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"opts.h"

int		main(int argc, char **argv)
{
  t_opts	opts;

  opts_ctor(&opts, argc, argv);
  return (EXIT_SUCCESS);
}
