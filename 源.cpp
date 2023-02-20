#include<iostream>
#include <cstdlib>
using namespace std;

int main() {
	void insert_normal(int *, int);//直接插入排序
	void mid_insert(int*, int);//折半插入排序
	void shell_insert(int*, int);//shell排序
	srand((unsigned)time(0));
	int n ;
	cout << "输入数组长度:";
	cin >> n;
	int* num = new int[n];
	cout << "得到数组：" << endl;
	for (int i = 0; i < n; i++) {
		num[i] = rand() % 100;
		cout << num[i] << " ";
	}
	cout << endl;
	//insert_normal(num, n);
	//mid_insert(num, n);
	shell_insert(num, n);
	cout << "排序后:" << endl;
	for (int i = 0; i < n; i++) {
		cout << num[i] << " ";
	}

	return 0;
}

void insert_normal(int* num,int n) {//直接插入排序
	if (n <= 1) {
		return;
	}
	int i, j;
	for (i = 1; i < n; i++) {
		if (num[i] < num[i - 1]) {
			int temp = num[i];
			for (j = i-1; j >= 0&&num[j]>temp; j--) {
				num[j + 1] = num[j + 1] ^ num[j];
				num[j] = num[j] ^ num[j + 1];
				num[j + 1] = num[j + 1] ^ num[j];
			}
			num[j + 1] = temp;
		}
	}
}

void mid_insert(int* num, int n) {//折半插入排序
	if (n <= 1) {
		return;
	}
	int i, j;
	for (i = 1; i < n; i++) {
		if (num[i] < num[i - 1]) {
			int temp = num[i];
			int low = 0, high = i - 1;
			while (low <= high) {
				int mid = (low + high) >> 1;
				if (num[mid] > temp) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			for (j = i - 1; j >= low; j--) {
				num[j + 1] = num[j];
			}
			num[j + 1] = temp;
		}
	}
}

void shell_insert(int* num, int n) {//Shell排序
	if (n <= 1) {
		return;
	}
	int i, j;
	for (int d = n / 2; d >0; d /= 2) {
		for (i = d; i < n; i++) {
			if (num[i] < num[i - d]) {
				int temp = num[i];
				for (j = i - d; j >= 0 && num[j] > temp; j -= d) {
					num[j + d] = num[j];
				}
				num[j + d] = temp;
			}
		}
	}
}