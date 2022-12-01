#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int x[1200],last=0,pc=0,steps=0;
  f=fopen("d05.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    x[last++]=atoi(s);
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  while (pc>=0 && pc<last) {
    pc+=x[pc]<3 ? x[pc]++ : x[pc]--;
    steps++;
  }
  printf("Escape in %d steps\n",steps);   
}
