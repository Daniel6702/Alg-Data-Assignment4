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
	Comparable tmp = std::move(array[node]);

	for (; node * 2 <= currentSize; node = child) {
		child = node * 2;
		if (child != currentSize && array[child + 1] > array[child])
			++child;
		if (array[child] > tmp)
			array[node] = std::move(array[child]);
		else
			break;
	}
	array[node] = std::move(tmp);
}
