#ifndef CONSTANTS
#define CONSTANTS

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int MAX_NUM_SIZE = 10;

void print_arr(char arr[][MAX_NUM_SIZE], int size) 
{
	for (int i = 0; i < size; i++) {
		printf("%s, ", arr[i]);
	}
	printf("\n");
}

//my string comp (it's like reverse for some reason, real wack)
bool msc(char *s1, char *s2) 
{
	return strcmp(s1, s2) == 0;
}

int is_operator(char *t) {
	return (msc(t,"+")||msc(t,"-")||msc(t,"*")||msc(t,"/"));
}

#endif
