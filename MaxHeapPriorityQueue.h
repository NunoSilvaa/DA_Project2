//
// Created by nmls1 on 24/05/2022.
//

#ifndef PROJETODA_2_MAXHEAPPRIORITYQUEUE_H
#define PROJETODA_2_MAXHEAPPRIORITYQUEUE_H

#include <vector>

template <class T>
class MaxHeapPriorityQueue {
    std::vector<T *> H;
    void shiftUp(unsigned i);
    void shiftDown(unsigned i);
    inline void set(unsigned i, T * x);
public:
    MaxHeapPriorityQueue();
    bool empty();
    void insert(T * x);
    T * extractMin();
    T * extractMax();
    void changePriority(T * x);
    T * getMax();
    void print();
    int getSize();
};

#define rightChild(i) ((2 * i) + 1)
#define leftChild(i) ((2 * i))
#define parent(i) ((i) / 2)

//int H[50];
//int size = -1;

// Function to return the index of the
// parent node of a given node
/*int parent(int i)
{

    return (i - 1) / 2;
}*/

// Function to return the index of the
// left child of the given node
/*int leftChild(int i)
{

    return ((2 * i) + 1);
}
*/
// Function to return the index of the
// right child of the given node
/*int rightChild(int i)
{

    return ((2 * i) + 2);
}*/

template <class T>
MaxHeapPriorityQueue<T>::MaxHeapPriorityQueue() {
    H.push_back(nullptr);
    // indices will be used starting in 1
    // to facilitate parent/child calculations
}

// Function to shift up the node in order
// to maintain the heap property
template <class T>
bool MaxHeapPriorityQueue<T>::empty() {
    return H.size() == 1;
}

template <class T>
void MaxHeapPriorityQueue<T>::shiftUp(unsigned i)
{
    auto x = H[i];
    while (i > 1 && *x < *H[parent(i)]) {
        set(i, H[parent(i)]);
        i = parent(i);
    }
    //std::cout << "i: " << i << " " << x->cap << " ";
    set(i, x);
    /*while (i > 1 && H[parent(i)] < H[i]) {
        std::cout << H[parent(i)]->cap << " ";
        // Swap parent and current node
        std::swap(H[parent(i)], H[i]);

        // Update i to parent of i
        i = parent(i);
    }*/
    //std::swap(H[0], H[i]);
}

// Function to shift down the node in
// order to maintain the heap property
template <class T>
void MaxHeapPriorityQueue<T>::shiftDown(unsigned int i) {
    auto x = H[i];
    //std::cout << H.size() << " ";
    while (true) {
        unsigned k = leftChild(i);
        if (k >= H.size())
            break;
        if (k+1 < H.size() && *H[k+1] < *H[k])
            ++k; // right child of i
        if ( ! (*H[k] < *x) )
            break;
        set(i, H[k]);
        i = k;
    }
    set(i, x);

    /*int maxIndex = i;

    // Left Child
    int l = leftChild(i);

    if (l <= H.size() && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    // Right Child
    int r = rightChild(i);

    if (r <= H.size() && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    // If i not same as maxIndex
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }*/
}

// Function to insert a new element
// in the Binary Heap
template <class T>
void MaxHeapPriorityQueue<T>::insert(T *x) {
    //size = size + 1;
    H.push_back(x);
    //std::cout << " add " << H.size() << " ";
    //H[H.size() - 1] = x;

    // Shift Up to maintain heap property
    shiftUp(H.size() - 1);
}

// Function to extract the element with
// maximum priority
template <class T>
T * MaxHeapPriorityQueue<T>::extractMax() {
    auto result = H[1];

    // Replace the value at the root
    // with the last leaf
    //H[1] = H[H.size()];
    H[1] = H.back();
    H.pop_back();
    //size = size - 1;
    /*if(H.size() > 1) shiftDown(1);
    result->queueIndex = 0;*/
    // Shift down the replaced element
    // to maintain the heap property
    shiftDown(1);
    return result;
}

// Function to change the priority
// of an element
template <class T>
void MaxHeapPriorityQueue<T>::changePriority(T * x){
    shiftUp(x->queueIndex);
    /*int oldp = H[i];
    H[i] = p;

    if (p > oldp) {
        shiftUp(i);
    }
    else {
        shiftDown(i);
    }*/
}

// Function to get value of the current
// maximum element
template <class T>
T * MaxHeapPriorityQueue<T>::getMax()
{

    return H[1];
}

// Function to remove the element
// located at given index
/*void remove(int i)
{
    H[i] = getMax() + 1;

    // Shift the node to the root
    // of the heap
    shiftUp(i);

    // Extract the node
    extractMax();
}*/
template <class T>
void MaxHeapPriorityQueue<T>::print(){
    int i = 1;
    std::cout << "\nPriority Queue : ";
    //std::cout << H[1]->cap;
    while (i <= 6) {
        std::cout << H[i]->cap << " ";
        i++;
    }
}

template <class T>
void MaxHeapPriorityQueue<T>::set(unsigned i, T * x) {
    H[i] = x;
    x->queueIndex = i;
}

template <class T>
int MaxHeapPriorityQueue<T>::getSize() {
    return H.size();
}



#endif //PROJETODA_2_MAXHEAPPRIORITYQUEUE_H
