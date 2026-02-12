#include <stdio.h>
#include <math.h>

double gap(const int ptr[5]) {
	double sum=0, avr;
	for (int i = 0; i < 5; i++) {
		sum += ptr[i];
	}
	avr= sum/5;
	sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += pow((ptr[i] - avr), 2);
		
	}
	sum /= 5;
	return sqrt(sum);

}


int main(void) {

	/*
	int arr1[6] = {1,2,3,4,5,6}, arr2[6] = {7,8,9,10,11,12};
	int* ptr1 = arr1, *ptr2 = arr2;
	int temp;

	for (int i = 0; i < 6; i++) {
		temp = *(ptr1 + i);
		*(ptr1 + i) = *(ptr2 + i);
		*(ptr2 + i) = temp;
	}
	
	int arr[5];
	printf("Enter 5 real numbers: ");
	scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	printf("%lf",gap(arr));
	*/

	fputs("Input> ", stdout);
	char name[100];

	fgets(name, sizeof(name), stdin);
	int gap = 'a' - 'A';
	for (int i = 0; name[i] != '\0'; i++) {
		if (name[i] >= 'A' && name[i] <= 'Z') {
			name[i] = name[i] + gap;
		}
		else if (name[i] >= 'a' && name[i] <= 'z') {
			name[i] = name[i] - gap;
		}
	}
	sprintf(name, "%s", "output>");
	puts(name);

}