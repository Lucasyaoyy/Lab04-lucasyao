// heap.cpp
// Lucas Yao 

#include "heap.h"
#include <iostream>
using namespace std;

void Heap::heapify(int index)
{
  // these are indexes
  int size = vdata.size();
  int minindex = index;
  int left = 2 * index + 1;
  int right = 2 * (index + 1);

  if(left < size && vdata[left] < vdata[minindex])
  minindex = left;

  if(right < size && vdata[right]< vdata[minindex])
  minindex = right;

  if(minindex != index) // we swapped so updates
  {
    swap(vdata[index], vdata[minindex]);
    heapify(minindex);
  }
}

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(vector<int>::iterator start, std::vector<int>::iterator end){
  while(start!=end)
  {
    vdata.push_back(*start);
    start++;
  }

  for(int i = vdata.size()/2 -1; i>=0; i--)
  heapify(i);

}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int index = vdata.size()-1;
  while(index>0 ) // this goes up
  {
    int parent = (index -1) / 2;
    if(vdata[index] < vdata[parent])
    {
      swap(vdata[index], vdata[parent]);
      index = parent;
    }
    else
    break; 
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  int back = vdata.size()-1;
  swap(vdata[0], vdata[back]);
  vdata.pop_back();
  heapify(0);
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    