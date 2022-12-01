#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  unsigned char list[20];
  int i,j,last=0,steps=0;
  unsigned long z;
  f=fopen("d06.txt","r");
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n')))*s2=0;
  s2=s;
  while (s2) list[last++]=atoi(strsep(&s2,"\t"));
  fclose(f);
  while (steps<5042) { // was 10000 to find first repeat
    j=0;
    for (i=1;i<last;i++) if (list[i]>list[j]) j=i;
    i=list[j];
    list[j]=0;
    while (i>0) {
      j++;
      if (j==last) j=0;
      list[j]++;
      i--;
    }
//    z=*(unsigned long *)list+((*((unsigned long *)(list+8)))<<4);
//    printf("%lu\n",z);  
    for (j=0; j<last; j++) printf("%3d",list[j]);
    printf("\n");
    steps++;
  }   
}
