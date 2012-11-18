#include "/home/onyuksel/courses/340/progs/12s/p11/wdigraph.h"

// This driver program can be used to test routines
// defined in class wdigraph.

void proc_graph ( wdigraph& );

int main ( )
{
    // create weighted digraph of size 5
    wdigraph g1 ( 5 ); proc_graph ( g1 );

    // create weighted digraph for default size
    wdigraph g2; proc_graph ( g2 );

    return 0;
}

// This routine is to create a weighted digraph
// for given size and it prints adjacency matrix.

void proc_graph ( wdigraph& g )
{
    // print graph
    cout << "\nA Weighted Digraph\n";
    cout << "________________\n";
    g.print_graph ( );

    // visit nodes by depth-first search
    cout << "Paths by Depth-First Search:\n";
    cout << "(skip every 2nd and 3rd node to print)\n\n";
    for ( int i = 0; i < g.get_size ( ); i += 3 ) g.depth_first ( i );
}
