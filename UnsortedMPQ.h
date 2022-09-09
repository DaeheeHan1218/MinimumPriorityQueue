#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

/**
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::vector
   // For remove_min() and min() just throw exception if the UnsortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
  private:
	std::vector<T> pq;
  public:
	T remove_min(){
		if(pq.size() == 0){
			throw std::invalid_argument( "remove called on empty queue" );
		}
		T min_val = pq[0];
		int min_index = 0;
		for(int i = 0; i < pq.size(); i++){
			if(pq[i] < min_val){
				min_val = pq[i];
				min_index = i;
			}
		}
		pq.erase(pq.begin() + min_index);
		return min_val;
	}
	
	T min(){
		if(pq.size() == 0){
			throw std::invalid_argument( "remove called on empty queue" );
		}
		T min_val = pq[0];
		int i;
		for(i = 0; i < pq.size(); i++){
			if(pq[i] < min_val){
				min_val = pq[i];
			}
		}
		return min_val;
	}
	
	bool is_empty(){
		return (0 == pq.size());
	}
	
	void insert(const T& data){
		pq.push_back(data);
	}
};

#endif