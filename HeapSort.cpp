#include <iostream>
#include <cstdlib>
using namespace std;

void HeapSort(int arr[], int size);
void HeapAdjust(int arr[], int s, int e);
void swap(int arr[], int a, int b);
void print(int arr[], int size);

int main() {
	int n, temp;
	int arr[100];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		arr[i] = temp;
	}
	cout << "print() test:" << endl;
	print(arr, n);
	cout << "swap() test:" << endl;
	swap(arr, 1, 3);
	print(arr, n);
	cout << "HeapSort() test:" << endl;
	HeapSort(arr, n);
	print(arr, n);
	system("pause");
	return 0;
}

void HeapSort(int arr[], int size) {
	for (int i = size / 2; i >= 1; i--) {
		HeapAdjust(arr, i, size);
	}
	print(arr, size);
	for (int i = size; i > 1; i--) {
		swap(arr, 1, i);
		HeapAdjust(arr, 1, i - 1);
		print(arr, size);
	}
}

void HeapAdjust(int arr[], int s, int e) {
	int temp, i;
	temp = arr[s];
	for (i = 2 * s; i <= e; i *= 2) {
		if (i < e && arr[i] < arr[i + 1]) {
			i++;
		}
		if (arr[i] <= temp) {
			break;
		}
		arr[s] = arr[i];
		s = i;
	}
	arr[s] = temp;
}

void swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void print(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << arr[size] << endl;
}
