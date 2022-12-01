#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void hash(char *s,unsigned char *hh) {
  char *s2,*s3;
  unsigned char d,dd[256];
  int i,j,k,ndx=0,skip=0,len;
  s3=malloc(strlen(s)+6);
  strcat(strcpy(s3,s),"\x11\x1f\x49\x2f\x17"); //17,31,73,47,23
  for (i=0;i<256;i++) dd[i]=i;
  for (k=0;k<64;k++) {
    s2=s3;
    while ((len=*s2++)) {
      i=ndx;
      j=ndx+len-1;
      while (j>i) {
        d=dd[i&255];
        dd[i&255]=dd[j&255];
        dd[j&255]=d;
        i++;
        j--;
      }
      ndx=(ndx+len+skip++)&255;  
    }
  }
  for (i=0;i<16;i++) {
    d=0;
    for (j=16*i;j<16*(i+1); j++) d^=dd[j];
    hh[i]=d;
  }
}
int xy[128][128];
void fill(int i,int j,int v) {
  xy[i][j]=v;
  if (i && xy[i-1][j]==1) fill(i-1,j,v);
  if (j && xy[i][j-1]==1) fill(i,j-1,v);
  if (i!=127 && xy[i+1][j]==1) fill(i+1,j,v);
  if (j!=127 && xy[i][j+1]==1) fill(i,j+1,v);
}

int main(int argc,char **argv) {
  unsigned char h[16];
  char s[13]="ugkiagan";
//  char s[13]="flqrgnkx"; // example data
  int i,j,k,n,sum=0,last=1;
  for (i=0;i<128;i++) {
    sprintf(s+8,"-%d",i);
    hash(s,h);
    for (j=0;j<16;j++) for (k=0;k<8;k++) {
      n=(h[j]>>(7-k))&1;
      sum+=n;
      xy[i][j*8+k]=n;
    }
  }
  for (i=0;i<128;i++) for (j=0;j<128;j++) if (xy[i][j]==1) {
    last++;
    fill(i,j,last);
  }  
  printf("%d used.\n",sum);
  printf("%d regions.\n",last-1);
}
