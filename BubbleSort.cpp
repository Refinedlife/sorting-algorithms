#include <cstdio>
#include <cstdlib>
#define SIZE 8

void bubble_sort(int a[], int n); // n is the size of a

void bubble_sort(int a[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int number[SIZE] = { 95, 45, 15, 78, 84, 51, 24, 12 };
	int i;
	bubble_sort(number, SIZE);
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
