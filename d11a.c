#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int dist(int r,int c) {
  c=abs(c);
  if (r>=0) {
    if (r>c/2) {
      r-=(c+1)/2;
    }
    else r=0;
  } else {
// This will be similar to above, but is prone to off by 1 errors.
// Since my data did not require this calculation, I am leaving 
// it out rather than writing potentially incorrect code.
  }
  return r+c;
}
  
int main(int argc,char **argv) {
  FILE *f;
  char s[25000],*s2,*s3;
  int d,r=0,c=0,max=0;
  f=fopen("d11.txt","r");
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n')))*s2=0;
  fclose(f);
  s2=s;
  while ((s3=strsep(&s2,","))) {
    if (*(s3+1)=='e') {
      if (*s3=='n') {
        c++;
        r+=(c&1);
      } else {
        r-=(c&1);
        c++;
      }
    } else if (*(s3+1)=='w') {          
      if (*s3=='n') {
        c--;
        r+=(c&1);
      } else {
        r-=(c&1);
        c--;
      }
    } else if (*s3=='n') r++;
    else r--;
    d=dist(r,c);
    if (d>max) max=d;
  } 
  printf("end=%d, max=%d\n",d,max);
}
