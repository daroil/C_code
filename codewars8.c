// Don't give me five!
// In this kata you get the start number and the end number of a region and should return the count of all numbers except numbers with a 5 in it. The start and the end number are both inclusive!

// Examples:

// 1,9 -> 1,2,3,4,6,7,8,9 -> Result 8
// 4,17 -> 4,6,7,8,9,10,11,12,13,14,16,17 -> Result 12
// The result may contain fives. ;-)
// The start number will always be smaller than the end number. Both numbers can be also negative!

// I'm very curious for your solutions and the way you solve it. Maybe someone of you will find an easy pure mathematics solution.

// Have fun coding it and please don't forget to vote and rank this kata! :-)

// I have also created other katas. Take a look if you enjoyed this kata!

int checkNumber(int number)
{
  int tmp;
  int count_in;
  int count_out;
  
  count_in = 0;
  count_out = 0;
  while (number != 0)
    {
      tmp = number % 10;
      number = number / 10;
      if (tmp != 5 && tmp != -5)
        count_in++;
      count_out++;
    }
  if(count_in == count_out)
    return(1);
  return (0);
}

int dontGiveMeFive(int start, int end)
{
  int count;
  
  count = 0;
  while(start != end)
  {
    if (checkNumber(start))
      count++;
    start++;
  }
  if (checkNumber(end))
      count++;
  return (count);
}
