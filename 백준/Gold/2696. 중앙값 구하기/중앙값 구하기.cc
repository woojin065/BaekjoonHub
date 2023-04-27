#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int com(const void* a, const void* b) { return *(int*)a - *(int*)b; }
void Q(int* arr, int k) {
	printf("%d\n", (k / 2)+1);
	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			qsort(arr, i + 1, sizeof(int), com);
			printf("%d ", arr[i / 2]);
		}
	}
	printf("\n");
}
int main() {
	int n;
	scanf("%d ", &n);
	for (int i = 0, k; i < n; i++) {
		scanf("%d ", &k);
		int* arr = (int*)malloc(sizeof(int) * k);
		for (int j = 0; j < k; j++) scanf("%d", &arr[j]);
		Q(arr, k);
		free(arr);
	}
}