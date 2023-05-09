#include <iostream>

struct Node {
	Node() {}
	Node(int val) : elem(val), next(nullptr) {}
	Node(int e, Node* n) : elem(e), next(n) {}
	
	int elem = 0;
	Node* next = nullptr;
	
	struct NodeIterator {
		NodeIterator() {};
		
		NodeIterator(Node* x) : p(x) {}
		
		Node* p = nullptr;
	
		int& operator *(){ return p->elem; }
	
		bool operator !=(const NodeIterator& other){
	    	     return p!=other.p;
		}
		
		void operator =(const NodeIterator& other){
	    	     p=other.p;
		}
	
		void operator ++(){ p=p->next; }
	};

	NodeIterator begin(){
	   return NodeIterator(next);
	}

	NodeIterator end(){
	   return NodeIterator(nullptr);
	}
	
};


void add(Node& n, int x) {
	n.next = new Node(x, n.next);
}


int main() {
	Node head; 
        
	add(head, 1);
	add(head, 2);
	add(head, 3);
	add(head, 4);
	add(head, 5);

	for (Node* p = head.next; p != nullptr; p = p->next) {
		std::cout << p->elem << " ";
	}
        std::cout << std::endl;

	for (int x : head) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	
	for (int& x : head) {
		x = 7;
	}
	
	for (const int& x : head) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
        
	return 0;
}
