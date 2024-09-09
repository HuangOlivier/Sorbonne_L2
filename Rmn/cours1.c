#include <stdio.h>
#include <stdint.h>

unsigned int position(unsigned int n, unsigned int i)
{
    return (n >> i) & 1;
}

int compare(uint16_t n, uint16_t m)
{
    int i = 15, b1, b2;
    do    
    { 
        b1 = (n << i);
        b2 = (m << i);
        i-=1;

    } while((b1 == b2) && ( i >= 0 ));

    return (b1 > b2) && (i != -1);
}

int main () {
   printf("%d \n",compare(28,90));
}

