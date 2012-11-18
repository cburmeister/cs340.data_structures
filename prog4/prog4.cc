//////////////////////////////////////////////////////////////////
// NAME: Corey Burmeister
// ASSIGNMENT: 4
// DUE: 2/17/2012
//////////////////////////////////////////////////////////////////

#include "/home/onyuksel/courses/340/common/340.h"

void get_words ( map <string, int>& );
void print_words ( const map <string, int>& );
void clean_entry ( const string&, string& );

int main()
{
	map <string, int> words; // map to store words
	get_words( words ); // calls get words method
	print_words( words ); // calls print words method
	return 0;
}

//////////////////////////////////////////////////////////////////
// METHOD: get_words
// FUNCTION: read in words from input and place into the map m
// ARGUMENTS: map <string, int>& m
//////////////////////////////////////////////////////////////////
void get_words ( map <string, int>& m)
{
	string dirtyWord, cleanWord;
	while( cin ) // while there is input
	{
		cin >> dirtyWord; // read in word 1 at a time
		clean_entry( dirtyWord, cleanWord ); // call clean method
		if( cleanWord.size() > 0 ) m[cleanWord]++; // add to set if > 0
	}
}

//////////////////////////////////////////////////////////////////
// METHOD: print_words
// FUNCTION: print words & frequency
// ARGUMENTS: map <string, int>& m
//////////////////////////////////////////////////////////////////
void print_words ( const map <string, int>& m)
{
	typedef map<string,int> mapType;
	mapType::const_iterator i;
	int count = 0;
	int words = 0;
	for( i = m.begin(); i!= m.end(); i++ )
	{
		cout << left << setw(20) << i->first << "= " << setw(5) << i->second;
		count++;
		words += i->second;
		if( count == 3 ){ cout << endl; count = 0; } // 3 words per line
	}
	cout << endl << "Number of non-empty words: " << words << endl;
	cout << "Number of distinct words: " << m.size() << endl;
}

//////////////////////////////////////////////////////////////////
// METHOD: clean_entry
// FUNCTION: remove punctuation & convert all chars to lowercase
// ARGUMENTS: const string&d, string& c
//////////////////////////////////////////////////////////////////
void clean_entry ( const string& d, string& c)
{
	// check if the word is really a word
	unsigned int start;
	for( start=0; start<d.length(); start++ )
	{
		if( isalnum( d[start] ) ) break; // is it alphanumeric?
	}
	// scan to end of the word
	unsigned int end = start;
	for( ; end<d.length(); end++ )
	{
		if( !isalnum( d[end] ) ) break; // is it not alphanumeric?
	}
	c = d.substr( start, end - start ); // retrieve cleaned word
	for_each( c.begin(), c.end(), ::tolower ); // set letters to lower case
}
