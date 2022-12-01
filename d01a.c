#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[2050],*s2,*s3,last;
  int sum=0,sum2=0;
  f=fopen("d01.txt","r");
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n')))*s2=0;
  fclose(f);
  s2=s;
  s3=s+strlen(s)/2;
  last=s[strlen(s)-1];
  while (*s2) {
    if (*s2==last) sum+=last-'0';
    if (*s3 && *s2==*s3++) sum2+=2*(*s2-'0');
    last=*s2++;
  } 
  printf("Part A=%d\n",sum); 
  printf("Part B=%d\n",sum2); 
}
