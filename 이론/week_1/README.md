# Singly Linked List

``` c++
#include <iostream>

using namespace std;

class StringNode {
private:
	string str;
	StringNode* next = nullptr;

	friend class StringLinkedList;
};

class StringLinkedList {
private:
	StringNode* head;
	StringNode* tail;

public:
	StringLinkedList() : head{ nullptr }, tail{ nullptr } {
	}
	bool empty() const {
		if (head == nullptr) { //&&tail == nullptr 하면 removeFront의 두 번째 조건식에서 tail이 nullptr로 할당되지 않은 상태라 무조건 false 리턴해버림.
			return true;
		}
		else return false;
	}
	string front() const {
		return head->str;
	}
	void addFront(string& data) {
		StringNode* newNode = new StringNode;
		if (empty()) {
			tail = newNode;
		}
		newNode->next = head; //비었으면 nullptr 참조할 것
		newNode->str = data;
		head = newNode;
	}
	void removeFront() {
		if (empty()) {
			return;
		}
		StringNode* oldNode = head; //앞부분 return 전에 만들면 의미없는 노드가 만들어진 상태로 함수가 종료될 수 있음. 조심.
		head = head->next;
		delete oldNode;
		if (empty()) {
			tail = nullptr;
		}
	}
	void addBack(string& data) {
		StringNode* newNode = new StringNode;
		newNode->str = data;
		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode; //이 부분을 위한 else
			tail = newNode;
		}
	}
	void removeBack() {
		if (empty()) {
			return;
		}
		StringNode* current = head;
		if (current == tail) { //빼먹으면 안됨
			delete current;
			head = tail = nullptr;
		}
		else {
			while (current->next != tail) {
				current = current->next;
			}
			delete tail;
			tail = current;
			tail->next = nullptr; //프린트 실패했던 이유. 이걸 빼먹음. 현재 tail은 head부터 올라온 녀석이고, next가 해제된 메모리를...
		}
	}
	void printList() {
		if (empty()) {
			cout << "empty!\n";
			return;
		}
		StringNode* temp = head;
		while (temp != nullptr) {
			cout << temp->str << ' ';
			temp = temp->next;
		}
		cout << '\n';
	}
	~StringLinkedList() {
		StringNode* temp;
		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
		}
		delete head;
		delete tail;
	}
};

int main() {
	StringLinkedList myList;

	string str;

	while (cin >> str) {
		if (str == "addFront") {
			cin >> str;
			myList.addFront(str);
		}
		else if (str == "removeFront") {
			myList.removeFront();
		}
		else if (str == "addBack") {
			cin >> str;
			myList.addBack(str);
		}
		else if (str == "removeBack") {
			myList.removeBack();
		}
		else if (str == "print") {
			myList.printList();
		}
		else if (str == "front") {
			cout << myList.front() << '\n';
		}
	}
	return 0;
}
```
