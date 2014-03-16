/*
** my_objdump.c for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/objdump/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Mar 14 17:28:51 2014 raphael defreitas
** Last update Sun Mar 16 04:01:23 2014 raphael defreitas
*/

#include	<elf.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"defines.h"
#include	"dumper.h"
#include	"opts.h"
#include	"xfunctions.h"

void		print_section_contents(Elf64_Shdr *s, const unsigned char *d);
void		print_header(t_dumper *dumper);

static const char	*get_file_format(t_dumper *dumper)
{
  return ("elf64-x86-64");
}

static int	is_displayable(t_dumper *dumper, Elf64_Shdr *shdr)
{
  const char	*n;

  n = dumper_get_shdr_name(dumper, shdr);
  if (shdr->sh_size == 0)
    return (0);
  if (shdr->sh_type == SHT_NOBITS)
    return (0);
  if (shdr->sh_type == SHT_PROGBITS || shdr->sh_type == SHT_NOTE)
    return (1);
  if ((shdr->sh_flags & SHF_ALLOC) == SHF_ALLOC ||
      (shdr->sh_flags & SHF_STRINGS) == SHF_STRINGS)
    return (1);
  return (0);
}

static void	print_sections(t_dumper *dumper)
{
  Elf64_Shdr	*shdr;
  int		i;
  unsigned char	*data;

  i = 0;
  while ((shdr = dumper_get_shdr_by_index(dumper, i)))
    {
      if (is_displayable(dumper, shdr))
	{
	  printf("Contents of section %s:\n",
		 dumper_get_shdr_name(dumper, shdr));
	  data = xmalloc(shdr->sh_size);
	  if (dumper_fseek(dumper, shdr->sh_offset) == RET_SUCCESS &&
	      dumper_fread(dumper, data, 1, shdr->sh_size) == RET_SUCCESS)
	      print_section_contents(shdr, data);
	  free(data);
	}

      i++;
    }
}

int		my_objdump(t_opts *opts)
{
  int		i;
  const char	*filename;
  t_dumper	d;

  i = 0;
  while ((filename = opts_opt_file_by_index(opts, i)))
    {
      if (dumper_ctor(&d, filename) == RET_SUCCESS &&
	  dumper_load(&d) == RET_SUCCESS)
	{
	  printf("\n%s:     file format %s\n", filename, get_file_format(&d));
	  if (opts_opt_file_headers(opts))
	    print_header(&d);
	  if (opts_opt_full_contents(opts))
	    {
	      printf("\n");
	      print_sections(&d);
	    }
	  dumper_dtor(&d);
	}
      else
	dumper_dtor(&d);
      i++;
    }
  return (RET_SUCCESS);
}
