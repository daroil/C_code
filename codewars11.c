// Enough is enough!
// Alice and Bob were on a holiday. Both of them took many pictures of the places they've been, and now they want to show Charlie their entire collection. However, Charlie doesn't like these sessions, since the motive usually repeats. He isn't fond of seeing the Eiffel tower 40 times. He tells them that he will only sit during the session if they show the same motive at most N times. Luckily, Alice and Bob are able to encode the motive as a number. Can you help them to remove numbers such that their list contains each number only up to N times, without changing the order?

// Task
// Given a list and a number, create a new list that contains each number of lst at most N times without reordering. For example if the input number is 2, and the input list is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times, and then take 3, which leads to [1,2,3,1,2,3]. With list [20,37,20,21] and number 1, the result would be [20,37,21].

// For C:

// Assign the return array length to the pointer parameter *szout.
// Do not mutate the input array.

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
//  return a dynamically allocated int array
//  the return array will be freed by tester
//  set *szout to the length of output array

int checkForNumber(int number, int *array, int count, int size)
{
  int i;
  int counter;
  
  i = 0;
  counter = 0;
  while (i <= size)
  {
    if (counter >= count)
      return(0);
    if (number == array[i])
      counter++;
    i++;
  }
 
  return(1);
}


int *delete_nth(size_t szin, int order[szin], int max_e, size_t *szout) 
{
  int     *array;
  size_t  i;
  size_t  j;
  
  i = 0;
  j = 0;
  array = malloc(szin * sizeof(size_t));
  while (i < szin)
  {
    if (checkForNumber(order[i], array, max_e, j))
    {
      array[j] = order[i];
      j++;
    }
    i++;
  }
  szout[0] = j;
  return(array);
}