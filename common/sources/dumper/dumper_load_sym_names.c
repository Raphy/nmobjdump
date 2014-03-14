/*
** dumper_load_sym_names.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 19:24:41 2014 raphael defreitas
** Last update Thu Mar 13 20:03:35 2014 raphael defreitas
*/

#include	<elf.h>
#include	<stdlib.h>

#include	"defines.h"
#include	"dumper.h"
#include	"xfunctions.h"

int		dumper_load_sym_names(t_dumper *this)
{
  Elf64_Shdr	*shdr;

  if ((shdr = dumper_get_shdr_by_name(this, ".strtab")) == NULL)
    {
      fprintf(stderr, "symbol string table not found\n");
      return (RET_FAILURE);
    }
  this->sym_names = xmalloc(shdr->sh_size);
  if (dumper_fseek(this, shdr->sh_offset) != RET_SUCCESS ||
      dumper_fread(this, this->sym_names, 1, shdr->sh_size) != RET_SUCCESS)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
