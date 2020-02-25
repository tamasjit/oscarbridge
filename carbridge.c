#include<stdio.h>


unsigned int northwait[20];
unsigned int soutwait[20];
unsigned int nx,sx;

struct lock
{
    unsigned int lka;
};
void lock_init(struct lock lko){
    lko.lka = 0;
}
//initilization as per
struct bridge
{

    unsigned int north_timewaiting;
    unsigned int north_timecrossing;
    unsigned int north_timeconsecutive;

    unsigned int south_timewaiting;
    unsigned int south_timecrossing;
    unsigned int south_timeconsecutive;

    struct lock llk;
}operatingbridge;




//lock acquire
void acquireing_lock_north()
{
    operatingbridge.llk.lka = 2;
}
void bridge_init(struct bridge operetingsys)
{
    operetingsys.north_timewaiting = 0;
    operetingsys.north_timecrossing = 0;
    operetingsys.north_timeconsecutive = 0;
    operetingsys.south_timeconsecutive = 0;
    operetingsys.south_timecrossing = 0;
    operetingsys.south_timewaiting = 0;

    lock_init(operetingsys.llk);
}
void acquireing_lock_south()
{
    operatingbridge.llk.lka = 1;
}
void south_empty_wait(){

    unsigned int loopvo;
    for(loopvo = 0; loopvo < sx; loopvo++)
    {
        printf("\tSouth Car %d Process gets executed::::: \n",soutwait[loopvo]);
    }
    puts("");
    sx = 0;

}
//North empyty wait
void north_empty_wait(){

    unsigned int loopvo;
    for(loopvo = 0; loopvo < nx; loopvo++)
    {
        printf("\tNorth Car %d Process gets executed::::: \n",northwait[loopvo]);
    }
    puts("");
    nx = 0;

}
//check


void bridge_arrive_south(unsigned int call_ver_t)
{
    if(operatingbridge.llk.lka == 0 || operatingbridge.llk.lka == 1)
            {
                printf("\tSouth Car %d process gets executed:::::\n",call_ver_t);
                acquireing_lock_south();
            }
            else
            {
                printf("\tSouth Car %d process goes to waiting.....\n",call_ver_t);
                soutwait[sx] = call_ver_t;
                sx++; 
                if(sx >= 5)
                {
                    acquireing_lock_south();
                    south_empty_wait();
                }
            }
}
void bridge_arrive_north(unsigned int call_ver_o)
{
    if(operatingbridge.llk.lka == 0 || operatingbridge.llk.lka == 2)
            {
                printf("\tNorth Car %d process gets executed:::::\n",call_ver_o);
                acquireing_lock_north();
            }
            else
            {
                printf("\tNouth Car %d process goes to waiting.....\n",call_ver_o);
                northwait[nx] = call_ver_o;
                nx++;
                if(nx >= 5)//“five car rule” test case
                {
                    acquireing_lock_north();
                    north_empty_wait();
                }
            }
}

unsigned int partition(unsigned int a[], unsigned int low, unsigned int high);

unsigned int partition (unsigned int a[], unsigned int low, unsigned int high)
{
    unsigned int pivot = a[high];  
    unsigned int i = (low-1);  
    unsigned int j;
    for ( j = low; j <= high-1; j++)
    {

        if (a[j] <= pivot)
        {
            i++;   
            unsigned int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    unsigned int t = a[i + 1];
    a[i+1] = a[high];
    a[high] = t;
    return (i + 1);
}

