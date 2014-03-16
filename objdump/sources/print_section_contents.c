/*
** print_section.c for objdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump/objdump/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Mar 16 02:01:15 2014 raphael defreitas
** Last update Sun Mar 16 04:01:42 2014 raphael defreitas
*/

#include	<elf.h>
#include	<stdio.h>
#include	<unistd.h>

static int	get_max_width(Elf64_Shdr *shdr)
{
  int		width;
  size_t	l;

  l = 0;
  while (l < shdr->sh_size)
    l += 0x10;
  l += isatty(fileno(stdout)) ? 0x0 : shdr->sh_addr;
  width = 1;
  while ((l = l / 16) > 0)
    width++;
  return (width < 4 ? 4 : width);
}

void		print_section_contents(Elf64_Shdr *shdr, const unsigned char *d)
{
  size_t	l;
  size_t	c;
  int		width;

  width = get_max_width(shdr);
  l = 0;
  while (l < shdr->sh_size)
    {
      printf(" %0*lx", width, isatty(fileno(stdout)) ? l : shdr->sh_addr + l);
      c = -1;
      while (++c < 16 && l + c < shdr->sh_size)
        printf("%s%02x", c % 4 == 0 ? " " : "", d[l + c]);
      while (c < 16)
        printf("  %s", c++ % 4 == 0 ? " " : "");
      printf("  ");
      c = -1;
      while (++c < 16 && l + c < shdr->sh_size)
        printf("%c", d[l + c] >= ' ' && d[l + c] <= '~' ? d[l + c] : '.');
      while (c < 16)
        printf("%c", (c = c + 1) ? ' ' : ' ');
      printf("\n");
      l += 0x10;
    }
}
