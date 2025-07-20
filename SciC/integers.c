//cseiitb

#include <stdio.h>
#include <stdlib.h>
#include "integers.h"
// typedef struct Int_i{
// 	int* digits;
// 	int len;
// } int_i;
void printf_i(int_i* num) {
	for(int i=0; i<num->len; i++) {
		printf("%d",num->digits[i]); //big endian storage
	}
	printf("\n");
}
int_i parseInt(int num) {
	if (num==0) {
		int_i newInt;
		newInt.digits=(int*)malloc(sizeof(int));
		newInt.digits[0]=0;
		newInt.len=1;
		return newInt;
	}
	int numberOfDigits=0; 
	int pres=num;
	while (pres!=0) {
		numberOfDigits++;
		pres/=10;
	}
	int_i newInt;
	newInt.len=numberOfDigits;
	newInt.digits=(int*)malloc(sizeof(int)*newInt.len);
	for (int i=newInt.len-1; i>=0; i--) {
		newInt.digits[i]=num%10;
		num/=10;
	}
	return newInt;
}
int_i parseIntFromString(char* num) {
	int_i newInt;
	newInt.len=0;
	for (int i=0; num[i]!='\0'; i++) {
		newInt.len++;
	}
	newInt.digits=(int*)malloc(sizeof(int)*newInt.len);
	for (int i=0; i<newInt.len; i++) {
		newInt.digits[i]=((int)num[i]-48);
	}
	return newInt;
}
int_i add_i(int_i* num1,int_i* num2) {
	int_i sum; 
	sum.len=(num1->len>num2->len)?num1->len:num2->len;
	sum.digits=(int*) calloc(sum.len,sizeof(int));
	int i=num1->len-1;
	int j=num2->len-1;
	int k=((num2->len>num1->len)?num2->len:num1->len)-1;
	int carry=0;
	while (i>=0 && j>=0) {
			sum.digits[k]=num1->digits[i--]+num2->digits[j--]+carry;
			carry=sum.digits[k]/10;
			sum.digits[k--]%=10;
	}
	if (i>=0) {
		while (i>=0) {
			sum.digits[k]=num1->digits[i--]+carry;
			carry=sum.digits[k]/10;
			sum.digits[k--]%=10;
		}
	} else if(j>=0) {
		while (j>=0) {
			sum.digits[k]=num2->digits[j--]+carry;
			carry=sum.digits[k]/10;
			sum.digits[k--]%=10;
		}
	}
	if(carry!=0) {
		sum.digits=(int*)realloc(sum.digits,(sum.len+1)*sizeof(int)); 
		for (int i=sum.len; i>0; i--) {
			sum.digits[i]=sum.digits[i-1];
		}
		sum.digits[0]=carry;
		sum.len+=1;
	}
	return sum;
}
