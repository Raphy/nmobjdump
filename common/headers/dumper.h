/*
** dumper.h for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/common/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Thu Mar 13 17:41:44 2014 raphael defreitas
** Last update Thu Mar 13 20:21:20 2014 raphael defreitas
*/

#ifndef		DUMPER_H_
# define	DUMPER_H_

# include	<elf.h>
# include	<stdio.h>

typedef	struct
{
  char		*filename;
  FILE		*stream;
  Elf64_Ehdr	*ehdr;
  Elf64_Shdr	**shdrs;
  Elf64_Sym	**syms;
  int		symnum;
  char		*shdr_names;
  char		*sym_names;
}		t_dumper;

int		dumper_ctor(t_dumper *this, const char *filename);
void		dumper_dtor(t_dumper *this);

int		dumper_fseek(t_dumper *this, long offset);
int		dumper_fread(t_dumper *this, void *ptr, size_t s, size_t nm);

int		dumper_load(t_dumper *this);
int		dumper_load_shdrs(t_dumper *this);
int		dumper_load_shdr_names(t_dumper *this);
int		dumper_load_syms(t_dumper *this);
int		dumper_load_sym_names(t_dumper *this);

/*
const char	*dumper_get_filename(t_dumper *this);
FILE		*dumper_get_stream(t_dumper *this);

Elf64_Ehdr	*dumper_get_ehdr(t_dumper *this);
*/

Elf64_Shdr	**dumper_get_shdrs(t_dumper *this);
Elf64_Shdr	*dumper_get_shdr_by_index(t_dumper *this, int index);
Elf64_Shdr	*dumper_get_shdr_by_name(t_dumper *this, const char *name);
const char	*dumper_get_shdr_name(t_dumper *this, Elf64_Shdr *shdr);

Elf64_Sym	**dumper_get_syms(t_dumper *this);
Elf64_Sym	*dumper_get_sym_by_index(t_dumper *this, int index);
Elf64_Sym	*dumper_get_sym_by_name(t_dumper *this, const char *name);
const char	*dumper_get_sym_name(t_dumper *this, Elf64_Sym *sym);

#endif /* !DUMPER_H_*/
