#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int arrSize;

public:
	Array(int sz) : arrSize{ sz } {
		arr = new int[arrSize];
		for (int i = 0; i < arrSize; ++i) {
			cin >> arr[i];
		}
	}
	void shift_idx(int d) { // 0 1 2 3 4
		for (int i = 0; i < d; ++i) {
			int first = arr[0];
			for (int j = 0; j < arrSize - 1; ++j) {
				arr[j] = arr[j + 1];
			}
			arr[arrSize - 1] = first;
		}
	}
	void switch_idx(int a, int b) {
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
	void print() {
		for (int i = 0; i < arrSize; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	~Array() {
		delete[] arr;
	}
};

int main() {
	int t, n, i = 0, j = 0;
	string str;

	cin >> t >> n;
	Array ar(n);

	while (t--) {
		cin >> str;
		if (str == "shift") {
			cin >> i;
			ar.shift_idx(i);
		}
		else if (str == "switch") {
			cin >> i >> j;
			ar.switch_idx(i, j);
		}
		else if (str == "print") {
			ar.print();
		}
	}
	return 0;
}