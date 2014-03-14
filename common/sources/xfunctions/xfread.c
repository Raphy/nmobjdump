/*
** xfread.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/xfunctions
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Mar 12 20:48:51 2014 raphael defreitas
** Last update Thu Mar 13 19:03:06 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<stdio.h>

size_t		xfread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t	ret;

  ret = fread(ptr, size, nmemb, stream);
  if ((size == 1 && ret < size) || ret < 1)
    {
      fprintf(stderr, "fread() failed! Bye!");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
