这段代码是很久之前从网上找的，当时对递归算法没什么概念，所以没怎么理解，大二上学习了DataStructure And Algorithm
脑子中多多少少有些概念了。

其实这个算法的执行过程很别扭。正规的思路是在连续表中（这里用数组）中用随机函数选定一个参考值val，然后分别在val的左右
找比val大和比val小的元素，然后两者互换，直至val左边所有元素都比val小，右边的都比val大。最后再递归排序val左边和右边的
连续表。

但这个算法的思路是，直接让参考值val等于数组的第一个元素，然后从后向前找大于val的元素，然后将这个值a[j]赋值给前面
再然后，从前往后找比val小的元素a[i]，然后令a[j] = a[i]，赋值。循环此过程，a[i] = a[j] a[j] = a[i]······
最后，将val，即最初被替换掉的元素 赋给 a[i]，完成分组。接下来，写个递归就OK了。


void QuickSort(int a[], int numsize) /*a是整形数组，numsize是元素个数*/
{
	int i = 0, j = numsize - 1;
	int val = a[0]; /*指定参考值val大小*/
	if (numsize > 1) /*确保数组长度至少为2，否则无需排序*/
	{
		while (i < j) /*循环继续执行的条件*/
		{
			/*从后向前搜索比val小的元素，找到后填到a[i]中并跳出循环*/
			for (; j > i; j--)
				if (a[j] < val)
				{
					a[i] = a[j];
					break;
				}
			/*从前往后搜索比val大的元素，找到后填到a[j]中并跳出循环*/
			for (; i < j; i++)
				if (a[i] > val)
				{
					a[j] = a[i];
					break;
				}
		}
		a[i] = val; /*将保存在val中的数放到a[i]中*/
		QuickSort(a, i); /*递归，对前i个数排序*/
		QuickSort(a + i + 1, numsize - 1 - i); /*对i+1到numsize-1这numsize-1-i个数排序*/
	}
}

/*Testing code*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	// void QuickSort(int a[], int numsize); /*函数原型*/ 函数在主函数之前声明，所以就不用定义函数原型了
	int a[8] = { 0, 1, 3, 23, 12, 88, 56, 778 };
	QuickSort(a, 8);
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
/*此函数执行的是从小到大排序*/
