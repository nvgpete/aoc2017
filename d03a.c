#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VALUE 277678
//#define VALUE 23
int main(int argc,char **argv) {

  int xy[1200][1200],i=600,j=600,k=2,dir=0;
  memset(xy,0,sizeof(xy));
  xy[600][600]=1;
  while (k<=VALUE) {
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
    xy[j][i]=k++;
  }
  printf("%d steps\n",abs(j-600)+abs(i-600));
}
