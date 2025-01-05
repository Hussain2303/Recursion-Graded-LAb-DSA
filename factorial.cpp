#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int factorial(int n)
{
	if (n == 0)
		return 1;
	if (n > 0)
		return n * factorial(n - 1);
}
int nod(int n)
{
	if (n == 0)
		return 0;
	if (n > 0)
		return nod(n / 10) + 1;
}
int sod(int n)
{
	if (n == 0)
		return 0;
	if (n > 0)
		return sod(n / 10) + n % 10;
}
int fab(int n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n > 2)
		return fab(n - 1) + fab(n - 2);
}
int RD(int num, int reversedNum = 0)
{
	if (num == 0)
		return reversedNum;
	if (num > 0)
		reversedNum = reversedNum * 10 + num % 10;
	return RD(num / 10, reversedNum);
}
void DTB(int n)
{
	if (n > 0)
	{
		DTB(n / 2);
		cout << n % 2;
	}
}
int SumOF(int n)
{
	if (n > 0)
		return n+ SumOF(n - 1);
}
void PN(int n)
{
	if (n == 0)
		return;
	if (n > 0)
	{
		return PN(n - 1);
		cout << n << " ";
	}
}
void reverseString(string& str, int start, int end)
{
	if (start >= end)
		return;
	else {
		swap(str[start], str[end]);
		reverseString(str, start + 1, end - 1);
	}
}
int power(int a, int b)
{
	if (b == 0)
		return 1;
	if (b > 0)
		return a * power(a, b - 1);
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	if (b > 0)
		return gcd (b, a % b);
}
void insertAtBottom(stack<int>& s, int element)
{
	if (s.empty()) {
		s.push(element);
		return;
	}

	// Pop the top element
	int topElement = s.top();
	s.pop();

	// Recursively call to insert at the bottom
	insertAtBottom(s, element);

	// Push the top element back after recursion
	s.push(topElement);
}

// Function to reverse the stack
void reverseStack(stack<int>& s)
{
	if (s.empty()) {
		return;
	}

	// Pop the top element
	int topElement = s.top();
	s.pop();

	// Recursively reverse the remaining stack
	reverseStack(s);

	// Insert the popped element at the bottom of the reversed stack
	insertAtBottom(s, topElement);
}
void reverseQueue(queue<int>& q) {
	if (q.empty()) {
		return; // Base case: stop when the queue is empty
	}

	// Step 1: Remove the front element
	int frontElement = q.front();
	q.pop();

	// Step 2: Recursively reverse the remaining queue
	reverseQueue(q);

	// Step 3: Add the removed element to the back of the queue
	q.push(frontElement);
}

// Helper function to print a queue
void printQueue(queue<int> q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main()
{
	/*string str = "hello";
	cout << factorial(5) << endl;
	cout << nod(5432) << endl;
	cout << sod(5432) << endl;
	cout << fab(5) << endl;
	cout << RD(1024) << endl;
	DTB(14);
	cout << endl;
	cout << SumOF(5) << endl;
	 PN(10);
	 reverseString(str,0,str.length()-1);
	 cout << str << endl;
	 cout << power(4, 3);
	 cout << endl;
	 cout << gcd(48, 18);*/
	/*stack<int> s;
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	reverseStack(s);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;*/
	queue<int> q;

	// Push some elements into the queue
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	cout << "Original Queue: ";
	printQueue(q);

	// Reverse the queue
	reverseQueue(q);

	cout << "Reversed Queue: ";
	printQueue(q);

	return 0;
}