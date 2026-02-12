#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
/*
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
*/



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
	char s[107];
	sprintf("%s", "output>");
	puts(name);
	*/
int main(void) {
	typedef struct {
		char name[30];
		char country[30];
		int popul;
	}city;

	city c[3];
	printf("Input three cities: \n");
	for (int i = 0; i < 3; i++) {
		printf("Name> ");
		fgets(c[i].name,sizeof(c[i].name), stdin);
		c[i].name[strlen(c[i].name) - 1] = 0;
		printf("Country> ");
		fgets(c[i].country, sizeof(c[i].country), stdin);
		c[i].country[strlen(c[i].country) - 1] = 0;
		printf("Population> ");
		scanf("%d", &c[i].popul);
		getchar(); //scanf´Â ¿£ÅÍ ³²±è
		printf("\n");
		
	}
	printf("Printing the three cities:\n");
	for (int i = 0; i < 3; i++) {
		printf("%d. %s in %s with a population of %d people\n",i+1,c[i].name,c[i].country,c[i].popul);

	}
}