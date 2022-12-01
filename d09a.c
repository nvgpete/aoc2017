#include <stdio.h>
#include <string.h>
char *s2;
char get() {
  char c;
  while ((c=*s2++)=='!') s2++;
  return c;
}  
int main(int argc,char **argv) {
  FILE *f;
  char s[14000],c;
  int d=0,count=0,g=0;
  f=fopen("d09.txt","r");
  fgets(s,sizeof(s),f);
  fclose(f);
  s2=s;
  while ((c=get())) {
    if (c=='{') d++;
    else if (c=='}') count+=d--;
    else if (c=='<') while (get()!='>') g++;
  }
  printf("score=%d\n",count);    
  printf("garbage=%d\n",g);
}
