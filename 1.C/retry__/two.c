#include <stdio.h>

int main2(void) {
	int num1=3, num2=2;
	int cur = 0, sum = 0;
	/*
	printf("Input two integers: ");
	scanf("%d %d", &num1, &num2);
	printf("%d & %d = %d\n", num1, num2, num1 & num2);
	printf("%d | %d = %d\n", num1, num2, num1| num2);
	printf("%d ^ %d = %d", num1, num2, num1^num2);
	
	
	printf("please enter kilometers: "); scanf("%lf", &num1);
	printf("%lf km is equal to %.1lf miles.", num1, num1 / 1.609);
	

	int cur = 2;
	int is = 0;

	while (cur < 10) {
		is = 1;
		while (is < 10) {
			printf("%d X %d = %d\n", cur, is, cur * is);
			is++;
		}
		cur++;
	}
	

	
	printf("몇개나?: "); scanf("%d", &num1);
	while (cur < num1) {
		printf("입력: "); scanf("%d", &num2);
		sum += num2;
		cur++;
	}
	
	printf("%lf", (double)sum/num1);
	
	
	int row = 5;
	for (int i = 1; i <= row; i++) {
		for (int j = 0; j < row - i; j++) {
			printf(" ");
		}
		for (int j = 0; j < i * 2 - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/
	
	int arr[5];
	printf("Please input five integers: "); scanf("%d %d %d %d %d",&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	printf("Odd numbers: ");
	for(int i = 0; i < 5; i++)
		if (arr[i] % 2 == 1) 
			printf("%d ", arr[i]);
	printf("\n");
	printf("Even numbers: ");
	for (int i = 0; i < 5; i++)
		if (arr[i] % 2 == 0)
			printf("%d", arr[i]);
	
}