#include <stdio.h>
#include <stdlib.h>
#include "integers.h"
int main() {
	int_i x,y;
	x.len=2;
	y.len=3;
	x.digits=malloc(sizeof(int)*2);
	y.digits=malloc(sizeof(int)*3);
	y.digits[0]=9,y.digits[1]=4,y.digits[2]=9;
	x.digits[0]=9,x.digits[1]=7;
	int_i sum = add_i(&x,&y);
	printf_i(&sum);
	int_i myNum = parseInt(43276743);
	printf_i(&myNum);
	printf("Now, time for a very very long number\n");
	int_i longerThanLong = parseIntFromString("3473984735647634092848350999249873409762937457648975");
	printf_i(&longerThanLong);
	int_i temp=parseInt(200);
	int_i sum2 = add_i(&longerThanLong,&temp);
	printf_i(&sum2);
}
 
