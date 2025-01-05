#include "DCLL.h"

class MyDCLL : public DCLL {
private:
    int getNodeCount() {
        if (head == nullptr) {
            return 0;
        }
        Node* temp = head;
        int count = 0;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void printlistrecursiveUtil(Node* current, Node* start, int count, int end) {
        if (!current || (current == start && count != 0)) {
            return; // Base case: Stop when we return to the head after completing the loop
        }

        if (count > end && end != -1) {
            return; // Stop when the end position is reached
        }

        cout << current->data << " ";
        printlistrecursiveUtil(current->next, start, count + 1, end);
    }

public:
    void printlistrecursive(int start = 0, int end = -1);
    void insertRecursive(Node* current, int data);
    void printlist();
    Node* getHead() { return head; }
};

void MyDCLL::printlistrecursive(int start, int end) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    int nodeCount = getNodeCount();
    if (start >= nodeCount || (end >= 0 && start > end)) {
        cout << "Invalid range." << endl;
        return;
    }

    Node* startNode = head;
    for (int i = 0; i < start; ++i) {
        startNode = startNode->next;
    }

    printlistrecursiveUtil(startNode, startNode, 0, end - start + 1);
    cout << endl;
}

void MyDCLL::insertRecursive(Node* current, int data) {
    if (head == nullptr) { // If the list is empty
        head = new Node;
        head->data = data;
        head->next = head;
        head->prev = head;
        return;
    }

    if (current->next == head) { // If we've reached the end of the list
        Node* newNode = new Node;
        newNode->data = data;
        current->next = newNode;
        newNode->prev = current;
        newNode->next = head;
        head->prev = newNode;
    }
    else {
        insertRecursive(current->next, data); // Recursive call
    }
}

void MyDCLL::printlist() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
