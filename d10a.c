#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,*s3;
  unsigned char d,dd[256];
  int i,j,ndx=0,skip=0,len;
  f=fopen("d10.txt","r");
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n')))*s2=0;
  fclose(f);
  for (i=0;i<256;i++) dd[i]=i;
  s2=s;
  while ((s3=strsep(&s2,","))) {
    len=atoi(s3);
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
  printf("product=%d\n",dd[0]*dd[1]);
}
