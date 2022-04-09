/* Note:
    Allocate memory yourself!
*/

#include <stdlib.h>
#include <stdio.h>

int ft_size(const char *dna)
{
  int size;
  
  size = 0;
  while (dna[size] != '\0')
    size++;
  return(size);
}

char *dna_strand(const char *dna)
{
  char *comp_dna;
  int i;
  
  i=0;
  comp_dna = malloc(ft_size(dna));
  while (dna[i] != '\0')
  {
    if (dna[i] == 'A')
      comp_dna[i] = 'T';
    if (dna[i] == 'T')
      comp_dna[i] = 'A';
    if (dna[i] == 'C')
      comp_dna[i] = 'G';
    if (dna[i] == 'G')
      comp_dna[i] = 'C';
    i++;
  }
  comp_dna[i]='\0';
  return (comp_dna);
}