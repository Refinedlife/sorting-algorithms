#include <iostream>
#include <vector>
using namespace std;
// 面向过程的设计，过程封装性
void print(vector<int> v);
void select_sort(vector<int> &v);
void get_vector(int n, vector<int> &v);

int main() {
    int T;
    cin >> T; //测试样例个数
    while (T--) {
        int n;
        vector<int> v;
        cin >> n;
        get_vector(n, v);
        select_sort(v);
        print(v);
        v.clear();
    }
    return 0;
}

void get_vector(int n, vector<int> &v) {
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
}
void print(vector<int> v) {
    vector<int>::iterator iter;
    for (iter = v.begin(); iter < v.end() - 1; iter++) {
        cout << *iter << " ";
    }
    iter = v.end() - 1;
    cout << *iter << endl;
}

void select_sort(vector<int> &v) {
    for (int s = 0; s < v.size() - 1; s++) {
        int min, index;
        int i = s;
        min = v[i];
        index = i;
        for (; i < v.size() - 1; i++) {
            if (v[i + 1] < min) {
                min = v[i + 1];
                index = i + 1;
            }
        }
        int temp =v[s];
        v[s] = v[index];
        v[index] = temp;
        //print(v); show every step
    }
}
