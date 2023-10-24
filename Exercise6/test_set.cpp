#include <iostream>
#include "set.h"
#include "binary_search_tree.h"

using namespace std;

int main() {
	Set<int> set;

	set.push(4);
	set.push(0);
	set.push(2);
	set.push(7);
	set.push(0);
	set.push(2);
	set.push(6);
	set.push(4);
	set.push(12);
	set.push(11);
	set.push(8);
	set.push(1);
	set.push(5);
	set.push(0);
	set.push(3);
	set.push(2);
	set.push(7);
	set.push(1);
	set.push(1);
	set.push(1);
	set.push(9);
	set.push(7);
	set.push(11);
	set.push(1);
	
	//Set<int> set = set;

	Set<int>::iterator it = set.insert(-1);
	
	cout << *it << endl;
	if (++it != set.end())
		cout << *it << endl;
	
	// Insert duplicate and print succ to prove that no new node is inserted
	it = set.insert(4);
	cout << *it << endl;
	if (++it != set.end())
		cout << *it << endl;
	
	it = set.insert(20);
	cout << *it << endl;
	if (++it != set.end())
		cout << *it << endl;

	it = set.find(15);
	if (++it != set.end())
		cout << *it << endl;
	it = set.find(12);
	cout << *it << endl;
	if (++it != set.end())
		cout << *it << endl;
	it = set.erase(it);
	if (it != set.end())
		cout << *it << endl;

	it = set.find(4);
	it = set.erase(it);
	if (it != set.end())
		cout << *it << endl;

	for (Set<int>::iterator it = set.begin(); it != set.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
	
}
