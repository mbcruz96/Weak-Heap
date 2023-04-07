#ifndef WEAKHEAP_H
#define WEAKHEAP_H
#include <vector>

class WeakHeap{
	public:
    /*Constructors:
        - inputs: an integer or vector of integers
        - intializes heap and generates reverse bit array
    */
		WeakHeap(const int&);
		WeakHeap(const std::vector<int>&);
		~WeakHeap();

    // returns number of elements in heap
		int get_size()const;

    // returns true if there are no elements in the array
		bool isEmpty()const;

    // inserts an integer into the heap
    // input: integer element
		void insert(int);

    // deletes and returns the smallest element in the heap
    int deleteMin();

    // deletes minimum element until heap is empty
    // prints the sorted order of the heap
    int* sort();

    // prints the current elements of the heap 
    void print()const;

	private:
		std::vector<int> heap;
    std::vector<int> revbits;

		// Utility functions

    // Returns the index of a nodes right child
    // input: index
    int rchild(int)const;

    // Returns the index of a nodes right child
    // input: index
    int lchild(int)const;

    // Returns the index of a nodes right child
    // input: index
    int parent(int)const;

    // Returns the 
    int getDistAncestor(int)const;
    void swaptree(int);
    
    void heapify();
    bool join(int, int);
    void siftup(int);
    void siftdown(int);

};
#endif