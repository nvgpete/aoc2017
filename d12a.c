#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pp[2000][10],grp[2000];

void chk(int n,int g) {
  int i=0;
  if (grp[n]) return;
  grp[n]=g;
  while (pp[n][i]>=0) {
    chk(pp[n][i],g);
    i++; 
  } 
  return;
}
       
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int i,g,n;
  memset(pp,-1,sizeof(pp));
  memset(grp,0,sizeof(grp));
  f=fopen("d12.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    n=strtol(s,&s2,10);
    i=0;
    s2+=3;
    while (*s2) {
      pp[n][i++]=strtol(s2+2,&s2,10);
    }
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  g=0;
  for (n=0; n<2000; n++) if (grp[n]==0) {
    g++;
    chk(n,g);
  }
  i=0;
  for (n=0; n<2000; n++) if (grp[n]==1) i++;
  printf("%d in group 1.\n",i);
  printf("%d total groups.\n",g);  
}
