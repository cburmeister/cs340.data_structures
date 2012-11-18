//////////////////////////////////////////////////////////////////
// NAME: Corey Burmeister
// ASSIGNMENT: 9
// DUE: 4/13/2012
//////////////////////////////////////////////////////////////////

#include "/home/onyuksel/courses/340/progs/12s/p9/prog9.h"

int main ( )
{
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 9 - Output ***\n\n";

    // first heap

    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int, INT_SZ, INT_LN > print1 ( v1.size ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    cout << "first heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    cout << "first heap - ascending order with absolute values:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, abs_less < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    // second heap

    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float, FLT_SZ, FLT_LN > print2 ( v2.size ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    cout << "second heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    cout << "second heap - ascending order with absolute values:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, abs_less < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    // third heap

    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string, STR_SZ, STR_LN > print3 ( v3.size ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    cout << "third heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    return 0;
}

// opens input file for reading & inserts items into vector
template <class T>
void get_list ( vector <T>& v, const char* path )
{
	v.clear();
	T temp;                     // Temp data to read into
	ifstream inFile;
	inFile.open( path );        // Open file
	if (!inFile)
	{
		cout << "Error, Unable to open file." << endl;
		exit(1);
	}
	inFile >> temp;             // Read first entry
	while (!inFile.eof())       //read in until end of file
	{
		v.push_back(temp);      // Insert in vector
		inFile >> temp;         // read next entry
	}
	inFile.close();            // Close file
}

// construct heap while comparing elements with pred
template <class T, class P>
void construct_heap ( vector <T>& v, P pred )
{
	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
}

// compares absolute value of x and y
template <class T>
bool abs_less <T> :: operator ( ) ( const T& x, const T& y ) const
{
	if (abs(x) < abs(y))
		return true;
	else
		return false;
}

// prints heaped vector
template <class T, const int W, const int L>
void print_list <T, W, L> :: operator ( ) ( const T& x )
{
	if ( cnt <= sz )
	{
		if (cnt % L == 0)
		{
			cout << endl;
		}
		cout << fixed << setprecision(2) << setw(W) << x << " ";
		cnt++;
	}
	if (cnt == sz)
		cout << endl << endl;
}

template < class T, const int W, const int L > 
print_list < T, W, L > :: print_list ( const int& s, const int& c )
{
	cnt = c;
	sz = s;
}