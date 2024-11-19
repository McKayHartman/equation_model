#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int productOfDigits(int num)
{
	int product = 1; 
  
    while (num != 0)  
    { 
        product = product * (num % 10); 
        num = num / 10; 
    } 
  
    return product; 
}


int find()
{
	// variables
	int aZero = 1;

	// finds aZero
	while(aZero < 1000000000)
	{
		bool dualNums = false;
		int runs = 0;
		int prev = 0;
		int current;

		while(dualNums == false)
		{
			// edge case for the first time it runs
			if(runs == 0)
			{
				current = aZero;
			}
			// This case runs every other time
			else
			{
				// Here's the equation!
				//aN = aN-1 + f(n)
				current = prev + productOfDigits(prev);
			}
			

			// This checks if the previous value is equal to the current value
			if(prev == current)
			{
				dualNums = true;
			}

			// This checks if the equation has been solved 20,000 times, 
			// without a repeated value
			if(runs == 20000)
			{
				// found a good match
				return aZero;
			}

			// increments the number of times it has run
			runs++;

			// sets the previous value to the current value
			prev = current;
		}
		// Increment aZero
		aZero++;
	}
	// return failure
	return -1;
}
int main()
{
	int result = find();

	if(result == -1)
	{
		printf("\n Did not find a candidate.");
		return 1;
	}
	else
	{
		printf("aZero = %d does not repeat for 20,000 iterations.", result);
		return 1;
	}
}
