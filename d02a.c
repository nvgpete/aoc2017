#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[150],*s2;
  int x,xx[16],i,j,ddd,min,max,sum=0,sum2=0;
  f=fopen("d02.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    s2=strtok(s," \t");
    min=max=atoi(s2);
    ddd=0;
    i=0;
    while (s2) {
      x=atoi(s2);
      if (ddd==0) {
        xx[i++]=x;
        for (j=0; j<i-1; j++) {
          if (x % xx[j]==0) ddd=x/xx[j];
          if (xx[j] % x==0) ddd=xx[j]/x;
        }
      }    
      if (x<min) min=x;
      if (x>max) max=x;
      s2=strtok(NULL," \t");
    }
    sum+=max-min;
    sum2+=ddd;  
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  printf("Cksum=%d\n",sum);
  printf("Part B sum=%d\n",sum2);
}
