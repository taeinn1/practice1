#include <stdio.h>
#include <stdlib.h>


int main(void) {
#if 1
	int n;
	scanf("%d", &n);

	int *arr = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		printf("%d¹øÂ°: ",i+1);
		scanf("%d", arr + i);
	}
	for (int i = n-1; i >=0; i--) {
		printf("%d", *(arr + i));
	}
	free(arr);

#endif
}

