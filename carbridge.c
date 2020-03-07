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
void sort_arival(unsigned int a[], unsigned int low, unsigned int high)

{
	if (low < high)
    {
    	
        unsigned int pi=partition(a, low, high);
	    sort_arival(a, low, pi - 1);  
        sort_arival(a, pi + 1, high); 
    }
}
unsigned int south_cars, north_cars;
unsigned int main()
{
	unsigned int mainver;
    
    printf("~~~~~~~~~~~Let all the cars are inputed according ascending order arrival time~~~~~~~~~~~\n\n");


    printf("\tNumber of total north car:\t");
    scanf("%d",&north_cars);
    unsigned int north_arival[north_cars];
    for( mainver = 0; mainver < north_cars; mainver++)
    {
    	printf("\tTime of north arrival of the car %d:\t",mainver+1);
    	scanf("%d",&north_arival[mainver]);
	}
	
	printf("\tNumber of total south car:\t");
    scanf("%d",&south_cars);
    unsigned int south_arival[south_cars];
    for( mainver = 0; mainver < south_cars; mainver++)
    {
    	printf("\tTime of south arrival of the car %d:\t",mainver+1);
    	scanf("%d",&south_arival[mainver]);

	}

    printf("~~~~~~~~~~Cars of North~~~~~~~~~~\n");
    printf("\tNo.\tArrival\tLeave\n");
    for(mainver = 0; mainver < north_cars; mainver++)
    {
        printf("\t%d\t%d\n",mainver,north_arival[mainver]);
    }

    printf("~~~~~~~~~~Cars of South~~~~~~~~~~\n");
    printf("\tNo.\tArrival\tLeave\n");
    for(mainver = 0; mainver < south_cars; mainver++)
    {
        printf("\t%d\t%d\n",mainver,south_arival[mainver]);
    }
    printf("~~~~~~~~~~~Start Whole System Processing and Execution~~~~~~~~~~~\n\n");
    // Input SetUp done; 
    bridge_init(operatingbridge);
    
    mainver = 0;
    unsigned int call_ver_o = 0;
    unsigned int call_ver_t = 0;
    do{
        if(north_arival[call_ver_o] <= south_arival[call_ver_t])
        {
            bridge_arrive_north(call_ver_o);
            call_ver_o++;
            
        }
        else
        {
            bridge_arrive_south(call_ver_t);
            call_ver_t++; 
        }
    }
    while(call_ver_o < north_cars && call_ver_t < south_cars);


    south_empty_wait();
    north_empty_wait();
    if(call_ver_o == north_cars)
    {
        for(call_ver_t; call_ver_t <south_cars; call_ver_t++)
        {
            printf("\tSouth Car %d process gets executed:::::\n",call_ver_t);
        }
    }
    else
    {
        for(call_ver_o; call_ver_o <north_cars; call_ver_o++)
        {
            
            printf("\tNorth Car %d process gets executed:::::\n",call_ver_o);
        }
    }
    


}

