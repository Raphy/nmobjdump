/*
** xmalloc.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/xfunctions
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Mar 12 13:15:39 2014 raphael defreitas
** Last update Thu Mar 13 18:56:43 2014 raphael defreitas
*/

#include	<stddef.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

void		*xmalloc(size_t size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      fprintf(stderr, "malloc() failed! Bye!");
      exit(EXIT_FAILURE);
    }
  memset(ptr, 0, size);
  return (ptr);
}
