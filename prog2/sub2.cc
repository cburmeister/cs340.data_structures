//////////////////////////////////////////////////////////////////
// NAME: Corey Burmeister
// ASSIGNMENT: 2
// DUE: 2/1/2012
//////////////////////////////////////////////////////////////////

#include "prog2.h"

void Vectors ( vector <int>& v1, vector <int>& v2, int s1, int s2 )
{
	srand(s1); // initialize RNG
    v1.clear();
    for(int i=0;i<(ARR_SIZE);i++) { v1.push_back(rand() % RND_NO_RANGE + 1); }

    srand(s2); // initialize RNG
    v2.clear();
    for(int i=0;i<TEST_ARR_SIZE;i++) { v2.push_back(rand( ) % RND_NO_RANGE + 1); }
}

void sortVector ( vector <int>& v )
{
	sort( v.begin(), v.end() ); // sort in ascending order
}

 bool linearSearch ( const vector <int>& v, int x )
 {	
	int i;

    for(i=0; i<ARR_SIZE; i++)
    {
        if( v.at(i) == x )
            return true; // found element
    }
	
	return false; // did not find element
 }
 
 bool binarySearch ( const vector <int>& v, int x )
 {
	if ( binary_search( v.begin(), v.end(), x ) ) return true;
	else return false; // did not find element
 }
 
void printVector ( const vector <int>& v )
{
	int count=0;

    for( unsigned int i=0; i<v.size(); i++ )
    {
        if( count == LINE_SIZE )
        {
            count = 0;
            cout << endl;
        }
        count++;

        cout << v.at(i) << " ";
    }
}