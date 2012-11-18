// Header file for program, which implements two search
// algorithms - linear and binary search.

#include "/home/onyuksel/courses/340/common/340.h"

#ifndef H_PROG2
#define H_PROG2

#define ARR_SIZE      200    // size of input vector
#define TEST_ARR_SIZE 100    // size of test vector
#define RND_NO_RANGE  1000   // range for random nums
#define LINE_SIZE     16     // max num of items printed on single line

#define SEED1 1              // seed value for RNG1
#define SEED2 3              // seed value for RNG2

void sortVector ( vector <int>& );                      // routine for sort
bool linearSearch ( const vector <int>&, int );         // routine for linear search
bool binarySearch ( const vector <int>&, int );         // routine for binary search
void search ( const vector <int>&, const vector <int>&,
    bool ( * ) ( const vector <int>&, int ) );          // routine for generic search

void Vectors ( vector <int>&, vector <int>&, int, int );// constructs vectors of ints   
void printVector ( const vector <int>& );               // prints vector of ints 
void printStat ( int, int );                            // prints final statistics
#endif
