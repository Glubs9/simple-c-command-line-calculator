#include <string.h>
#include <stdbool.h>
#include "constants.h"

//can't remember if higher or lower precedence is +
int precedence(char *test_in)
{
	if (msc(test_in, "(") || msc(test_in, ")")) {
		return 0;
	} else if (msc(test_in, "+") || msc(test_in, "-")) {
		return 1;
	} else if (msc(test_in, "*") || msc(test_in, "/")) {
		return 2;
	} else {
		perror("operator not sent to precedence finder \n");
		return -1;
	}
}

//function name a bit long (also it's not great)
int pop_less_precedence(char out[][MAX_NUM_SIZE], int *out_pos, char stack[][MAX_NUM_SIZE], int head, char *val)
{
	int p = precedence(val);
	while ((head > 0) && (precedence(stack[head]) > p)) {
		strcpy(out[*out_pos], stack[head]);
		(*out_pos)++;
		head--;
	}
	return head;
}

//takes in return array and array of maths tokens and the size and returns the size? (might not need to return, or return value)
	//code is pretty much verbaitim from wikipedia
int parse(char out[][MAX_NUM_SIZE], char toks[][MAX_NUM_SIZE], int size)
{
	char stack[size][MAX_NUM_SIZE]; //stack is a bit big but i think it's minimum size possible
	int size_out = 0;
	int stack_head = 0;

	for (int i = 0; i < size; i++) {
		//add bracket support
		if (msc(toks[i], "(")) {
			stack_head++;
			strcpy(stack[stack_head], toks[i]);
		} else if (msc(toks[i], ")")) {
			stack_head = pop_less_precedence(out, &size_out, stack, stack_head, ")");
			stack_head--;
		} else if (is_operator(toks[i])) {
			stack_head = pop_less_precedence(out, &size_out, stack, stack_head, toks[i]);
			stack_head++; //switch with below
			strcpy(stack[stack_head], toks[i]);
		} else {
			strcpy(out[size_out], toks[i]);
			size_out++;
		}
	}

	while (stack_head != 0) {
		strcpy(out[size_out], stack[stack_head]);
		size_out++;
		stack_head--;
	}

	return size_out;

}
