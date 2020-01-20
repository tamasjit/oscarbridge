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