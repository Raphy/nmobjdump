/*
** xfunctions.h for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Wed Mar 12 13:14:04 2014 raphael defreitas
** Last update Wed Mar 12 20:48:37 2014 raphael defreitas
*/

#ifndef		XFUNCTIONS_H_
# define	XFUNCTIONS_H_

# include	<stdio.h>
# include	<stddef.h>

void		*xmalloc(size_t size);
size_t		xfread(void *ptr, size_t size, size_t nmemn, FILE *stream);
int		xfseek(FILE *stream, long offset, int whence);

#endif /* !XFUNCTIONS_H_*/
