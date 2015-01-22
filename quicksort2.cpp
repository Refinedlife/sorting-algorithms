// Problem#: 12598
// Submission#: 3580558
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#ifndef _HW_08_1005_H
#define _HW_08_1005_H

template <typename Record>
void quick_sort(Record* startPointer, Record *endPointer) {
    if (startPointer != endPointer) {
        Record * low = startPointer, *high = endPointer, temp = *startPointer;
        high--;
        while (low != high) {
            while (low < high && *high > temp) high--;
            if (low != high) *low++ = *high;
            while (low < high && *low < temp) low++;
            if (low != high) *high-- = *low;
        }
        *low = temp;
        quick_sort(startPointer, low--);
        low++;
        quick_sort(++low, endPointer);
    }
}

#endif                                 


// 可运行
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

template <class Record>
void quick_sort(Record *startPointer, Record *endPointer) {
	if ((endPointer - startPointer) > 1) {
		Record *low = startPointer, *high = endPointer, temp = *startPointer;
		high--;
		while (low < high) {
			while (low < high && *high >= temp) high--;
			if (low != high) *low++ = *high;
			while (low < high && *low <= temp) low++;
			if (low != high) *high-- = *low;
		}
		*low = temp;
		quick_sort(startPointer, low - 1);
		quick_sort(low + 1, endPointer);
	}
}

int main() {
	int array[20] = {1,23,4,78,9,20,88,179,31,42,67,8,5};
	printf("The array unsorted is:\n");
	for (int i = 0; i < 13; i++) {
		printf("%d ", &array[i]);
	}
	printf("\n\n");
	quick_sort(array, array + 13);
	printf("The array sorted is:\n");
	for (int i = 0; i < 13; i++) {
		printf("%d ", &array[i]);
	}
	printf("\n\n");

	system("pause");
	return 0;
}
