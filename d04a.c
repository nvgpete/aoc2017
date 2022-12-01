#include <stdio.h>
#include <string.h>
void sort(char *s) {
  int i,j,n;
  char c;
  n=strlen(s);
  for (i=0; i<n-1; i++) for (j=i; j<n; j++) if (s[i]>s[j]) {
    c=s[i]; s[i]=s[j]; s[j]=c;
  }
}      
int main(int argc,char **argv) {
  FILE *f;
  int ok=0,ok2=0,last,i,j,good;
  char s[100],*s2,*s3[20];
  f=fopen("d04.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    last=0;
    s2=s;
    while (s2) s3[last++]=strsep(&s2," ");
    good=1;
    for (i=0; i<last-1; i++) for (j=i+1; j<last; j++) if (strcmp(s3[i],s3[j])==0) good=0;
    ok+=good;
    if (good) {
      for (i=0; i<last; i++) sort(s3[i]);
      for (i=0; i<last-1; i++) for (j=i+1; j<last; j++) if (strcmp(s3[i],s3[j])==0) good=0;
      ok2+=good;
    }  
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  printf("%d valid part A passphrases\n",ok);
  printf("%d valid part B passphrases\n",ok2);
}
