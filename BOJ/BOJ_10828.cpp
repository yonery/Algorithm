// BOJ 10828 스택 (C++)

#include <iostream>
#include <cstring>
using namespace std;



class Node {
public:
	int num;
	Node* pre;
	Node(int num);
};

Node::Node(int num) {
	this->num = num;
}


class Stack {
public:
	int ssize;
	Node* topNode;
	Stack();
	~Stack();

	void push(int num);
	void pop();
	void size();
	void empty();
	void top();
};

//스택생성시 topNode와 size 초기화
Stack::Stack() {
	this->topNode = NULL;
	this->ssize = 0;
}


//스택제거시
Stack::~Stack() {
	/*
	Node* ttop = this->topNode;
	while (ttop) {
		Node* old = ttop;
		ttop = ttop->pre;
		delete old;
	} */
}


void Stack::push(int num) {
	//스택에 값이 없을 경우
	if (this->topNode == NULL) {
		this->topNode = new Node(num);
		this->topNode->pre = NULL;
	}
	//값이 있을 경우
	else {
		//현재 top의 Node 값을 저장할 old를 만듬
		Node* old = this->topNode;
		//top을 new Node로 옮김(새 입력값)
		this->topNode = new Node(num);
		//new Node의 pre 값이 이전 값을 가리킬 수 있게
		this->topNode->pre = old;
	}
	ssize++;
	
}
void Stack::pop() {
	if (this->topNode == NULL)
		cout << "-1" << endl;
	else {
		cout << this->topNode->num << endl;
		Node* old = this->topNode->pre;
		delete this->topNode;
		this->topNode = old;
		ssize--;

	}
}
void Stack::size() {
	cout << ssize << endl;
}
void Stack::empty() {
	if (this->topNode == NULL)
		cout << "1" << endl;
	else
		cout << "0" << endl;
}
void Stack::top() {
	if (this->topNode == NULL)
		cout << "-1" << endl;
	else
		cout << this->topNode->num << endl;
}
int main() {
	int testcase;
	cin >> testcase;
	Stack stc;
	for (int T = 0; T < testcase; T++) {
		char cmd[10];
		cin >> cmd;
		if (strcmp(cmd, "push") == 0) {
			int num;
			cin >> num;
			stc.push(num);
		}
		else if (strcmp(cmd, "pop") == 0) {
			stc.pop();
		}
		else if (strcmp(cmd, "size") == 0) {
			stc.size();
		}
		else if (strcmp(cmd, "empty") == 0) {
			stc.empty();
		}
		else if (strcmp(cmd, "top") == 0) {
			stc.top();
		}
		else {

		}
	}
	cout << endl;
	return 0;
}
