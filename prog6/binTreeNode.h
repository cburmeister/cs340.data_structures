//////////////////////////////////////////////////////////////////
// NAME: Corey Burmeister
// ASSIGNMENT: 6
// DUE: 3/9/2012
//////////////////////////////////////////////////////////////////

#ifndef BINTREENODE_H
#define BINTREENODE_H

#include "/home/onyuksel/courses/340/common/340.h"


template <class T> class binTree;

template <class T> class binTreeNode 
{
	friend class binTree <T>;

	public:

		// default constructor
		binTreeNode ( const T& =T ( ), binTreeNode <T>* = 0, binTreeNode <T>* = 0 );

	private:

		T data; // data value in node
		binTreeNode <T> *left, *right; // links to other nodes
};

// default constructor
template <class T>
binTreeNode <T>:: binTreeNode( const T& v, binTreeNode <T>* newLeft, binTreeNode <T>* newRight )
{
	data = v; // initialize value
	left = newLeft; // initialize left
	right = newRight; // initialize right
}

#endif
