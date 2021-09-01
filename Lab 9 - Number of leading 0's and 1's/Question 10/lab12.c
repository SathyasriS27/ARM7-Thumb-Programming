#include <stdio.h>
#include <lpc21xx.h>

int main() {

	int a1 = 5;
	int b = 4;
	int i = 0;
	int sum = 0;  
	int diff = b - a1;
	int comp = ~a1;
	int a[3] = {1, 3, 4};

	for (i = 0; i <= 3; i++) {
		sum = sum + a[i];	
	}

	// int sum = a + b;
}