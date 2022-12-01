#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[50000],*s2,pp[32]="abcdefghijklmnop",c;
  char ps[140][16];  //See d16notes.txt for why this won't overflow
  int i,j,k;
  f=fopen("d16.txt","r");
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n')))*s2=0;
  fclose(f);
  k=0;
  do  {
    strncpy(ps[k],pp,16);
    s2=s;
    while (*s2) {
      if (*s2=='s') {
        i=strtol(s2+1,&s2,10);
        memmove(pp+i,pp,16);
        memmove(pp,pp+16,i);
      } else { 
        if(*s2=='p') {
          i=strchr(pp,*(s2+1))-pp;
          j=strchr(pp,*(s2+3))-pp;
          s2+=4;
        } else {  
          i=strtol(s2+1,&s2,10);
          j=strtol(s2+1,&s2,10);
        }
        c=pp[i];
        pp[i]=pp[j];
        pp[j]=c;
      }
      if (*s2==',') s2++;    
    }
    if (k==0) printf("After one time through=%.16s\n",pp);
    k++;
  } while (strncmp(pp,"abcdefghijklmnop",16));
  printf("Repeats after=%d iterations.\n",k);
  printf("After one billion times through=%.16s\n",ps[(1000000000%k)]); 
}
