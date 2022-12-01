#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VALUE 277678
//#define VALUE 1100
int main(int argc,char **argv) {

  int xy[1200][1200],i=600,j=600,dir=0;
  memset(xy,0,sizeof(xy));
  xy[600][600]=1;
  while (xy[j][i]<VALUE) {
    switch (dir) {
      case 0: i++;
              if (xy[j-1][i]==0) dir=1;
              break;
      case 1: j--;
              if (xy[j][i-1]==0) dir=2;
              break;
      case 2: i--;
              if (xy[j+1][i]==0) dir=3;
              break;
      case 3: j++;
              if (xy[j][i+1]==0) dir=0;
    }
    xy[j][i]=xy[j-1][i-1]+xy[j-1][i]+xy[j-1][i+1]+xy[j][i-1]+xy[j][i+1]+xy[j+1][i-1]+xy[j+1][i]+xy[j+1][i+1];
  }
  printf("Value=%d\n",xy[j][i]);
}
