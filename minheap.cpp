#include "minheap.hpp"
#include <iostream>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

MinHeap::MinHeap(int size) {
    heap_size = 0;
    capacity = size;
    harr = new int[size];
}

MinHeap::~MinHeap() {
    delete[] harr;
    harr = nullptr; // Reset the pointer to avoid using deallocated memory
}

int MinHeap::left(int parent) {
    int i = parent * 2 + 1;
    return (i < heap_size) ? i : -1;
}

int MinHeap::right(int parent) {
    int i = parent * 2 + 2;
    return (i < heap_size) ? i : -1;
}

int MinHeap::parent(int child) {
    if (child != 0) {
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}

int MinHeap::size() {
    return heap_size;
}

void MinHeap::insert(int element) {
    if (heap_size == capacity) {
        std::cout << "Heap is full. Cannot insert more elements." << std::endl;
        return;
    }

    // Insert the new element at the end
    int i = heap_size;
    harr[i] = element;
    heap_size++;

    // Fix the min heap property
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin() {
    if (heap_size <= 0)
        return -1;

    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value and remove it from the heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l != -1 && harr[l] < harr[i])
        smallest = l;

    if (r != -1 && harr[r] < harr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::display() {
    std::cout << "MinHeap:- ";
    std::cout << heap_size << std::endl;
    for (int i = 0; i < heap_size; i++) {
        std::cout << harr[i] << " ";
    }
    std::cout << std::endl;
}

void MinHeap::heapsort(vector<int>& A, int n) {
    int* tempArr = new int[n];  // Temporary array for sorting

    // Build a min-heap
    heap_size = n;
    capacity = n;
    harr = tempArr;  // Use the temporary array for heap operations

    for (int i = 0; i < n; i++)
        harr[i] = A[i];

    for (int i = (n / 2) - 1; i >= 0; i--)
        MinHeapify(i);

    // Extract elements from the min-heap in sorted order
    for (int i = n - 1; i > 0; i--) {
        swap(&harr[0], &harr[i]);
        heap_size--;
        MinHeapify(0);
    }

    // Copy sorted elements back to the input vector
    for (int i = 0; i < n; i++)
        A[i] = harr[i];

    delete[] tempArr;  // Deallocate the temporary array
    harr = nullptr;   // Reset the pointer to avoid using deallocated memory
}