#include "/home/onyuksel/courses/340/progs/12s/p10/hTable.h"

#ifndef H_TABLE
#define H_TABLE

void ptr_sort ( );

HT::HT (  const unsigned& s )
{
	hTable.resize(s);
	pTable.resize(s);
	psize = 0;
	hsize = TBL_SZ;
	for (unsigned int i = 0; i != s; i++)
	{
		hTable[i].key = FREE;
	}
}

HT::~HT()
{
	//delete [] hTable;
	//delete [] pTable;
}

void HT::insert ( const Entry& e )
{
	int index = hash(e.key);
	unsigned int i;
	for (i = 0; i < hsize; i++)
	{
		if (hTable[(index+i)%hsize].key == FREE)
		{
			// use open addressing: linear probing for collision resolution
			cout << " entry = " << (index + i) % hsize << endl;
			hTable[(index+i)%hsize] = e;
			pTable[psize] = &hTable[(index+i)%hsize];
			psize++;
			break;
		}
		if (hTable[(index+i)%hsize].key == e.key)
		{
			cout << " not inserted - duplicate key!!!" << endl;
			break;
		}
	}
	if (i == hsize)
		cout << " not inserted - table full!!!" << endl;
}

void HT::search ( const string& s )
{
	int index = hash(s);
	unsigned int i;
	for (i = 0; i < hsize; i++)
	{
		if (hTable[(index+i)%hsize].key == s)
		{
			cout << " ==> number: "
			<< setw(4) << hTable[(index+i)%hsize].num
			<< " - item: " << hTable[(index+i)%hsize].desc
			<< endl;
			break;
		}
	}
	if (hTable[(index+i)%hsize].key != s)
		cout << " not in table!!" << endl;
}

void HT::hTable_print ( )
{
	bool lastEmpty = false;
	for ( unsigned int i = 0; i < hsize; i++ )
	{
		if ( hTable[i].key != FREE )
		{
			if ( lastEmpty ) cout << endl;
			cout << setw(4) << i << ":  " << hTable[i].key << " - "
			<< setw(5) << hTable[i].num << "   -  " << hTable[i].desc << endl;
			lastEmpty = false;
		}
		else lastEmpty = true;
	}
	cout << endl;
}

void HT::pTable_print ( )
{
	ptr_sort();
	for (unsigned int i = 0; i < psize; i++ )
	{
		cout << "   " << pTable[i]->key
		<< " - " << right << setw(4) << pTable[i]->num
		<< " - " << left << pTable[i]->desc << endl;
	}
	cout << endl;
}

void ptr_sort ( )
{
	unsigned int i, j;
	Entry* bucket;
	for (i = 1; i < psize; i++)
	{
		bucket = pTable[i];
		for (j = i; (j > 0) && (pTable[j-1]->key > bucket->key); j--)
			pTable[j] = pTable[j-1];
		pTable[j] = bucket;
	}
}

#endif
