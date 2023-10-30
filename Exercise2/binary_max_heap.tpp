/*
Just modified all the < to > and changed the names of the methods
*/
template<typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable& x) {
    if (currentSize == array.size() - 1)
        array.resize(array.size() * 2);

    int node = ++currentSize;
    Comparable copy = x;

    array[0] = std::move(copy);
    for (; x > array[node / 2]; node /= 2)
        array[node] = std::move(array[node / 2]);
    array[node] = std::move(array[0]);
}


template<typename Comparable>
const Comparable& BinaryHeap<Comparable>::findMax() const {
    if (isEmpty()) throw underflow_error{};
    return array[1];
}

template<typename Comparable>
void BinaryHeap<Comparable>::deleteMax() {  
    if (isEmpty()) throw underflow_error("heap is empty.");
    array[1] = std::move(array[currentSize--]);
    maxHeapify(1); 
}
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMax(Comparable & minItem) {
	if (isEmpty()) throw underflow_error("heap is empty.");
	minItem = std::move(array[1]);
	array[1] = std::move(array[currentSize--]);
	maxHeapify(1);
}

template<typename Comparable>
void BinaryHeap<Comparable>::buildHeap() {
	for (int i = currentSize / 2; i > 0; --i) {
		maxHeapify(i);
	}
}

template<typename Comparable>
void BinaryHeap<Comparable>::maxHeapify(int node) {
	int child;
	// Store the element at the current node temporarily
	Comparable tmp = std::move(array[node]);
	// Start the loop to maintain the max heap property
	for (; node * 2 <= currentSize; node = child) {
		// Determine the left child of the current node
		child = node * 2;
		// Check if there is a right child and if it is greater than the left child
		if (child != currentSize && array[child + 1] > array[child])
			++child;
		// Compare the larger child with the temporary element
		if (array[child] > tmp)
			// If the child is larger, move it up in the heap
			array[node] = std::move(array[child]);
		else
			// If the temporary element is larger, break out of the loop
			break;
	}
	// Place the temporary element in its correct position
	array[node] = std::move(tmp);
}
