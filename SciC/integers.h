#ifndef INTEGERS_H
#define INTEGERS_H
typedef struct Int_i {
	int* digits;
	int len;
} int_i;

void printf_i(int_i* num);
int_i add_i(int_i* num1,int_i* num2);
int_i parseInt(int num);
int_i parseIntFromString(char* num);
#endif
