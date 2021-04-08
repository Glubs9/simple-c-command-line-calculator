#include <stdlib.h>
#include "constants.h"

int rpn(char toks_in[][MAX_NUM_SIZE], int size) 
{
	 int stack[size];
	 int head = 0;

	 //check if - and / are the right way round
	 for (int i = 0; i < size; i++) {
		if (msc(toks_in[i],"+")) { stack[head-1] = stack[head-1] + stack[head]; head--; }
		else if (msc(toks_in[i],"-")) { stack[head-1] = stack[head-1] - stack[head]; head--; }
		else if (msc(toks_in[i],"*")) { stack[head-1] = stack[head-1] * stack[head]; head--; }
		else if (msc(toks_in[i],"/")) { stack[head-1] = stack[head-1] / stack[head]; head--; }
		else {
			head++;
			stack[head] = atoi(toks_in[i]);
		}
	 }

	 return stack[head]; //ehhhhhhh, maybe something else?
}
