#include <stdio.h>
#include <string.h>
#include "lex.h"
#include "constants.h"
#include "parse.h"
#include "rpn.h"

int main()
{
	char test_str[100];
	fgets(test_str, sizeof(test_str), stdin);
	char out[100][MAX_NUM_SIZE];
	int am = lex(out, test_str);
	char rpn_arr[100][MAX_NUM_SIZE];
	int size = parse(rpn_arr, out, am);
	printf("rpn is: ");
	print_arr(rpn_arr, size);
	int rpn_out = rpn(rpn_arr, size);
	printf("ans: %d \n", rpn_out);
	return 0;
}
