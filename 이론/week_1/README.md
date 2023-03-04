# Singly Linked List 연습

``` c++
#include <iostream>

using namespace std;

class StringNode {
private:
	string str;
	StringNode* next;

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
		if (head == nullptr && tail == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	string front() const {
		return head->str;
	}
	void addFront(string& data) {
		StringNode* newNode = new StringNode;
		if (empty()) {
			tail = newNode;
		}
		newNode->str = data;
		newNode->next = head;
		head = newNode;
	}
	void removeFront() {
		if (empty()) {
			return;
		}
		StringNode* old = head;
		head = old->next;
		delete old;
		if (empty()) {
			tail = nullptr;
		}
	}
	void addBack(string& data) {
		StringNode* newNode = new StringNode;
		newNode->str = data;
		if (empty()) {
			head = newNode;
		}
		tail->next = newNode;
		tail = newNode;
	}
	void removeBack() {
		if (empty()) {
			return;
		}
		StringNode* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		delete current->next;
		tail = current;
		tail->next = nullptr;
	}
	void printList() {
		if (empty()) {
			cout << "Empty List\n";
			return;
		}
		StringNode* current = head;
		while (current != nullptr) {
			cout << current->str << ' ';
			current = current->next;
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

	int testCase;
	string str;

	cin >> testCase;

	while (testCase--) {
		cin >> str;
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
