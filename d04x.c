#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  int ok=0;
  char s[100],*s2,*s3;
  f=fopen("d04.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    s2=s;
    s3=strsep(&s2," ");
    while (s2) {
//      printf("%s %s\n",s3,s2);
      if (s2 && strstr(s2,s3)) break;
      s3=strsep(&s2," ");
    }
    ok+=(s2==NULL);  
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  printf("%d valid passphrases\n",ok);
}
