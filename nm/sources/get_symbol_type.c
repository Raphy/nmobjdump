/*
** get_symbol_type.c for nm in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/nm/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Mar 15 15:22:49 2014 raphael defreitas
** Last update Sat Mar 15 18:19:01 2014 raphael defreitas
*/

#include	<ctype.h>
#include	<elf.h>
#include	<stdlib.h>
#include	<string.h>

#include	"dumper.h"

static char	by_shdr_name(const char *name)
{
  if (strcmp(name, ".bss") == 0)
    return ('b');
  if (strcmp(name, ".code") == 0 || strcmp(name, ".fini") == 0 ||
      strcmp(name, ".init") == 0 || strcmp(name, ".text") == 0 ||
      strcmp(name, ".fini_array") == 0 || strcmp(name, ".init_array") == 0)
    return ('t');
  if (strcmp(name, ".data") == 0)
    return ('d');
  if (strcmp(name, ".debug") == 0)
    return ('N');
  if (strcmp(name, ".drectve") == 0 || strcmp(name, ".idata") == 0)
    return ('i');
  if (strcmp(name, ".edata") == 0)
    return ('e');
  if (strcmp(name, ".pdata") == 0)
    return ('p');
  if (strcmp(name, ".rdata") == 0 || strcmp(name, ".rodata") == 0)
    return ('r');
  if (strcmp(name, ".sbss") == 0)
    return ('s');
  if (strcmp(name, ".scommon") == 0)
    return ('c');
  if (strcmp(name, ".sdata") == 0)
    return ('g');
  return ('?');
}

static char	by_shdr_type_and_flags(Elf64_Shdr *shdr)
{
  if ((shdr->sh_flags & SHF_WRITE) != SHF_WRITE)
    {
      if (shdr->sh_type == SHT_GROUP)
	return ('n');
      return ('r');
    }
  if (shdr->sh_type == SHT_PROGBITS || shdr->sh_type == SHT_DYNAMIC)
    return ('d');
  return ('X');
}

static char	shndx_and_bind_and_type(Elf64_Sym *sym, int bind, int type)
{
  if (sym->st_shndx == SHN_COMMON)
    return ('C');
  if (sym->st_shndx == SHN_UNDEF)
    {
      if (bind == STB_WEAK)
	{
	  if (type == STT_OBJECT)
	    return ('v');
	  return ('w');
	}
      return ('U');
    }
  if (bind == STB_WEAK)
    {
      if (type == STT_OBJECT)
	return ('V');
      return ('W');
    }
  if (bind == STB_GNU_UNIQUE)
    return ('u');
  return ('?');
}

char		get_symbol_type(t_dumper *dumper, Elf64_Sym *sym)
{
  char		c;
  Elf64_Shdr	*shdr;
  int		bind;
  int		type;

  bind = ELF64_ST_BIND(sym->st_info);
  type = ELF64_ST_TYPE(sym->st_info);
  shdr = dumper_get_shdr_by_index(dumper, sym->st_shndx);
  if ((c = shndx_and_bind_and_type(sym, bind, type)) != '?')
    return (c);
  if (sym->st_shndx == SHN_ABS)
    c = 'a';
  else if (shdr)
    {
      c = by_shdr_name(dumper_get_shdr_name(dumper, shdr));
      if (c == '?')
	c = by_shdr_type_and_flags(shdr);
    }
  return (bind == STB_GLOBAL ? toupper(c) : c);
}
