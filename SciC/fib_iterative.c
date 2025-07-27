#include <stdio.h>
#include <stdlib.h>
#include "integers.h"
int_i* fact;
char buffer[20];
int_i* fibonacci(int);
_Bool memorySweeper=0, printTrace=0;
int main() {
    int n;
    printf("Please enter the upper bound:\n");
    scanf("%d",&n);
    if(n>5) {
		printf("Do you want the entire series?\nWarning: Printing in the integers library is O(n). Y/N:\n");
		char choice;
		fgets(buffer, 20, stdin);
		scanf("%c",&choice);
		if (choice=='y'||choice=='Y') printTrace=1;
		else printTrace=0;
		memorySweeper=1;
    }
    if (memorySweeper) {
		fact=(int_i*)malloc(sizeof(int_i)*3);
		for (int i=0; i<3; i++) {
			fact[i].len=0;
		}
		fact[0]=parseInt(0);
		fact[1]=parseInt(1);
		printf_i(fibonacci(n));
    } else {
    fact = (int_i*)malloc(sizeof(int_i)*n);
    for (int i=0; i<n; i++) {
        fact[i].len=0;
    }
    fact[0]=parseInt(0);
    fact[1]=parseInt(1);
    for (int i=1; i<=n; i++) {
        printf_i(fibonacci(i));
    	}
    } 
}
int_i* fibonacci(int n) {
	if (memorySweeper) {
		if (n==1) {
			int_i trivialReturn=parseInt(0);
			return &trivialReturn;
		}
		else if (n==2) {
			int_i trivialReturn=parseInt(1);
			return &trivialReturn;
		}
		else {
			for(int i=2; i<n; i++) {
				fact[2]=add_i(&fact[1],&fact[0]);
				free(fact[0].digits);
				fact[0]=fact[1];
				fact[1]=fact[2];
				if (printTrace) printf_i(&fact[2]);
			}
			return &fact[2];
		}
	} else {
    if (fact[n-1].len==0) {
    	fact[n-1]=add_i(&fact[n-2],&fact[n-3]);
    	
		return &fact[n-1];
    	} else return &fact[n-1];
	}
}
