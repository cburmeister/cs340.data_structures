//////////////////////////////////////////////////////////////////
// NAME: Corey Burmeister
// ASSIGNMENT: 6
// DUE: 3/9/2012
//////////////////////////////////////////////////////////////////

#ifndef BINTREE_H
#define BINTREE_H

#include "binTreeNode.h"

template <class T> class binTree
{
	public:

		binTree ( ); // default constructor
		bool empty ( ) const; // checks if tree empty
		int size ( ) const; // returns no of nodes
		int height ( ) const; // returns height of tree
		virtual void insert ( const T& ); // inserts a node in shortest subtree

		void inOrder ( void ( * ) ( T& )); // inorder traversal of tree
		void preOrder ( void ( * ) ( T& )); // preorder traversal of tree
		void postOrder ( void ( * ) ( T& )); // postorder traversal of tree

	protected:

		binTreeNode <T>* root; // root of tree

	private:
	
		int size ( binTreeNode <T>* ) const; // private version of size
		int height ( binTreeNode <T>* ) const; // private version of height
		void insert ( binTreeNode <T>*&, const T& ); // private version of insert

		void inOrder ( binTreeNode <T>*, void ( * ) ( T& )); // private version of inOrder
		void preOrder ( binTreeNode <T>*, void ( * ) ( T& )); // private version of preOrder
		void postOrder ( binTreeNode <T>*, void ( * ) ( T& )); // private version of postOrder

		void clear ( binTreeNode <T>*& ); // private version of clear
		binTreeNode <T>* copy ( const binTreeNode <T>* ); // creates clone of tree
};

// default constructor
template <class T>
binTree <T>::binTree( )
{
	root = 0; // initialize root
}

// checks if tree empty
template <class T>
bool binTree<T>::empty( ) const
{
	if( root == 0 )
	{
		return true; // empty tree
	}
	else
	{
		return false;
	}   
}

// returns no of nodes
template <class T>
int binTree <T>::size( ) const
{
    return size( root ); // call recursive
}

// returns height of tree
template <class T>
int binTree <T>::height( ) const
{
    return height( root ); // call recursive
}

// inserts a node in shortest subtree
template <class T>
void binTree <T>::insert( const T& v )
{
    insert( root, v ); // call recursive
}

// inorder traversal of tree
template <class T>
void binTree <T>::inOrder( void ( *fn ) ( T& ) )
{
    inOrder( root, fn ); // call recursive
}

// preorder traversal of tree
template <class T>
void binTree <T>::preOrder( void ( *fn ) ( T& ) )
{
    preOrder( root, fn ); // call recursive
}

// postorder traversal of tree
template <class T>
void binTree <T>::postOrder( void ( *fn ) ( T& ) )
{
    postOrder( root, fn ); // call recursive
}

// private version of size
template <class T>
int binTree <T>::size( binTreeNode <T>* ptr ) const
{
	if( ptr != 0 ) // if not empty
	{
		return 1 + size( ptr->left ) + size( ptr->right );
	}
	else
	{
		return 0; // emtpy tree
	}
} 

// private version of height
template <class T>
int binTree <T>::height( binTreeNode <T>* ptr ) const
{
	if( ptr == 0 )
	{
		return 0; // empty tree
	}
	else
	{
		int lHeight = height( ptr->left ); // left side
		int rHeight = height( ptr->right ); // right side
	  
		if( lHeight > rHeight ) // which is greater
		{
			return 1 + lHeight; // return left
		}
		else
		{
			return 1 + rHeight; // return right 
		}   
	}
}

// private version of insert
template <class T>
void binTree <T>::insert( binTreeNode <T>* & p, const T& v )
{
	if( p == 0 )
	{
		binTreeNode <T> * newNode;
		newNode = new binTreeNode <T>( v ); // new node with new value
		p = newNode; // set ptr to new node
	}	   
	else 
	{
		int lHeight = height( p->left );
		int rHeight = height( p->right );
	  
		if( lHeight <= rHeight )
		{
			insert( p->left, v );
		}
		else
		{
			insert( p->right, v );
		}
	}
}

// private version of inOrder
template <class T>
void binTree <T>::inOrder( binTreeNode <T>* p, void ( *fn ) ( T& ) )
{
	if( p != NULL )
	{
		inOrder( p->left, fn );
		fn( p->data );
		inOrder( p->right, fn );
	}
}

// private version of preOrder
template <class T>
void binTree <T>::preOrder( binTreeNode <T>* p, void ( *fn ) ( T& ) )
{
	if( p != NULL )
	{
		fn( p->data ); 
		preOrder( p->left, fn );
		preOrder( p->right, fn );
	}
}

// private version of postOrder
template <class T>
void binTree <T>::postOrder( binTreeNode <T>* p, void ( *fn ) ( T& ) )
{
	if( p != NULL )
	{
		postOrder( p->left, fn );
		postOrder( p->right, fn );
		fn( p->data ); 
	}
}

// private version of clear
template <class T>
void binTree <T>::clear ( binTreeNode <T>*& p )
{
	if( p != NULL )
	{
		clear( p->left );
		clear( p->right );
		delete p;
	}
}

// creates clone of tree
template <class T>
binTreeNode <T>* binTree<T>::copy ( const binTreeNode <T>* p )
{
	binTreeNode<T> * newNode;
	if(p != NULL)
	{
		newNode = new binTreeNode<T>( p->value );
		newNode->left = copy( p->left );
		newNode->right = copy( p->right );
		return newNode;
	}
	else
	{
		return NULL;
	}
}

#endif