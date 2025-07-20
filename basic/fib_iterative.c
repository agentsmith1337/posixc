#include <stdio.h>
#define MAX 93
unsigned long long int fact[MAX];
unsigned long long fibonacci(int);
int main() {
    int n;
    printf("Please enter the upper bound:\n");
    scanf("%d",&n);
    for (int i=0; i<MAX; i++) fact[i]=-1;
    fact[0]=0;
    fact[1]=1;
    for (int i=1; i<=n; i++) {
        printf("%llu\t",fibonacci(i));
    }
}
unsigned long long int fibonacci(int n) {
    if (fact[n-1]==-1) {
    fact[n-1]=fact[n-2]+fact[n-3];
	return fact[n-1];
    } else return fact[n-1];
}
