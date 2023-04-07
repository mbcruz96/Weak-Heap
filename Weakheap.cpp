#include "Weakheap.h"
#include <iostream>

// Constructors
WeakHeap::WeakHeap(const int& v){
	heap.push_back(v);
  revbits.push_back(0);
	heapify();
}

WeakHeap::WeakHeap(const std::vector<int>& h){
  if(heap.size() > 0)
    heap.clear();
  if(revbits.size() > 0)
    revbits.clear();
  for(int i=0; i < h.size(); i++){
    heap.push_back(h[i]);
    revbits.push_back(0);
  }
  heapify();
}

// Destructor 
WeakHeap::~WeakHeap(){
  heap.clear();
  revbits.clear();
}


// Member fucntions
int::WeakHeap::get_size()const{
	return heap.size();
}

bool::WeakHeap::isEmpty()const{
	return (heap.size() == 0);
}

void::WeakHeap::insert(int v){
	heap.push_back(v);
  revbits.push_back(0);
  if (revbits[revbits.size()-1] && 1 == 0)
    swaptree(parent(revbits.size()-1));
  siftup(heap.size()-1);
}

int::WeakHeap::deleteMin(){
  int item = -1;
  if(heap.size() > 0){
    item = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    revbits.pop_back();
    if(heap.size() > 1)
      siftdown(0);
  }
  return item;
}

int*::WeakHeap::sort(){
  std::cout << "\n\nSorted order:\n";
  int sorted[heap.size()];
  for(int x = 0; x < heap.size(); x++){
    int item = deleteMin();
    sorted[x] = item;
    std::cout << item << " ";
  }
  std::cout << std::endl;
  return sorted;
}

void::WeakHeap::print()const{
  std::cout << "\nHeap: \n";
  for(int i = 0; i < heap.size(); i++){
    std::cout << heap[i] << " ";
  }
  std::cout << "\n\nReverse bits: \n";
  for(int i = 0; i < revbits.size(); i++){
    std::cout << revbits[i] << " ";
  }
  std::cout << std::endl;
}



// Utility functions
void::WeakHeap::heapify(){
  for(int i = heap.size()-1; i > 0; --i){
    int x = getDistAncestor(i);
    join(x,i);
  }
}

int::WeakHeap::rchild(int index)const{
  return(2*index + 1 - revbits[index]);
}

int::WeakHeap::lchild(int index)const{
  if(index != 0)
    return(2*index + revbits[index]);
  else
    return 0;
}

int::WeakHeap::parent(int index)const{
  return(index/2);
}

int::WeakHeap::getDistAncestor(int index)const{
  int p = parent(index);
  if (index == lchild(p)){
    return parent(p);
  }
  else{
    return parent(index);
  }
}

void::WeakHeap::swaptree(int index){
  revbits[index] = 1 - revbits[index];
}

bool::WeakHeap::join(int x, int y){
  if(heap[y] < heap[x]){
    std::swap(heap[x], heap[y]);
    swaptree(y);
    return false;
  }
  return true;
}

void::WeakHeap::siftup(int index){
  while(index != 0){
    int ancestor = getDistAncestor(index);
    if(join(ancestor, index))
        break;
    index = ancestor;
  }
}

void::WeakHeap::siftdown(int index){
  int i = rchild(index);
  while(lchild(i) < heap.size()){
    i = lchild(i);
  }
  while(i != index){
    join(index, i);
    i = parent(i);
  }
}