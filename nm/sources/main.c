/*
** main.c for nm in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/nm/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Mar 11 11:34:37 2014 raphael defreitas
** Last update Sat Mar 15 19:32:34 2014 raphael defreitas
*/

#include	<elf.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"defines.h"
#include	"dumper.h"
#include	"xfunctions.h"

void		sort_symbols(t_dumper *dumper);
char		get_symbol_type(t_dumper *dumper, Elf64_Sym *sym);

static void	display_symbol(t_dumper *dumper, Elf64_Sym *sym)
{
  const char	*name;
  char		type;
  Elf64_Shdr	*shdr;

  name = dumper_get_sym_name(dumper, sym);
  shdr = dumper_get_shdr_by_index(dumper, sym->st_shndx);
  type = get_symbol_type(dumper, sym);
  if (name[0] == '\0' || ELF64_ST_TYPE(sym->st_info) == STT_FILE)
    return ;
  if (type == 'U' || type == 'w')
    printf("%s", "                ");
  else
    printf("%016lx", sym->st_value);
  printf(" %c %s\n", type, name);
}

static int	load_dumper(t_dumper *dumper, const char *file)
{
 if (dumper_ctor(dumper, file) != RET_SUCCESS ||
     dumper_load(dumper) != RET_SUCCESS ||
     dumper_load_shdrs(dumper) != RET_SUCCESS ||
     dumper_load_shdr_names(dumper) != RET_SUCCESS ||
     dumper_load_syms(dumper) != RET_SUCCESS ||
     dumper_load_sym_names(dumper) != RET_SUCCESS)
    {
      dumper_dtor(dumper);
      return (RET_FAILURE);
    }
 return (RET_SUCCESS);
}

static void	my_nm(const char *file, int display_file)
{
  t_dumper	d;
  int		i;
  Elf64_Sym	*sym;

  if (load_dumper(&d, file) != RET_SUCCESS)
    return ;
  if (display_file)
    printf("%s:\n", file);
  sort_symbols(&d);
  i = 1;
  while ((sym = dumper_get_sym_by_index(&d, i)))
    {
      display_symbol(&d, sym);
      i++;
    }
  dumper_dtor(&d);
}

int		main(int argc, char **argv)
{
  int		i;
  int		display_file;

  display_file = (argc > 2);
  i = 1;
  while (i < argc)
    {
      if (i == 1 && i + 1 < argc)
	printf("\n");
      my_nm(argv[i], display_file);
      if (i + 1 < argc)
	printf("\n");
      i++;
    }
  if (i == 1)
    my_nm("a.out", 0);
  return (EXIT_SUCCESS);
}
