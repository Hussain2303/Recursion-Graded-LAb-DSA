#include "Node.h"
#include <iostream>
using namespace std;
class DCLL {
protected:
	Node* head;
public:
	virtual void printlistrecursive(int, int) = 0;
	virtual void insertRecursive(Node*, int) = 0;
	virtual void printlist() = 0;
	DCLL();
};
DCLL::DCLL() {
	head = nullptr;
}