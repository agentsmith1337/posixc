#include <stdio.h>
unsigned long long int fibonacci(int);
int main() {
	for (int i=1; i<=100; i++) {
		printf("%llu\t",fibonacci(i));
	}
}
unsigned long long int fibonacci(int n) {
	unsigned long long int x0=0, x1=1;
	for(int i=2; i<n; i++) {
		unsigned long long int x2=x0+x1;
		x0=x1; x1=x2;
	}
	if (n==1) return 0;
	else if (n==2) return 1;
	else return x1; 
} 
