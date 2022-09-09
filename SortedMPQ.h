#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::list
   // For remove_min() and min() throw exception if the SortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
  private:
	std::list<T> pq;
  public:
   T remove_min(){
		if(pq.size() == 0){
			throw std::invalid_argument( "remove called on empty queue" );
		}
		T min_val = pq.front();
		pq.pop_front();
		return min_val;
	}
	
	T min(){
		if(pq.size() == 0){
			throw std::invalid_argument( "remove called on empty queue" );
		}
		return pq.front();
	}
	
	bool is_empty(){
		return (0 == pq.size());
	}
	
	void insert(const T& data){
		if(pq.size() == 0){
			pq.push_back(data);
		}
		else{
		    bool inserted = false;
		    typename std::list<T>::iterator it;
            for(it = pq.begin(); it != pq.end(); ++it){
                if(data < *it){
                    pq.insert(it, data);
                    inserted = true;
                    break;
                }
            }
            if(!inserted){
                pq.push_back(data);
            }
		}
	}
};

#endif