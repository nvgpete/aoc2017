#include <stdio.h>
#include <string.h>
#define MA 16807
#define MB 48271
#define DV 2147483647L
#define SEEDA 116
#define SEEDB 299
int main(int argc,char **argv) {
  long seeda=SEEDA,seedb=SEEDB;
  int i,count=0;
  for (i=0;i<40000000;i++) {
    seeda=seeda*MA%DV;
    seedb=seedb*MB%DV;
    if ((seeda&0xffff)==(seedb&0xffff)) count++;
  }
  printf("%d matches.\n",count);
  count=0;
  seeda=SEEDA;
  seedb=SEEDB;
  for (i=0;i<5000000;i++) {
    do seeda=seeda*MA%DV; while (seeda%4);
    do seedb=seedb*MB%DV; while (seedb%8);
    if ((seeda&0xffff)==(seedb&0xffff)) count++;
  }
  printf("%d matches.\n",count);
}
