/*
** symbol_char.c for nm in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/nm/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 22:12:31 2014 raphael defreitas
** Last update Fri Mar 14 02:34:17 2014 raphael defreitas
*/

#include	<elf.h>
#include	<ctype.h>
#include	<stdlib.h>
#include	<string.h>

#include	"dumper.h"

char		with_shdr(t_dumper *dumper, Elf64_Sym *sym)
{
  Elf64_Shdr	*shdr;

  if ((shdr = dumper_get_shdr_by_index(dumper, sym->st_shndx)) == NULL)
    return ('\0');
  if (shdr->sh_type == SHT_NOBITS)
    return ('b');
  if ((shdr->sh_flags & SHF_WRITE) != SHF_WRITE
      && (shdr->sh_flags & SHF_EXECINSTR) != SHF_EXECINSTR)
    return ('r');
  if ((shdr->sh_flags & SHF_ALLOC) != SHF_ALLOC ||
      strcmp(".data", dumper_get_shdr_name(dumper, shdr)) == 0 ||
      shdr->sh_type == SHT_DYNAMIC ||
      (shdr->sh_type == SHT_PROGBITS
       && ELF64_ST_TYPE(sym->st_info) == STT_OBJECT))
    return ('d');
  if (shdr->sh_type == SHT_INIT_ARRAY)
    return ('t');
  return ('\0');
}

char		symbol_char(t_dumper *dumper, Elf64_Sym *sym)
{
  int		bind;
  int		type;
  int		c;

  bind =  ELF64_ST_BIND(sym->st_info);
  type =  ELF64_ST_TYPE(sym->st_info);
  if (sym->st_shndx == SHN_ABS)
    return (bind == STB_GLOBAL ? 'A' : 'a');
  if (sym->st_shndx == SHN_COMMON)
    return ('C');
  if (bind == STB_WEAK)
    return (sym->st_shndx == SHN_UNDEF ? 'w' : 'W');
  if (sym->st_shndx == SHN_UNDEF)
    return ('U');
  if ((c = with_shdr(dumper, sym)) != '\0')
    return (bind == STB_GLOBAL ? toupper(c) : c);
  if (type == STT_FUNC || type == STT_OBJECT)
    return (bind == STB_GLOBAL ? 'T' : 't');
  return ('?');
}
