// In this little assignment you are given a string of space separated numbers, and have to return the highest and lowest number.

// Examples
// high_and_low("1 2 3 4 5")  // return "5 1"
// high_and_low("1 2 -3 4 5") // return "5 -3"
// high_and_low("1 9 3 4 -5") // return "9 -5"
// high_and_low("1 2 3 4 5", result)  // result "5 1"
// high_and_low("1 2 -3 4 5", result) // result "5 -3"
// high_and_low("1 9 3 4 -5", result) // result "9 -5"
// Notes
// All numbers are valid Int32, no need to validate them.
// There will always be at least one number in the input string.
// Output string must be two numbers separated by a single space, and highest number is first.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_isnum(char c)
{
  if (c >= '0' && c <= '9')
    return(1);
  return(0);
}

int ft_isminus(char c)
{
  if (c == '-')
    return(1);
  return(0);
}

int ft_is_space(char c)
{
  if (c == ' ')
    return(1);
  return(0);
}

int ft_number_count(const char *str)
{
  int size;
  int i;
  
  size = 0;
  i = 0;
  while (str[i] != '\0')
  {
    if (ft_isnum(str[i]) && !ft_isnum(str[i+1]))
      size++;    
    i++;    
  }
  return (size);
}

int *ft_create_arr(const char *strnum)
{
  int *int_arr;
  int i;
  int j;
  int number;
  int minus_counter;
  
  i = 0;
  j = 0;
  minus_counter = 1;
  int_arr = malloc(ft_number_count(strnum) * sizeof(int));
  while (strnum[i] != '\0')
  {
    if(ft_isminus(strnum[i]))
      minus_counter = -1;
    
    if(ft_isnum(strnum[i]))
    {  
      number = 0;
      while(ft_isnum(strnum[i]))
      {
        number = number * 10 + (strnum[i] - '0');
        i++;
      }
      number *= minus_counter;
      int_arr[j] = number;
      j++;
    }
    if (ft_is_space(strnum[i]))
      minus_counter = 1;
    i++;
  }
  return(int_arr);
}

int ft_find_max(int *arr, int length)
{
  int max;
  int i;
  
  i = 0;
  max = arr[i];
  while (i < length)
  {
    if (max < arr[i])
      max = arr[i];
    i++;
  }
  return (max);
}

int ft_find_min(int *arr, int length)
{
  int min;
  int i;
  
  i = 0;
  min = arr[i];
  while (i < length)
  {
    if (min > arr[i])
      min = arr[i];
    i++;
  }
  return (min);
}

void high_and_low (const char *strnum, char *result)
{
  int max;
  int min;
  int *int_arr;
  int length;
  
  int_arr = ft_create_arr(strnum); 
  length = ft_number_count(strnum);
  max = ft_find_max(int_arr, length);
  min = ft_find_min(int_arr, length);
	sprintf(result, "%d %d", max, min);
}