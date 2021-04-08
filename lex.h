#ifndef LEX
#define LEX

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

//potentially make use of lex?
	//would be kinda sick to learn actually

//takes the list to output to and the string input
int lex(char out[][MAX_NUM_SIZE], char *in)
{
	in[strcspn(in, "\n")] = 0; //removes new line

	char tmp[MAX_NUM_SIZE];
	int pos = 0;
	int tokens_count = 0;

	for (int i = 0; i < strlen(in); i++) { //strlen call might not be efficient
		if (in[i] == ' ') {
			if (strcmp(tmp, "") == 0) {continue;} //handling two spaces
			strcpy(out[tokens_count], tmp);
			tokens_count++;
			memset(tmp, 0, strlen(tmp)); //resets string
			strcpy(tmp, "");
			pos = 0;
		} else if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '(' || in[i] == ')') {
			//that statemnet is not great rip (could be done by checking a list but you know
			if (strcmp(tmp, "") != 0) { //handle space before number
				strcpy(out[tokens_count], tmp);
				tokens_count++;
				memset(tmp, 0, strlen(tmp));
				pos = 0;
			}
			out[tokens_count][0] = in[i];
			out[tokens_count][1] = '\0';
			tokens_count++;
		} else {
			tmp[pos] = in[i];
			pos++;
		}
	}

	//sometimes there are trailing newlines
	if (!msc(tmp, "")) {
		strcpy(out[tokens_count], tmp);
		tokens_count++;
	}

	return tokens_count;
}

#endif
