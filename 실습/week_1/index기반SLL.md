`` c++

#include <iostream>

using namespace std;

class Node {
private:
	int data = NULL;
	Node* next = nullptr;

	friend class NodeList;
};

class NodeList {
private:
	int listSize;
	Node* head;
	Node* tail;
public:
	NodeList() {
		listSize = 0; head = tail = nullptr;
	}
	bool empty() {
		if (listSize == 0) { 
			return true; 
		}
		else { 
			return false; 
		}
	}
	void append(int data) { //제일 뒤에 추가
		Node* newNode = new Node;
		newNode->data = data;
		if (empty()) {
			head = tail = newNode;
			++listSize;
			return;
		}
		tail->next = newNode;
		tail = newNode;
		++listSize;
	}
	void insertion(int idx, int data) {
		if (idx < 0 || idx > listSize) {
			return;
		}
		else if (idx == listSize) { //제일 뒤에 추가 또는 빈 리스트에 추가
			append(data);
		}
		else if (idx == 0) { //제일 앞에 추가
			Node* newNode = new Node;
			newNode->data = data;
			newNode->next = head;
			head = newNode;
			++listSize;
		}
		else { //중간에 추가
			Node* newNode = new Node;
			newNode->data = data;
			Node* preNode = head;
			for (int i = 1; i < idx; ++i) {
				preNode = preNode->next;
			}
			newNode->next = preNode->next;
			preNode->next = newNode;
			++listSize;
		}
	}
	void deletion(int idx) { //삭제
		if (idx < 0 || idx >= listSize || empty()) {
			return;
		}
		Node* cursor = head;
		if (idx == 0) { //첫 번째 원소를 삭제
			if (listSize == 1) { //하나뿐일때
				head = tail = nullptr;
			}
			else {
				head = head->next;
			}
		}
		else {
			Node* pre = head;
			for (int i = 0; i < idx; ++i) {
				pre = cursor;
				cursor = cursor->next;
			}
			pre->next = cursor->next;
			if (cursor == tail) {
				tail = pre;
				//pre->next = nullptr; 위에서 이미 함.
			}
		}
		delete cursor;
		--listSize;
	}
	void print() {
		if (empty()) {
			cout << "empty!\n";
			return;
		}
		Node* cursor = head;
		for (int i = 0; i < listSize; ++i) {
			cout << cursor->data << ' ';
			cursor = cursor->next;
		}
		cout << '\n';
	}
};

int main() {
	NodeList myNode;
	string str;
	int data = 0, index = 0;

	cin >> str;

	while (cin) {
		if (str == "append") {
			cin >> data;
			myNode.append(data);
		}
		else if (str == "insert") {
			cin >> index >> data;
			myNode.insertion(index, data);
		}
		else if (str == "delete") {
			cin >> index;
			myNode.deletion(index);
		}
		else if (str == "print") {
			myNode.print();
		}
		cin >> str;
	}
}

``
