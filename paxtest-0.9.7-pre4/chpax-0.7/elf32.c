/*
** elf32.c for chpax
**
** The PaX project : http://pax.grsecurity.net/
**
*/
#include "chpax.h"


unsigned long   get_flags_elf()
{
  u_long              flags;
   
  flags = ((u_long) header_elf.e_ident[EI_PAX + 1] << 8) + (u_long) header_elf.e_ident[EI_PAX];
  return (flags);
}

void             put_flags_elf(unsigned long flags)
{
  header_elf.e_ident[EI_PAX]     = (flags & 0xFF);
  header_elf.e_ident[EI_PAX + 1] = ((flags >> 8) & 0xFF);
}
