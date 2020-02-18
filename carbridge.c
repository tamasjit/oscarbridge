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

