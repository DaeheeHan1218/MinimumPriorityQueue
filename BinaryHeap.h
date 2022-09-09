#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        //Implement the below 4 methods. Please note these methods are not from MPQ.h
        //BinaryHeap class does not inherit MPQ class 
        //Implement BinaryHeap insert operation
        //Also implement upheap and downheap operations (functions provided below) and call them from wherever necessary
        void insert(const T& data){
			elements.push_back(data);
			size++;
			up_heap(size - 1);
		}
        // Return true if BinaryHeap is empty otherwise false
        bool is_empty(){
			return (size == 0);
		}
        // Return minimum element in the BinaryHeap
        T min(){
			if(size <= 0){
				throw std::invalid_argument( "remove called on empty heap" );
			}
			return elements[0];
		}
        // Remove minimum element in the BinaryHeap and return it
        T remove_min(){
			if(size == 0){
				throw std::invalid_argument( "remove called on empty heap" );
			}
			T min_val = elements[0];
			elements[0] = elements[size - 1];
			elements.pop_back();
			down_heap(0);
			size--;
			return min_val;
		}
    private:
        //
        std::vector<T> elements;
        int size = 0;
        //Implement down heap operation
        void down_heap(int i);
        //Implement up heap operation
        void up_heap(int i);

        //Pre-implemented helper functions
        //swaps two elements at positions a and b
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        //Binary tree (Complete Binary tree) can be represented in vector form and hence, stored in a vector. 
        //Returns the right child index of current index
        int right_child(int i) {return 2*i + 2;}
        //Returns the left child index of current index
        int left_child(int i) {return 2*i + 1;}
        //Returns the parent index of current index
        int parent(int i) {return floor((i-1)/2);}
        //Checks if current index is an internal node
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        //Checks if current index is a leaf
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i){
    int parent_index = parent(i);
    /*
     * Can be computed iteratively or recursively
     */
	int curr_index = i;
	while(parent_index >= 0){
		if(elements[curr_index] < elements[parent_index]){
			swap(curr_index, parent_index);
			curr_index = parent_index;
			parent_index = parent(parent_index);
		}
		else{
			break;
		}
	}
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i){
    int right_index = right_child(i);
    int left_index = left_child(i);
    /*
     * Can be computed iteratively or recursively
    */
	int curr_index = i;
	while(is_internal(curr_index)){
		if(right_index < size){
		    if(elements[right_index] < elements[left_index]){
    		    if(elements[right_index] < elements[curr_index]){
    		        swap(right_index, curr_index);
    		        curr_index = right_index;
    		        right_index = right_child(curr_index);
    		        left_index = left_child(curr_index);
    		    }
    		    else{
    		        break;
    		    }
		    }
    		else if(elements[left_index] < elements[curr_index]){
    		    swap(left_index, curr_index);
    		    curr_index = left_index;
    		    right_index = right_child(curr_index);
    		    left_index = left_child(curr_index);
    		}
    		else{
    		    break;
		    }
		}
		else if(left_index < size){
		    if(elements[left_index] < elements[curr_index]){
		        swap(left_index, curr_index);
		        curr_index = left_index;
		        right_index = right_child(curr_index);
		        left_index = left_child(curr_index);
		    }
		    else{
		        break;
		    }
		}
		else{
		    break;
		}
	}
}
#endif