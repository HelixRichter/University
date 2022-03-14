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

int main()
{
	Stack st;
	cout << "Is stack empty now? " << st.isEmpty() << endl;

	cout << "I will add " << 17 << " element." << endl;
	st.add(17);
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "I will add " << 34 << " element." << endl;
	st.add(34);
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "I will add " << 29 << " element." << endl;
	st.add(29);
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "I will use get() now." << endl;
	st.get();
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "I will add " << 13 << " element." << endl;
	st.add(13);
	cout << "Here is your stack now:" << endl;
	st.print();

	cout << "Is stack empty now? " << st.isEmpty() << endl;
}
