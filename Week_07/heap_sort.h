#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void minHeapify(vector<Comparable> &array, int node, int n) {
	int child;
	Comparable tmp = std::move(array[node]);
	// his condition ensures that the loop continues as long as the left child of the current node is within the bounds of the heap.
	// The left child index is calculated as (node * 2 + 1), which represents the position of the left child in a binary heap.
	// This part is O(log N) because, in the worst case, the loop will run for each level of the binary heap, 
	// and the height of a binary heap is logarithmic with respect to the number of elements (N).
	for (; node * 2 + 1 < n; node = child) {
		child = node * 2 + 1;
		if (child != n - 1 && array[child + 1] < array[child])
			++child;
		if (array[child] < tmp)
			array[node] = std::move(array[child]);
		else
			break;
	}
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
