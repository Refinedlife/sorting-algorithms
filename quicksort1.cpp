//用vector实现快速排序，排序代码参考了stackoverflow上的代码
//快速排序是一种很重要的排序算法

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void quick_sort(vector<int>::iterator begin, vector<int>::iterator end);
void print(vector<int> v);
int mmin(vector<int> v, int K);
int mmax(vector<int> v, int K);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        vector<int> v;
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        quick_sort(v.begin(), v.end());
        // print(v);
        int min = mmin(v, K);
        int max = mmax(v, K);
        // cout << min << " " << max << endl;
        cout << max - min << endl;
    }
}

void quick_sort(vector<int>::iterator begin, vector<int>::iterator end) {
    if (end - begin < 2) return;
    vector<int>::iterator l = begin;
    vector<int>::iterator r = end - 1;
    vector<int>::iterator pivot = l + rand() % (r - l + 1);
    while(l != r)
    {
        // Find the lowest bound number to swap
        while(*l < *pivot) ++l;
        while(*r >= *pivot && l < r) --r;

        // Do the swap
        if(pivot == l) { pivot = r; }
        swap(*l, *r);
    }
    // Here l == r and numbers in the interval [begin, r) are lower and in the interval [l, end) are greater or equal than the pivot
    // Move pivot to the position
    swap(*pivot, *l);

    // Sort left
    quick_sort(begin, l);
    // Sort right
    quick_sort(l + 1, end);
}

void print(vector<int> v) {
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

int mmin(vector<int> v, int K) {
    int index;
    if (K % 2 != 0) {
        index = (K - 1) / 2;
        return v[index];
    } else {
        return (v[K / 2] + v[K / 2 - 1]) / 2;
    }
}

int mmax(vector<int> v, int K) {
    int index;
    if (K % 2 != 0) {
        index = (v.size() * 2 - (K + 1)) / 2;
        return v[index];
    } else {
        index = v.size() - 1 - K / 2;
        return (v[index] + v[index + 1]) / 2;
    }
}
