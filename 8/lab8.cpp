//modified by: Elijah Morris
//date: 3-12-20
//
//author: Gordon Griesel
//date: Fall 2017
//floodfill with a stack and queue
//
//Assignment:
//Make the floodfill_queue() function work.
//Make both the stack and queue classes templates.
//
//
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
const int w = 44;
const int h = 22;
void fillMaze(char fill_char);
void floodfill_stack(int a, int b, char fill_char);
void floodfill_queue(int a, int b, char fill_char);
void showMaze();
const int MAX_QUEUE = 10000;
const int MAX_STACK = 10000;
char maze[w*h+2] = "\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\
x                                          x\
x                                          x\
x                xxxxxxxxxxxx              x\
x           xxxxxxxxxxxxxxxxxxxxxx         x\
x         xxxxxxxxx       xxxxxxxxx        x\
x        xxxx                   xxxx       x\
x        xxx     xxxxxxxxxxx     xxx       x\
x        xxx    xxxxxxxxxxxxx    xxx       x\
x       xxx     xxxx     xxxx     xxx      x\
x       xxx     xxx       xxx     xxx      x\
x       xxx     xxx       xxx     xxx      x\
x       xxx     xxxx     xxxx     xxx      x\
x        xxx    xxxxxxxxxxxxxxxxxxxx       x\
x        xxx     xxxxxxxxxxxxxxxxxx        x\
x        xxxx                              x\
x         xxxxxxxxx      xxxxxxxx          x\
x           xxxxxxxxxxxxxxxxxxxx           x\
x               xxxxxxxxxxxxx              x\
x                    xxx                   x\
x                                          x\
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";


class Node {
public:
	int x, y;
	bool visited;
	Node() {
		visited = false;
	}
	Node(int a, int b, bool q) {
		x = a;
		y = b;
		visited = q;
	}
} xp[w*h];

template <class T>
class Stack {
public:
	T *arr;
	int top;
	~Stack() {
		delete [] arr;
	}
	Stack() {
		top = -1;
		arr = new Node[MAX_STACK];
	}
	bool isFull() {
		return (top >= MAX_STACK-1);
	}
	bool isEmpty() {
		return (top < 0);
	}
	void push(T node) {
		if (isFull()) {
			cout << "full ";
			return;
		}
		arr[++top] = node;
	}
	void push(int x, int y) {
		if (isFull()) {
			cout << "full ";
			return;
		}
		++top;
		arr[top].x = x;
		arr[top].y = y;
	}
    T pop() {
		if (isEmpty()) {
			cout << "empty ";
			T tmp(-1, -1, false);
			return tmp;
		}
		T p = arr[top--];
		return p;
	}
};


template <class T>
class Queue {
public:
	T *arr;
	int front, back, n;
	//
	//You write the queue class here.
    //
	~Queue() {
		delete [] arr;
	}
	Queue() {
		front = -1;
        back = -1;
        n = 0;
		arr = new Node[MAX_QUEUE];
	}
	bool isFull() {
		return (n >= MAX_QUEUE);
	}
	bool isEmpty() {
		return (n == 0);
	}
	void enqueue(T node) {
		if (isFull()) {
			cout << "full ";
			return;
		}
        back++;
		arr[back] = node;
        n++;
	}
	void enqueue(int x, int y) {
		if (isFull()) {
			cout << "full ";
			return;
        }
        back++;
		arr[back].x = x;
		arr[back].y = y;
        n++;
	}
	T dequeue() {
		if (isEmpty()) {
			cout << "empty ";
			T tmp(-1, -1, false);
			return tmp;
		}
        front++;
		T p = arr[front];
		return p;
        n--;
        
	}
};





int main(int argc, char *argv[])
{
	int x=2, y=2;
	char fill = 'm';
	if (argc > 1) x = atoi(argv[1]);
	if (argc > 2) y = atoi(argv[2]);
	if (argc > 3) fill = argv[3][0];
	//
	showMaze();
	switch (fill) {
		case 'm': fillMaze('.'); break;
		case 's': floodfill_stack(x,y, '-'); break;
		case 'q': floodfill_queue(x,y, '#'); break;
	}
	showMaze();
	cout << endl;
	if (argc < 2) {
		cout << "USAGE: $ " << argv[0] << " <x> <y> <m, s, q>\n";
		cout << "                                       \n";
		cout << "(x, y) = starting position             \n";
		cout << "                                       \n";
	}
	cout << endl;
	return 0;
}

bool isValid(int x, int y, char c)
{
	return (!xp[y*w+x].visited &&
		maze[y*w+x] == c &&
		x>=0 && y>=0 && x<w && y<h);
}

void floodfill_stack(int a, int b, char fill_char)
{
	//push first point
	Node nd(a, b, false);
    Stack<Node> s;
	char c = maze[b*w+a];
	s.push(nd);
	while (!s.isEmpty()) {
		Node p = s.pop();		
		int x = p.x;
		int y = p.y;
		maze[y*w+x] = fill_char;
		//push 4 neighbors...
		//look left
		x = p.x-1;
		y = p.y;
		if (isValid(x, y, c)) {
			s.push(x,y);
			xp[y*w+x].visited = true;
		}
		//look above
		x = p.x;
		y = p.y+1;
		if (isValid(x, y, c)) {
			s.push(x,y);
			xp[y*w+x].visited = true;
		}
		//look right
		x = p.x+1;
		y = p.y;
		if (isValid(x, y, c)) {
			s.push(x,y);
			xp[y*w+x].visited = true;
		}
		x = p.x;
		y = p.y-1;
		//look below
		if (isValid(x, y, c)) {
			s.push(x,y);
			xp[y*w+x].visited = true;
		}
		showMaze();
		usleep(50000);
	}
}

void floodfill_queue(int a, int b, char fill_char)
{
	Node nd(a, b, false);
    Queue<Node> q;
	char c = maze[b*w+a];
	q.enqueue(nd);
	while (!q.isEmpty()) {
		Node p = q.dequeue();		
		int x = p.x;
		int y = p.y;
		maze[y*w+x] = fill_char;
		//push 4 neighbors...
		//look left
		x = p.x-1;
		y = p.y;
		if (isValid(x, y, c)) {
			q.enqueue(x,y);
			xp[y*w+x].visited = true;
		}
		//look above
		x = p.x;
		y = p.y+1;
		if (isValid(x, y, c)) {
			q.enqueue(x,y);
			xp[y*w+x].visited = true;
		}
		//look right
		x = p.x+1;
		y = p.y;
		if (isValid(x, y, c)) {
			q.enqueue(x,y);
			xp[y*w+x].visited = true;
		}
		x = p.x;
		y = p.y-1;
		//look below
		if (isValid(x, y, c)) {
			q.enqueue(x,y);
			xp[y*w+x].visited = true;
		}
		showMaze();
		usleep(50000);
	}
}

void fillMaze(char fill_char) {
	int n = w * h;
	for (int i=0; i<n; i++) {
		if (maze[i] == ' ') {
			maze[i] = fill_char;
			showMaze();
			usleep(10000);
		}
	}
}

void showMaze() {
	cout << endl;	
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cout << maze[i*w+j];
		}
		cout << endl;	
	}
	cout << endl;	
}















