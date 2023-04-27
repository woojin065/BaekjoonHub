#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int len = 0;
void ch(int* arr, int N, int M, int lev) {
	if (lev == M) {
		for (int i = 0; i < M; i++) printf("%d ", arr[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= N; i++) {
			int ch1 = 1;
			for (int j = 0; j < len; j++)if (arr[j] == i) { ch1 = 0; break; }
			if (ch1) { arr[len++] = i; ch(arr, N, M, lev + 1); len--;}
		}
	}
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int* arr = (int*)malloc(sizeof(int) * M);
	ch(arr, N, M, 0);
}