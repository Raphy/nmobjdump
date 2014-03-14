/*
** dumper_load.c for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/sources/dumper
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Mar 13 18:20:48 2014 raphael defreitas
** Last update Thu Mar 13 19:08:03 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"defines.h"
#include	"dumper.h"
#include	"xfunctions.h"

static int	load_ehdr(t_dumper *this)
{
  this->ehdr = xmalloc(sizeof(Elf64_Ehdr));
  if (fseek(this->stream, 0, SEEK_SET) == RET_ERROR)
    {
      perror("fseek");
      return (RET_FAILURE);
    }
  if (fread(this->ehdr, sizeof(Elf64_Ehdr), 1, this->stream) < 1)
    {
      perror("read");
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

static int	check_ident(t_dumper *this)
{
  if (strncmp((char *)this->ehdr->e_ident, ELFMAG, SELFMAG) != RET_SUCCESS)
    {
      fprintf(stderr, "File format not recognized: ");
      fprintf(stderr, "only ELF format supported\n");
      return (RET_FAILURE);
    }
  if (this->ehdr->e_ident[EI_CLASS] != ELFCLASS64)
    {
      fprintf(stderr, "File format not recognized: ");
      fprintf(stderr, "only 64 bits supported\n");
      return (RET_FAILURE);
    }
  if (this->ehdr->e_ident[EI_DATA] != ELFDATA2LSB)
    {
      fprintf(stderr, "File format not recognized: ");
      fprintf(stderr, "only little endian supported\n");
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

int		dumper_load(t_dumper *this)
{
  if (this->ehdr != NULL)
    return (RET_SUCCESS);
  else if (load_ehdr(this) == RET_FAILURE)
    return (RET_FAILURE);
  else if (check_ident(this) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
