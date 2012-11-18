#include "/home/onyuksel/courses/340/progs/12s/p2/prog2.h"

// Driver program to test two search algorithms - linear
// search and binary search - on vector of integers.

int main ( )
{
    // Define two empty vectors of ints for given sizes and
    // fill them by random integers for given seed values.

    vector <int> A ( ARR_SIZE ), B ( TEST_ARR_SIZE );
    Vectors ( A, B, SEED1, SEED2 );

    // Print test (1st) vector before sorting its elements.
    cout << "Random Numbers Before Sorting:\n\n";
    printVector ( A );

    // Sort test (1st) vector.
    sortVector ( A );

    // Print test (1st) vector after sorting its elements.
    cout << "\nRandom Numbers After Sorting:\n\n";
    printVector ( A );

    // Print test values from 2nd vector.
    cout << "\nRandom Numbers Searched:\n\n";
    printVector ( B );

    // Search each test value from 2nd vector in 1st vector
    // using linear search algorithm.

    cout << "\nLinear Search:\n";
    search ( A, B, linearSearch );

    // Search each test value from 2nd vector in 1st vector
    // using binary search algorithm.

    cout << "\nBinary Search:\n";
    search ( A, B, binarySearch );

    return 0;
}

// Generic search algorithm: It takes pointer to search routine f ( ),
// then it calls f ( ) for each element v2 in v1. It also computes tot 
// no of successful searches totalSucCnt. To print final statistics,
// it calls print routine printStat ( ).

void search (const vector <int>& v1, const vector <int>& v2,
    bool ( *f )( const vector <int>&, int ))
{
    int n = v2.size ( );
    int totalSucCnt = 0;

    for ( int i = 0; i < n; i++ )
        if ( f ( v1, v2[i] ) ) totalSucCnt++;

    printStat ( totalSucCnt, v2.size ( ));
}

// Prints avg no of comparisons and percent of successful searches as
// right-aligned, floating-pt nos on stdout.

void printStat ( int totalSucCnt, int vectorSz )
{
    cout << setiosflags ( ios::fixed | ios::showpoint )
         << setprecision ( 2 );

    cout << "\tPercent of Successful Searches = "
         << setw ( 5 ) << 100 * ( float ) totalSucCnt / vectorSz << "%\n";
}
