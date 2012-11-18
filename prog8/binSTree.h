//////////////////////////////////////////////////////////////////
// NAME: Corey Burmeister
// ASSIGNMENT: 8
// DUE: 4/4/2012
//////////////////////////////////////////////////////////////////

#ifndef BINSTREE_H
#define BINSTREE_H

#include "binTree.h"
#include "binTreeNode.h"

template <class T>
class binSTree : public binTree <T> 
{
	public:

		void insert ( const T& x ); // insert node with value x
		bool search ( const T& x ) const; // searches leaf with value x
		bool remove ( const T& x ); // removes leaf with value x

	private:

		void insert ( binTreeNode <T>*&, const T& ); // private version of insert
		bool search ( binTreeNode <T>*, const T& ) const; // private version of search
		binTreeNode <T>* remove ( binTreeNode <T>*, const T& ); // private version of remove
		bool leaf ( binTreeNode <T>* node ) const; // checks if node is leaf
};

// insert node with value x
template <class T>
void binSTree<T>::insert ( const T& x )
{
	insert( this->root, x );
}

// searches leaf with value x
template <class T>
bool binSTree<T>::search ( const T& x ) const
{
	return search( this->root, x );
}

// removes leaf with value x
template <class T>
bool binSTree<T>::remove ( const T& x )
{
	if( this->size() == 1 )
	{
		this->root = NULL;

		return false;
	}

	if( this->size() > 1 )
	{	 
		if( search( x ) ) this->root = remove( this->root, x );

		return true;
	}
	else if( this->size() == 1 )
	{
		return false;
	}
	else
	{
		return false;
	}
}

// private version of insert
template <class T>
void binSTree<T>::insert ( binTreeNode <T>*& p, const T& v )
{
	if(p == NULL)
	{
        p = new binTreeNode<T>( v );
	}
    else if( v < p->data)
	{
        insert( p->left, v );
	}
    else if( v > p->data )
	{
        insert( p->right, v );
	}
    else
	{
        return; // duplicate 
	}
}

// private version of search
template <class T>
bool binSTree<T>::search ( binTreeNode <T>* p, const T& v ) const
{
	if( p == NULL ) return false;
    else
    {
        if( v == p->data )
		{
			if( leaf( p ) ) return true;
			else return false;
		}
        else if( v < p->data )
			return search( p->left, v );
        else
            return search( p->right, v );
    }
}

// private version of remove
template <class T>
binTreeNode<T>* binSTree<T>::remove ( binTreeNode <T>* p, const T& v )
{
	binTreeNode<T>* curr;
    binTreeNode<T>* parent;
    curr = p;
    
    while( curr != NULL )
    {
         if( curr->data == v )
         {
            break;
         }
         else
         {
             parent = curr;

             if( v > curr->data ) curr = curr->right;
             else curr = curr->left;
         }
    }

	if( curr != NULL )
	{
		if( parent->right == curr ) parent->right = NULL;
		else parent->left = NULL;

		delete curr;
		curr = NULL;
	}

	if( this->size() >= 1 )
	{
		return this->root;
	}

	return this->root;
}

// checks if node is leaf
template <class T>
bool binSTree<T>::leaf ( binTreeNode <T>* p ) const
{
	if( p->left == NULL && p->right == NULL ) 
	{
		return true; // node is a leaf
	} 
	else
	{
		return false; // node is not a leaf
	}
}

#endif
