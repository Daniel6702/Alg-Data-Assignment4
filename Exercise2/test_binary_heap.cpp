#include <iostream>
#include <sstream>
#include <string>

//#include "binary_max_heap.h"
#include "priority_queue.h"
using namespace std;

	// Test program
int main() {
	
	int minItem = 10000;
	int maxItem = 99999;
	BinaryHeap<int> h;
	int x;
	for (int i = 37; i != 0; i = (i + 37) % maxItem) {
		if (i >= minItem) {
			h.insert(i);
		}
	}
	for (int i = maxItem-1; i > minItem; --i) {
		h.deleteMax(x);
		if (x != i) {
			cout << x << "   Oops! " << i << endl;
		}
	}
	cout << "\nIf nothing was printed before, the max heap works!\n\n";
	
	/*PRIORITY QUEUE TEST*/
	//<item, priority>
	PriorityQueue<std::string, int> pq;

    pq.insert("high", 3);
    pq.insert("medium", 2);
	pq.insert("low", 1);
	pq.insert("medium2", 2);
	pq.insert("low2", 1);
    pq.insert("high2", 3);

	//Should dequeue the items with the highest priority first. Items that has the same priority should be dequeued in the order they were inserted.
    std::cout << "Dequeued: " << pq.dequeue() << endl; 
    std::cout << "Dequeued: " << pq.dequeue() << endl;
	std::cout << "Dequeued: " << pq.dequeue() << endl; 
    std::cout << "Dequeued: " << pq.dequeue() << endl;
	std::cout << "Dequeued: " << pq.dequeue() << endl; 
    std::cout << "Dequeued: " << pq.dequeue() << endl;

	return 0;
}
