#include "Weakheap.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
  cout << "\nprogram commencing...\n\n";

  // heap of 20 elements
  // sorting all elements
  cout << "\nOriginal array of 20 elements: \n";
  vector<int> vec;
  for(int x = 0; x < 20; x++){
    int i = rand() % 100;
    vec.push_back(i);
    cout << i << " ";
  }
  cout << endl;
  WeakHeap heap(vec);
  heap.print();
  //vec.clear();
  int* sorted = heap.sort();

  cout << "\nOriginal array of 100 elements: \n";
  for(int x = 0; x < 100; x++){
    int i = rand() % 500;
    heap.insert(i);
    cout << i << " ";
  }
  cout << endl;
  heap.print();
  //vec.clear();
  int* sorted2 = heap.sort();
  
  cout << "\nOriginal array of 500 elements: \n";
  for(int x = 0; x < 500; x++){
    int i = rand() % 100;
    heap.insert(i);
    cout << i << " ";
  }
  cout << endl;
  heap.print();
  //vec.clear();
  int* sorted3 = heap.sort();

  cout << "\n\nterminating program...\n\n";
	return 0;
}