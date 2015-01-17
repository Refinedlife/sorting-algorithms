// 用vector实现插入排序
// copyright reserved by WarpPrism
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v);

int main() {
    int N;
    vector<int> v;
    cin >> N; // N代表数据个数
    while (N--) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    bool original = true;
    // s 代表已经排列好的元素个数
    for (int i = 1, s = 1; i < v.size(); i++, s++) {
        for (int j = 0; j < s; j++) {
            if (v[i] < v[j]) {
                original = false;
                v.insert(v.begin() + j, v[i]);
                v.erase(v.begin() + i + 1);
                print(v); // 每一步都显示出来
            }
        }
    }
    if (original) print(v); // 若原始数据已经是升序排列的，则输出原始数据
    return 0;
}

// print函数
void print(vector<int> v) {
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}
