#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void minHeapify(std::vector<Comparable> &array, int node, int n) {
    // Store the value at the current node in a temporary variable
    Comparable tmp = std::move(array[node]);
    // Loop until the current node has at least one child
    for (; node * 2 + 1 < n; node = child) {
        // Calculate the index of the left child
        int child = node * 2 + 1;
        // If the right child exists and is smaller than the left child, use the right child
        if (child != n - 1 && array[child + 1] < array[child])
            ++child;
        // If the value of the child is smaller than the temporary value,
        // move the child's value up to the current node
        if (array[child] < tmp)
            array[node] = std::move(array[child]);
        else
            break;  // Break the loop if the heap property is satisfied
    }
    // Place the temporary value in its correct position
    array[node] = std::move(tmp);
}

/**
 * Standard heapsort.
 */
template <typename Comparable>
void heapSort(vector<Comparable> &array) {
	// The loop runs for approximately N/2 iterations, and within each iteration, 
	// the minHeapify function is called. The time complexity of minHeapify is O(log N).
	for (int i = array.size() / 2 - 1; i >= 0; --i)	/* buildHeap */
		minHeapify(array, i, array.size());
	// After building the heap, the code performs heap sort by repeatedly extracting the minimum element. 
	// The outer loop runs for N-1 iterations, and within each iteration, minHeapify is called. 
	// Since minHeapify has a time complexity of O(log N), the overall time complexity of this part is O(N * log N).
	for (int j = array.size() - 1; j > 0; --j) {
		std::swap(array[0], array[j]);	/* deleteMin */
		minHeapify(array, 0, j);
	}
	std::reverse(array.begin(), array.end());
}

#endif
