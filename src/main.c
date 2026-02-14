#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

int parse_int(const char* str)
{
  int number = 0;
  // str -> 14 '\0'
  while(*str != '\0')
  {
    if (*str < '0' || *str > '9')
      return number;

    number = number * 10 + (*str - '0');
    str++;
  }
  return number;
}


int main(int argc, char ** argv)
{
  if(argc != 2)
  {
    printf("please input sleep number <sleep x>...\n");
    return 0;
  }

  int seconds = 0;
  seconds = parse_int(argv[1]);

  printf("sleep %d seconds...\n", seconds);
  //Sleep(seconds * 1000);


  return 0;
}