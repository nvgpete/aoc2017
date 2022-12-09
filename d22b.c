#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,xy[2000][2000],dir='u';
  int i=1001,r=1013,c=1013,count=0;
  memset(xy,'.',sizeof(xy));
  f=fopen("d22.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    strncpy(xy[i]+1001,s,25);
    i++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
//  memset(xy,'.',sizeof(xy)); // uncomment for example data  
//  xy[1012][1014]='#'; 
//  xy[1013][1012]='#'; 
  for (i=0; i<10000000;i++) {
    if (xy[r][c]=='#') {
      xy[r][c]='F';
      switch (dir) {
        case 'u': dir='r';
                  c++;
                  break;
        case 'r': dir='d';
                  r++;
                  break;
        case 'd': dir='l';
                  c--;
                  break;
        case 'l': dir='u';
                  r--;
                  break;
      }
    } else if (xy[r][c]=='.') {         
      xy[r][c]='W';
      switch (dir) {                                     
        case 'u': dir='l';
                  c--;
                  break;
        case 'r': dir='u';
                  r--;
                  break;
        case 'd': dir='r';
                  c++;
                  break;
        case 'l': dir='d';
                  r++;
                  break;
      }
    } else if (xy[r][c]=='W') {         
      xy[r][c]='#';
      count++;
      switch (dir) {                                     
        case 'u': r--;
                  break;
        case 'r': c++;
                  break;
        case 'd': r++;
                  break;
        case 'l': c--;
                  break;
      }
    } else { // 'F'        
      xy[r][c]='.';
      switch (dir) {                                     
        case 'u': dir='d';
                  r++;
                  break;
        case 'r': dir='l';
                  c--;
                  break;
        case 'd': dir='u';
                  r--;
                  break;
        case 'l': dir='r';
                  c++;
                  break;
      }
    }
  }
//  for (i=900;i<=1150;i++) printf("%.169s\n",xy[i]+900);
  printf("%d nodes infected.\n",count);    
}
