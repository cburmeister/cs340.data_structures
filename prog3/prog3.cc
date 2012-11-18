//////////////////////////////////////////////////////////////////
// NAME: Corey Burmeister
// ASSIGNMENT: 3
// DUE: 2/9/2012
//////////////////////////////////////////////////////////////////

#include "/home/onyuksel/courses/340/common/340.h"

void sieve ( set <int> &, int );
void print_primes ( const set <int> & );

int main()
{
	int UPPER_LIMIT; // storage for limit
	set <int> intSet; // storage for set

	cout << "Enter a Boundary: ";
	cin >> UPPER_LIMIT;
	cout << endl;

	sieve( intSet, UPPER_LIMIT ); // sift the set
	print_primes( intSet ); // print the set

	return 0;
}

// Sift the Twos and sift the Threes,
// The Sieve of Eratosthenes.
// When the multiples sublime,
// The numbers that remain are Prime.
void sieve ( set <int>& s, int n )
{
	// insert elements into set up to given limit
	for(int i = 2; i < n + 1; i++) s.insert(i);

	// loop through each key ( 2,3..n )
	for(int i = 2; i < n; i++)
	{
		// remove multiples of i such that i * i >= n
		for(int j = i * i; j <= n; j += i)
		{
			s.erase(j);
		}
	}
}

// print primes ( 16 per line )
void print_primes ( const set <int>& s )
{
	int count = 0;
	set <int>::iterator it;
	for(it = s.begin(); it != s.end(); it++) 
	{
		if(count == 16)
		{
			count = 0;
			cout << endl;
		}
		count++;
		cout << *it << "  ";
	}
	cout << endl;
}