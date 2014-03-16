/*
** main.c for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/objdump/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Mar 11 11:36:14 2014 raphael defreitas
** Last update Fri Mar 14 17:31:24 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"defines.h"
#include	"opts.h"

int		my_objdump(t_opts *opts);

static void	usage()
{
  printf("Usage: ./my_objdump [OPTION] <file> [<file> ...]\n");
  printf("-h, --help           Display this information\n");
  printf("-f, --file-headers   Display the contents of the file header\n");
  printf("-s, --full-contents  Display the full contents of all sections\n");
}

int		main(int argc, char **argv)
{
  t_opts	opts;

  if (opts_ctor(&opts, argc, argv) != RET_SUCCESS)
    {
      usage();
      opts_dtor(&opts);
      return (EXIT_FAILURE);
    }
  if (opts_opt_help(&opts))
    {
      usage();
      opts_dtor(&opts);
      return (EXIT_SUCCESS);
    }
  if (my_objdump(&opts) != RET_SUCCESS)
    {
      opts_dtor(&opts);
      return (EXIT_FAILURE);
    }
  opts_dtor(&opts);
  return (EXIT_SUCCESS);
}
