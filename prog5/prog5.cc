//////////////////////////////////////////////////////////////////
// NAME: Corey Burmeister
// ASSIGNMENT: 5
// DUE: 2/28/2012
//////////////////////////////////////////////////////////////////

#include "/home/onyuksel/courses/340/progs/12s/p5/prog5.h"

int simClock = 0;
bool f1 = true;
bool f2 = true;

int main()
{
	srand( SEED ); // initialize RNG
	MS ms; // create list of cust objects
	MS::iterator i; // create multiset iterator
	Q q; // create queue of cust objects
	stat s; // create stat object
	event e; // create event object
	int id = 1; // cust id count
	//bool f1 = true;
	//bool f2 = true;

	init_vars( e, s ); // init event & stat objects

	while ( simClock < SIM_TIME )
	{
		if ( simClock == e.next_arr ) // cust arrival
		{
			Arrival( e, id, ms ); // process cust arrival
			id++; // increment cust id count
		}

		if( simClock == e.next_checkout ) // cust checkout
		{
			Checkout( e, ms, q ); // process cust checkout
		}

		if( simClock == e.next_dept ) // cust depart
		{
			Departure( e, q, s ); // process cust depart
		}

		if( ms.empty() ) f1 = false; else f1 = true; // is multiset empty?
		if( q.empty() ) f2 = false; else f2 = true; // is queue empty?

		//simClock++;
		simClock = update_clock( e, f1, f2 ); // update simulation clock
	}

	return 0;
}

void init_vars ( event& e, stat& s)
{
	e.next_arr = 0; // next arrival time
	e.next_dept = SIM_TIME + 1; // next departure time
	e.next_checkout = SIM_TIME + 1; // time to enter checkout line

	s.num_dept = 0; // num of customers departed
	s.tot_shop = 0; // total shopping time
	s.tot_wait = 0; // total wait time in checkout line
	s.tot_serv = 0; // total service time for all customers
	s.avg_shop = 0; // avg shopping time
	s.avg_wait = 0; // avg wait time in checkout line
	s.avg_serv = 0; // avg service time
}


bool cmp :: operator ( ) ( const cust& c1, const cust& c2 ) const
{
	if( c1.checkout < c2.checkout ) return true; else return false;
}

void Arrival ( event& e, const int& id, MS& ms )
{
	cust c; // create nth cust
	c.id = id; // set cust id
	c.atime = simClock; // set cust arrival time
	c.checkout = start_checkout( simClock ); // set cust time to enter checkout
	c.wtime = 0; // set cust wait time

	ms.insert( c ); // insert nth cust into multiset

	e.next_arr = arr_time( simClock ); // compute next arrival time

	MS::iterator i;
	i = ms.begin();

	e.next_checkout = i->checkout; // get the next dept time
}

void Checkout ( event& e, MS& ms, Q& q )
{
	MS::iterator i; // create iterator
	cust c1; // create cust
	i = ms.begin(); // get next cust checking out
	c1 = *i;
	ms.erase( ms.begin() ); // remove cust from set
	q.push( c1 ); // push cust into checkout line

	if ( q.size() == 1 ) e.next_dept = dept_time( simClock ); // get next dept time
}

void Departure ( event& e, Q& q, stat& s )
{
	cust c1; // create cust
	cust c2;
	c1 = q.front(); // get first cust in line
	q.pop(); // remove first cust in line

	if ( ! q.empty() ) // if more cust in line
	{
		c2 = q.front(); // get next cust in line

		c2.wtime = simClock - c1.checkout; // set cust wait time
		e.next_dept = dept_time( simClock ); // get next dept time
	}
	update_fin_stat( s, c1, simClock ); // update stats
}

int arr_time ( const int& clock )
{
	return ( rand()% ( ( MAX_INT_ARR - MIN_INT_ARR + 1 ) + MIN_INT_ARR ) + clock );
}

int start_checkout ( const int& clock )
{
	return ( rand()% ( ( MAX_PICK - MIN_PICK + 1 ) + MIN_PICK ) + clock );
}

int dept_time ( const int& clock )
{
	return ( rand()% ( ( MAX_SERV, MIN_SERV + 1 ) + MIN_SERV ) + clock );
}

int update_clock ( const event& e, const bool& f1, const bool& f2 )
{
	int currentTime ;
		currentTime = e.next_arr;
	if( f1 == true )
		if( e.next_checkout < currentTime ) 
			currentTime = e.next_checkout;
	if( f2 == true )
		if( e.next_dept < currentTime ) 
			currentTime = e.next_dept;
	return currentTime;
}

void update_fin_stat ( stat& s, const cust& c, const int& clock )
{
	s.num_dept++; // increment num of departed cust
	s.tot_shop += c.checkout - c.atime; // increment total shopping time
	s.tot_wait += c.wtime; // increment wait time
	s.tot_serv += clock - c.checkout; // increment service time

	if( s.num_dept % SAMPLE_INT == 0 )
	{
		cout << "Num: " << s.num_dept << " " << "ID: " << c.id << " " << "Shopping Time: " << 
			c.checkout - c.wtime << " " << "Wait Time: " << c.wtime << " " << "Service Time: " << clock - c.checkout;
	}
}

void print_fin_stat ( stat& s )
{
	s.avg_shop = s.tot_shop / s.num_dept;
	s.avg_wait = s.tot_wait / s.num_dept;
	s.avg_serv = s.tot_serv / s.num_dept;

	cout << s.avg_shop << endl;
	cout << s.avg_wait << endl;
	cout << s.avg_serv << endl;
}