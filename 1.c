#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10
#define size 4

int check (int number, double size){
	if ((number % pow(10, size)) == 0){
		return number;
	}
}

void writing(FILE* f, int number) {
	fprintf(f, "%d ", number);
}
 
void main (void) {
	
	FILE *f;

	srand(time(NULL));
	
	f = fopen("numbers.txt", "w");
	
	for(int i = 0; i < N; i++){
		writing(f, rand());
	}
	
	fclose(f);
}
