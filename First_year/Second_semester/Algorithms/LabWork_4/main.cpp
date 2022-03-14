#include <iostream>
using namespace std;

class Elem {
	public:
		int x;
		Elem* next;
};

class Stack {
	public:
		Elem* head;

		Stack() {
			head = NULL;
		}

	void print() {
		Elem* el = head;
		while(el) {
			cout << el -> x << " ";
			el = el -> next;
		}
		cout << endl;
	}

	void add(int x) {
		Elem* el = new(Elem);
		el -> x = x;
		el -> next = head;
		head = el;
	}

	bool isEmpty() {
		return (!(head == NULL));
	}

	Elem* get() {
		if(isEmpty()) {
			Elem* el = head;
			head = el -> next;
			while(el -> next) {
				el -> x = el -> next -> x;
				el -> next = el -> next -> next;
				el = el -> next;
			}

			return head;
		} else {
			cout << "GET() ERR" << endl;

			return head;
		}
	}

	Elem* readHead() {
		return head;
	}
};

int main() {
	Stack st;
	cout << "Is stack empty now? " << st.isEmpty() << endl;

	cout << "I will add " << 12 << " element." << endl;
	st.add(12);
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "I will add " << 26 << " element." << endl;
	st.add(26);
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "I will add " << 30 << " element." << endl;
	st.add(30);
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "I will use get() now." << endl;
	st.get();
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "I will add " << 56 << " element." << endl;
	st.add(56);
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "Is stack empty now? " << st.isEmpty() << endl;
}
