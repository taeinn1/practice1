#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FileName.h"


typedef struct {
	char name[10];
	int age;
}Person;

typedef int (*fp)(int a, int b);

int cal(fp func, int aa, int bb) {
	return func(aa, bb);
}


int main(void) {
#if 0


	Person* per = (Person*)malloc(sizeof(Person));
	fgets(per->name, sizeof(per->name), stdin);
	size_t len = strlen(per->name);
	if (len-1=="\n" && len>0)
		per->name[len-1] = 0;
	scanf("%d", &per->age);
	printf("%s %d", per->name, per->age);

	free(per);

#endif

	printf("%d", cal(mul, 3, 4));


}