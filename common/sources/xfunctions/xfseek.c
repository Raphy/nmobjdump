/*
** xfseek.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/xfunctions
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Mar 12 20:51:37 2014 raphael defreitas
** Last update Wed Mar 12 21:02:56 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<stdio.h>

int		xfseek(FILE *stream, long offset, int whence)
{
  if (fseek(stream, offset, whence) < 0)
    {
      fprintf(stderr, "fseek() failed! Bye!");
      exit(EXIT_FAILURE);
    }
  return (0);
}
