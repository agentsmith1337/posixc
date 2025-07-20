#include <stdio.h>
#include <stdlib.h>
#include "integers.h"
int_i* fact;
int_i* fibonacci(int);
int main() {
    int n;
    printf("Please enter the upper bound:\n");
    scanf("%d",&n);
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
int_i* fibonacci(int n) {
    if (fact[n-1].len==0) {
    fact[n-1]=add_i(&fact[n-2],&fact[n-3]);
	return &fact[n-1];
    } else return &fact[n-1];
}
