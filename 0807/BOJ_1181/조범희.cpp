#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyStruct
{
	char voca[50];
	int num;

	
}MyStruct;

int pare(const void* aSort, const void* bSort) { // 오름차순
	MyStruct A = *(MyStruct*)aSort;
	MyStruct B = *(MyStruct*)bSort;
	if (A.num > B.num)
		return 1;
	else if (A.num < B.num)
		return -1;
	else if (A.num == B.num) {
		if (strcmp(A.voca, B.voca) > 0)
			return 1;
		else if (strcmp(A.voca, B.voca) == 0)
			return 0;
		else if (strcmp(A.voca, B.voca) < 0)
			return -1;
	}
}

int main()
{
	int N;
	struct MyStruct* st;

    scanf("%d", &N);

	st = (MyStruct*)malloc(sizeof(MyStruct) * N);

	for (int i = 0; i < N; i++) {
		scanf("%s", st[i].voca);
		st[i].num = strlen(st[i].voca);
	}

	qsort(st, N, sizeof(MyStruct), pare);
	
	for (int i = 0; i < N; i++) {
		if (i != 0 && strcmp(st[i].voca, st[i - 1].voca) == 0)
			continue;
		else
			printf("%s\n", st[i].voca);
	}
}
