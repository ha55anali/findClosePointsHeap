#pragma once

#include <iostream>
using namespace std;

template <class T>
class myHeap {
public:
	myHeap(int mSize);
	~myHeap();

	void insert(T const& d);
	T& getTop();
	void removeTop();

	void remove(int index);

	T& operator[](int n) {
		return h[n + 1];
	}

	int getSize() {
		return currSize;
	}
	
	friend ostream& operator<<(ostream& os, myHeap<T> const& hp) {
		for (int c = 1; c < hp.currSize; ++c) {
			cout << hp.h[c] << endl;
		}

		return os;
	}
private:
	void percolateUp(int index);
	void heapify(int index);

	int mSize;
	int currSize;
	T* h;

};

template <class T>
myHeap<T>::myHeap(int mSize)
	:mSize(mSize)
{
	h = new T[mSize+1];
	currSize = 0;
}

template<class T>
myHeap<T>::~myHeap()
{
	delete h;
}

template<class T>
void myHeap<T>::insert(T const& d)
{
	if (currSize > mSize)
		throw invalid_argument("Heap is full");

	++currSize;
	h[currSize] = d;

	return percolateUp(currSize);
}

template<class T>
T& myHeap<T>::getTop() {
	return h[1];
}

template<class T>
void myHeap<T>::removeTop() {
	swap(h[1], h[currSize]);
	--currSize;

	heapify(1);
}

template <class T>
void myHeap<T>::remove(int index) {
	++index;//heap array starts from 1

	swap(arr[index], arr[currSize]);
	--currSize;

	if (arr[index] > arr[currSize+1])
		percolateUp(index);
	else
		heapify(index);
}

template<class T>
void myHeap<T>::percolateUp(int index)
{

	int parent = index / 2;

	if (parent == 0)
		return;

	if (h[parent] > h[index]) 
		swap(h[parent], h[index]);

	percolateUp(parent);
	

}

template<class T>
void myHeap<T>::heapify(int index)
{
	int max = index;

	if (2 * index <= currSize && h[2 * index] < h[max])
		max = 2 * index;

	if (2 * index + 1 <= currSize && h[2 * index+ 1] < h[max])
		max = 2 * index+ 1;

	if (max != index) {
		swap(h[max], h[index]);
		heapify(max);
	}
}
