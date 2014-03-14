/*
** opts_ctor.c for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/objdump/sources/opts
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Mar 14 02:51:42 2014 raphael defreitas
** Last update Fri Mar 14 03:10:06 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<string.h>

#include	"defines.h"
#include	"opts.h"
#include	"xfunctions.h"

static void	set_default_values(t_opts *this)
{
  this->file_headers = 0;
  this->full_contents = 0;
  this->files = NULL;
}

static int	parse_short_opts(t_opts *this, int ac, char **av)
{
  int		i;
  int		j;

  i = 0;
  while (++i < ac)
    {
      if (av[i][0] == '-' && av[i][1] != '-')
	{
	  j = 0;
	  while (av[i][++j])
	    {
	      if (av[i][j] == 's')
		this->full_contents = 1;
	      else if (av[i][j] == 'f')
		this->file_headers = 1;
	      else
		{
		  fprintf(stderr, "Unknown parameter: -%c\n", av[i][j]);
		  return (RET_FAILURE);
		}
	    }
	}
    }
  return (RET_SUCCESS);
}

static int	parse_long_opts(t_opts *this, int ac, char **av)
{
  int		i;

  i = 0;
  while (++i < ac)
    {
      if (av[i][0] == '-' && av[i][1] == '-')
	{
	  if (strcmp(av[i] + 2, "full-contents") == 0)
	    this->full_contents = 1;
	  else if (strcmp(av[i] + 2, "file-headers") == 0)
	    this->file_headers = 1;
	  else
	    {
	      fprintf(stderr, "Unknown parameter: --%s\n", av[i] + 2);
	      return (RET_FAILURE);
	    }
	}
    }
  return (RET_SUCCESS);
}

static int	parse_file_opts(t_opts *this, int ac, char **av)
{
  int		i;
  int		count;
  int		j;

  count = 0;
  i = 0;
  while (++i < ac)
    if (av[i][0] != '-')
      count++;
  j = 0;
  i = 0;
  this->files = xmalloc((count + 1) * sizeof(char *));
  while (++i < ac)
    {
      if (av[i][0] != '-')
	{
	  this->files[j] = strdup(av[i]);
	  j++;
	}
    }  
  this->files[j] = NULL;
  return (RET_SUCCESS);
}

int		opts_ctor(t_opts *this, int ac, char **av)
{
  set_default_values(this);
  if (parse_long_opts(this, ac, av) != RET_SUCCESS ||
      parse_short_opts(this, ac, av) != RET_SUCCESS ||
      parse_file_opts(this, ac, av) != RET_SUCCESS)
    {
      return (RET_FAILURE);
    }
      
  return (RET_SUCCESS);
}
