#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
 */
template <typename T>
class BinaryHeapMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // It is enough if the 4 methods in  BinaryHeapMPQ calls the corresponding implemented methods in BinaryHeap.h.
   // To hold the elements use BinaryHeap (from BinaryHeap.h)
   // For remove_min() and min() throw exception if the BinaryHeapMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
  private:
	BinaryHeap<T> bh;
  public:
	T remove_min(){
		if(bh.is_empty()){
			throw std::invalid_argument( "remove called on empty queue" );
		}
		return bh.remove_min();
	}
	T min(){
		if(bh.is_empty()){
			throw std::invalid_argument( "remove called on empty queue" );
		}
		return bh.min();
	}
	bool is_empty(){
		return bh.is_empty();
	}
	void insert(const T& data){
		bh.insert(data);
	}
};

#endif