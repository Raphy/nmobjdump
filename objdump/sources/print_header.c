/*
** print_header.c for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Mar 16 02:17:30 2014 raphael defreitas
** Last update Sun Mar 16 17:06:56 2014 raphael defreitas
*/

#include	"dumper.h"

static void	print_start_address(Elf64_Ehdr *ehdr)
{
  int		i;
  int		hexlen;
  size_t	addr;

  hexlen = 1;
  addr = ehdr->e_entry;
  while ((addr = addr >> 4))
    hexlen++;
  printf("start address 0x");
  i = -1;
  while (++i < 16 - hexlen)
    printf("0");
  printf("%lx\n", ehdr->e_entry);
}

static void	print_architecture(Elf64_Ehdr *ehdr)
{
  ehdr = (void *)ehdr;
  printf("architecture: %s, ", "i386:x86-64");
}

static size_t	get_flags(t_dumper *dumper)
{
  dumper = (void *)dumper;
  return (0);
}

static void	print_flags(t_dumper *dumper)
{
  size_t	flags;

  flags = get_flags(dumper);
  printf("flags 0x%08lx:\n", flags);
  printf("\n");
}

void		print_header(t_dumper *dumper)
{
  print_architecture(dumper->ehdr);
  print_flags(dumper);
  print_start_address(dumper->ehdr);
}
