#include <stdio.h>
#include <stdint.h>

uint64_t recursiveFib(int val)
{
   if (val <= 0)
   {
      printf("The input must be greater than 0.\n");
      return 0;
   }

   else if (val == 1)
   {
      return 0;
   }

   else if (val == 2)
   {
      return 1;
   }

   else
   {
      return recursiveFib(val - 1) + recursiveFib(val - 2);
   }
}

uint64_t iterativeFib(int val)
{
   uint64_t prevPrevNum = 0;
   uint64_t prevNum = 0;
   uint64_t currentNum = 1;

   for (int i = 2; i < val; i++)
   {
      prevPrevNum = prevNum;
      prevNum = currentNum;
      currentNum = prevPrevNum + prevNum;
   }

   return currentNum;
}

int main(int argc, char **argv)
{
   int num = 0;
   int input = atoi(argv[1]);
   uint64_t output = 0;
   FILE *fptr = fopen(argv[3], "r");
   fscanf(fptr, "%d", &num);
   fclose(fptr);

   if (argv[2][0] == 'r')
   {
      output = recursiveFib(input + num);
   }

   else if (argv[2][0] == 'i')
   {
      output = iterativeFib(input + num);
   }
   printf("%llu\n", output);
   return 0;
}
