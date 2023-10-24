#include <vector>
#include "binary_search_tree.h"

using namespace std;

template<typename Comparable>
class Set {
  private:
	size_t theSize = 0;
	BinarySearchTree<Comparable> tree;

  public:
	Set() { }

	~Set() { clear(); }

	Set(const Set& s) {
		for (auto& x : s) {
			push(x);
		}
	}

	void clear() {
		tree.makeEmpty();
		theSize = 0;
	}

	size_t size() const {
		return theSize;
	}

	bool empty() const {
		return size() == 0;
	}

	void push(const Comparable& t) {
		tree.insert(t);
		theSize++;
	}

	friend class BinarySearchTree<Comparable>;
	typedef typename BinarySearchTree<Comparable>::iterator iterator;

	iterator begin() const {
		return iterator(tree.findMin());
	}

	iterator end() const {
		return iterator(tree.findMax());
	}

	iterator insert(const Comparable& t) {
		cout << "1";
		iterator itr = find(t);
		cout << "5";
		if (itr == end()) {
			itr = tree.insert(t);
			theSize++;
		}
	}

	iterator find(const Comparable& t) {
		cout << "2";
		iterator itr = begin();
		cout << "3";
		while (itr != end() && *itr != t) {
			++itr;
			cout << "itr: " << *itr << endl;
		}
		cout << "4";
		return itr;
	}

	iterator erase(iterator& itr) {
		iterator next = itr;
		++next;
		tree.remove(*itr);
		theSize--;
		return next;
	}
};
