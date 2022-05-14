// In this example you have to validate if a user input string is alphanumeric. The given string is not nil/null/NULL/None, so you don't have to check that.

// The string has the following conditions to be alphanumeric:

// At least one character ("" is not valid)
// Allowed characters are uppercase / lowercase latin letters and digits from 0 to 9
// No whitespaces / underscore



#include <stdbool.h>

int ft_is_char_or_num(char c)
{
  if (c >= '0' && c <= '9')
    return(1);
  if (c >= 'a' && c <= 'z')
    return(1);
  if (c >= 'A' && c <= 'Z')
    return(1);
  return(0);
}

bool alphanumeric(const char* strin) 
{
  int i;
  
  i = 0;
  if (strin[i] == '\0')
    return(false);
  while (strin[i] != '\0')
  {
    if (!ft_is_char_or_num(strin[i]))
      return (false);
    i++;
  }
  return (true);
}