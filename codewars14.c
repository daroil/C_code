// Memory model of `pyramid`:
// `pyramid` is a one-dimensional array containing the elements of a pyramid with `rows` levels,
// in direct succession from left to right, top to bottom
// Lyrics...
// Pyramids are amazing! Both in architectural and mathematical sense. If you have a computer, you can mess with pyramids even if you are not in Egypt at the time. For example, let's consider the following problem. Imagine that you have a pyramid built of numbers, like this one here:

//    /3/
//   \7\ 4 
//  2 \4\ 6 
// 8 5 \9\ 3
// Here comes the task...
// Let's say that the 'slide down' is the maximum sum of consecutive numbers from the top to the bottom of the pyramid. As you can see, the longest 'slide down' is 3 + 7 + 4 + 9 = 23

// Your task is to write a function that takes a pyramid representation as argument and returns its' largest 'slide down'. For example:

// * With the input `[[3], [7, 4], [2, 4, 6], [8, 5, 9, 3]]`
// * Your function should return `23`.
// By the way...
// My tests include some extraordinarily high pyramids so as you can guess, brute-force method is a bad idea unless you have a few centuries to waste. You must come up with something more clever than that.

// (c) This task is a lyrical version of the Problem 18 and/or Problem 67 on ProjectEuler.

#include <stdio.h>

int ft_highest_in_row(int row, int num_elements, const int pyramid[num_elements], int i)
{
  int high;
  int rowsize;

  rowsize = i+row;
  high = pyramid[i];
  printf ("highest before %d ",high);
  while (i <= rowsize-1)
  {
    if (high < pyramid[i])
      high = pyramid[i];
    i++;
  }
  printf ("highest %d ",high);
  return (high);
}

int pyramid_slide_down(int num_elements, const int pyramid[num_elements], int rows) {
  int sum;
  int i;
  int row;
    
  i = 0;
  sum = 0;
  row = 1;
  while (row <= rows)
  {
    sum += ft_highest_in_row(row,  num_elements, pyramid, i);
    i += row;
    row++; 
  }
  return sum;
}