#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  unsigned char d,dd[256];
  int i,j,k,ndx=0,skip=0,len;
  f=fopen("d10.txt","r");
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n')))*s2=0;
  strcat(s,"\x11\x1f\x49\x2f\x17"); //17,31,73,47,23
  fclose(f);
  s2=s;
  for (i=0;i<256;i++) dd[i]=i;
  for (k=0;k<64;k++) {
    s2=s;
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
    printf("%.2x",d);
  }
  printf("\n");     
}
