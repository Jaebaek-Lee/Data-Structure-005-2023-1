#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int arrSize;

public:
	Array(int sz) {
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < sz; ++i) {
			arr[i] = 0;
		}
	}

	void at(int idx) { //index로 원소 출력
		cout << arr[idx] << '\n';
	}

	void add(int idx, int value) { //원소 추가 0 1 2 3 4
		for (int i = arrSize - 2; i >= idx; --i) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	void remove(int idx) { //원소 삭제 0 1 2 3 4
		for (int i = idx; i < arrSize - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		arr[arrSize - 1] = 0;
	}

	void print() {
		for (int i = 0; i < arrSize; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}

	void set(int idx, int value) { //원소 변경
		arr[idx] = value;
	}

	void find(int value) { //사실 정렬 하고 이진탐색하는게 빠르긴 한데... stl이 금지다... 정렬 빠르게 짜기엔 다 까먹음
		//bool checker = false;
		//int min = 10000;
		for (int i = 0; i < arrSize; ++i) {
			/*if (arr[i] == value && i <= min) { 괜히 어렵게 생각했다. 어차피 0부터 도는거면 처음 찾은 idx가 가장 작은 idx다...
				min = i;
				checker = true;
			}*/
			if (arr[i] == value) {
				//checker = true;
				cout << i << '\n';
				return;
			}
		}
		/*if (!checker) {
			cout << -1 << '\n';
		}
		else cout << min << '\n';*/
		cout << -1 << '\n';
	}

	~Array() {
		delete[] arr;
	}
};

int main() {
	int t = 0, i, x, size = 0;
	string str;
	cin >> t >> size;
	Array ar(size);
	while (t--) {
		cin >> str;
		if (str == "at") {
			cin >> i;
			ar.at(i);
		}
		else if (str == "add") {
			cin >> i >> x;
			ar.add(i, x);
		}
		else if (str == "set") {
			cin >> i >> x;
			ar.set(i, x);
		}
		else if (str == "remove") {
			cin >> i;
			ar.remove(i);
		}
		else if (str == "print") {
			ar.print();
		}
		else if (str == "find") {
			cin >> i;
			ar.find(i);
		}
	}
	return 0;
}