#ifndef CPU_JOB_H
#define CPU_JOB_H

#include <iostream>

/*
 * CPU_Job holds information for a process to run on the processor
 */
struct CPU_Job {
    int ID;     // process ID
    int length; // process length
    int prior;  // process priority
    //Assigns ID, length and priority
    CPU_Job(int a = 0, int b = 0, int c = 0) : ID(a), length(b), prior(c) {};
};

/*
 * Operator declarations
 */
/**
 * Less than operator to compare the priority of two CPU_Jobs
 * Input: Two Job objects -lhs and rhs
 * Output: Returns true if the priority of lhs is less than priority of rhs
 *   If the priority is the same, compare length.
 *   Returns true if length of lhs is less than length of rhs. If the length is also same, then compare ID. 
 *   Returns true if ID of lhs is less than ID of rhs
 *   Otherwise returns false
 */
bool operator<(const CPU_Job& lhs, const CPU_Job& rhs){
	bool is_less;
	if(lhs.prior < rhs.prior){
		is_less = true;
	}
	else if(lhs.prior > rhs.prior){
		is_less = false;
	}
	else{
		if(lhs.length < rhs.length){
			is_less = true;
		}
		else if(lhs.length > rhs.length){
			is_less = false;
		}
		else{
			if(lhs.ID < rhs.ID){
				is_less = true;
			}
			else{
				is_less = false;
			}
		}
	}
	return is_less;
}
/*
 * Gets a CPU_Job from an input stream.
 * Create one CPU_Job object and assign ID, length and prior data from the input stream. (Assigns one line of data at a time).
 * The format of each line in input file is 3 integers in this order: job ID, length, priority. Look at InputFiles/
 *  In the below case:
 *  7	8	9
 * 7 is job ID, 8 is length and 9 us priority.
 */
std::istream& operator>>(std::istream& in, CPU_Job& job){
	int i, l, p;
	in >> i >> l >> p;
	job.ID = i;
	job.length = l;
	job.prior = p;
	return in;
}
/*
 * Outputs a CPU_Job to an output stream
 * Format: "Job xx with length yy and priority zz"
 * Example: "Job 382 with length 3 and priority -7"
 */
std::ostream& operator<<(std::ostream& out, const CPU_Job& job){
	out << "Job " << job.ID << " with length " << job.length << " and priority " << job.prior;
	return out;
}

#endif