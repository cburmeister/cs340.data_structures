#include "/home/onyuksel/courses/340/progs/12s/p11/wdigraph.h"

// default class constructor

wdigraph :: wdigraph ( int n ) : size ( n )
{
    // allocate dynamic memory

    label = vector < char > ( size );
    adj_matrix = vector < vector < int > > ( size );
    for ( int i = 0; i < size; i++ )
        adj_matrix [ i ] = vector < int > ( size );

    // assign labels to each node

    label [ 0 ] = 'A';
    for ( int i = 1; i < size; i++ )
        label [ i ] = label [ i - 1 ] + 1;

    // determine weights for links between nodes randomly
    // and build adjacency matrix

    srand ( 1 ); bool flag; // to check if node is connected
    for ( int i = 0; i < size; i++ ) {
        adj_matrix [ i ] [ i ] = 0; flag = false;
        for ( int j = i + 1; j < size; j++ ) {
            double r = ( double ) rand ( ) / RAND_MAX;
            adj_matrix [ i ] [ j ] = adj_matrix [ j ] [ i ] =
                ( r <= LINK_PROB ) ? ( rand ( ) % MAX_WEIGHT ) + 1 : 0;
            if ( adj_matrix [ i ] [ j ] > 0 ) flag = true;
        }

        // if node is not connected to any other node, then
        // connect this node to digraph choosing random node
        // for connection

        if ( i < size && !flag ) {
            int k; while ( ( k = rand ( ) % size ) == i ) ;
            adj_matrix [ i ] [ k ] = adj_matrix [ k ] [ i ] =
                ( rand ( ) % MAX_WEIGHT ) + 1;
        }
    }
}
