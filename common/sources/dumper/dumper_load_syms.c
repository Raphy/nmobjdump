/*
** dumper_load_syms.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 19:48:29 2014 raphael defreitas
** Last update Thu Mar 13 20:23:52 2014 raphael defreitas
*/

#include	<elf.h>
#include	<stdlib.h>

#include	"defines.h"
#include	"dumper.h"
#include	"xfunctions.h"

static int	load_symbols(t_dumper *this, Elf64_Shdr *symtab)
{
  int		i;

  this->symnum = symtab->sh_size / sizeof(Elf64_Sym);
  this->syms = xmalloc((this->symnum + 1) * sizeof(Elf64_Sym));
  if (dumper_fseek(this, symtab->sh_offset) != RET_SUCCESS)
    return (RET_FAILURE);
  i = 0;
  while (i < this->symnum)
    {
      this->syms[i] = xmalloc(sizeof(Elf64_Sym));
      if (dumper_fread(this, this->syms[i], 1, sizeof(Elf64_Sym)) != 0)
        return (RET_FAILURE);
      i++;
    }
  this->syms[i] = NULL;
  return (RET_SUCCESS);
}

int		dumper_load_syms(t_dumper *this)
{
  Elf64_Shdr	*symtab;

  if (this->syms != NULL)
    return (RET_SUCCESS);
  if ((symtab = dumper_get_shdr_by_name(this, ".symtab")) == NULL)
    {
      fprintf(stderr, "Error on loading symbols: ");
      fprintf(stderr, "the section .symtab is not found\n");
      return (RET_FAILURE);
    }
  if (symtab->sh_size % sizeof(Elf64_Sym) != 0)
    {
      fprintf(stderr, "Error on loading symbols: ");
      fprintf(stderr, "the section size is weird...\n");
      return (RET_FAILURE);
    }
  return (load_symbols(this, symtab));
}
