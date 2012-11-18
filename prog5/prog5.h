#include "/home/onyuksel/courses/340/common/340.h"

#ifndef H_PROG5
#define H_PROG5

#define SEED 1                      // seed for RNG
#define SIM_TIME ( 7 * 24 * 60 )    // total simulation time in minutes
#define SAMPLE_INT 200              // period for sampling intervals

#define MIN_INT_ARR 1               // min interarrival time for customers
#define MAX_INT_ARR 5               // max interarrival time for customers

#define MIN_PICK 1                  // min time to pick items in shopping
#define MAX_PICK 20                 // max time to pick items in shopping

#define MIN_SERV 1                  // min service time in checkout line
#define MAX_SERV 4                  // max service time in checkout line

// structure for individual customer
typedef struct {
    int id;                         // customer id
    int atime, wtime, checkout;     // customer arrival time, wait time in
                                    // checkout, and time to enter checkout line
} cust;

// structure for time event
typedef struct {
    int next_arr, next_dept,        // next arrival time, next departure time
        next_checkout;              // time to enter checkout line
} event;

// structure for final statistics
typedef struct {
    int num_dept;                       // num of customers departed
    int tot_shop, tot_wait, tot_serv;   // total shopping time, total wait time
                                        // in checkout line, and total service
                                        // time for all customers in simulation
    float avg_shop, avg_wait, avg_serv; // avg shopping time, avg wait time in
                                        // checkout line, and avg service time
} stat;


// class to compare grocery picking times for customers c1 and c2
class cmp {
public:
    bool operator ( ) ( const cust& c1, const cust& c2 ) const;
};

typedef multiset < cust, cmp > MS; typedef MS :: iterator P;
typedef queue < cust > Q;

// initialize values in structures e and s
void init_vars ( event& e, stat& s);

// creates object for arriving customer with id, insert object in multiset ms,
// and updates timing values in structure e
void Arrival ( event& e, const int& id, MS& ms );

// moves object with minimum checkout time from multiset ms to queue q
// and updates timing values in structure e
void Checkout ( event& e, MS& ms, Q& q );

// removes object for departing customer from queue q, updates timing
// values in structure e, and updates final statistics in structure s
void Departure ( event& e, Q& q, stat& s );

// updates clock to first occurrence of timing events in structure e
// with given flag values of f1 and f2
int update_clock ( const event& e, const bool& f1, const bool& f2 );

// returns next arrival time
int arr_time ( const int& clock );

// returns next departure time
int dept_time ( const int& clock );

// returns time to enter checkout line
int start_checkout ( const int& clock );

// updates final statistics in structure s for customer c at time clock
void update_fin_stat ( stat& s, const cust& c, const int& clock );

// prints final statistics in structure s at end of simulation
void print_fin_stat ( stat& s );
#endif
