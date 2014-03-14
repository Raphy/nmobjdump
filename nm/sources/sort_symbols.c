/*
** sort.c for nm in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/nm/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 21:22:28 2014 raphael defreitas
** Last update Fri Mar 14 02:31:07 2014 raphael defreitas
*/

#include	<elf.h>
#include	<ctype.h>

#include	<stdio.h>
#include	<string.h>

#include	"dumper.h"

static int	compare(t_dumper *dumper, Elf64_Sym *sym1, Elf64_Sym *sym2)
{
  const char	*name1;
  const char	*name2;
  int		i1;
  int		i2;

  name1 = dumper_get_sym_name(dumper, sym1);
  name2 = dumper_get_sym_name(dumper, sym2);
  i1 = 0;
  i2 = 0;
  while (name1[i1] && name2[i2])
    {
      while (name1[i1] && name1[i1] == '_')
	i1++;
      while (name2[i2] && name2[i2] == '_')
	i2++;
      if (tolower(name1[i1]) - tolower(name2[i2]) != 0)
	return (tolower(name1[i1]) - tolower(name2[i2]));
      i1++;
      i2++;
    }
  if (i2 > i1 && tolower(name1[i1]) == tolower(name2[i2]))
    return (1);
  return (tolower(name1[i1]) - tolower(name2[i2]));
}

static int	is_sorted(t_dumper *dumper)
{
  int		i;
  Elf64_Sym	*sym1;
  Elf64_Sym	*sym2;

  i = 0;
  while ((sym1 = dumper_get_sym_by_index(dumper, i)) &&
	 (sym2 = dumper_get_sym_by_index(dumper, i + 1)))
    {
      if (compare(dumper, sym1, sym2) > 0)
	return (0);
      i++;
    }
  return (1);
}

void		sort_symbols(t_dumper *dumper)
{
  int		i;
  Elf64_Sym	*sym1;
  Elf64_Sym	*sym2;

  while (!is_sorted(dumper))
    {
      i = 0;
      while ((sym1 = dumper_get_sym_by_index(dumper, i)) &&
	     (sym2 = dumper_get_sym_by_index(dumper, i + 1)))
	{
	  if (compare(dumper, sym1, sym2) > 0)
	    {
	      dumper->syms[i] = sym2;
	      dumper->syms[i + 1] = sym1;
	    }
	  i++;
	}
    }
}
