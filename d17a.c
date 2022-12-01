#include <stdio.h>
#include <string.h>
#define SKIP 335
//#define SKIP 3
int main(int argc,char **argv) {
  int bb[2020];
  int pos=0,k;
  bb[0]=0;
  for (k=1; k<=2017; k++) {
    pos=((pos+SKIP)%k)+1;
    if (pos!=k) memmove(bb+pos+1,bb+pos,(k-pos)*sizeof(int));
    bb[pos]=k;
  }
  printf("Part A=%d\n",bb[pos+1]);  
  for (k=1; k<=50000000; k++) {
    pos=((pos+SKIP)%k)+1;
    if (pos==1) bb[1]=k;
  }
  printf("Part B=%d\n",bb[1]);  
}
