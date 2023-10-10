#include "binary_max_heap.h"
#include <vector>
#include <unordered_map>
#include <iostream>

/*The PriorityQueue associates items with priorities and utilizes a max-heap to manage these priorities*/
template <typename Item, typename Priority>
class PriorityQueue {
private:
    BinaryHeap<Priority> binaryHeap;
    std::unordered_map<Priority, std::vector<Item>> map;

public:
    PriorityQueue(int capacity = 100) : binaryHeap(capacity) {}

    void insert(const Item& item, const Priority& priority) {
        //insert the priority into the heap
        binaryHeap.insert(priority);
        //map the priority to the item
        map[priority].push_back(item);
    }

    Item dequeue() {
        if (binaryHeap.isEmpty()) {
            throw std::underflow_error("The priority queue is empty.");
        }

        //get the max priority value
        Priority maxPriority;
        binaryHeap.deleteMax(maxPriority);

        //get the item with the max priority and remove it
        Item item = map[maxPriority].back();
        map[maxPriority].pop_back();

        if (map[maxPriority].empty()) {
            map.erase(maxPriority);
        }

        return item;
    }
};