#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[210][210],*s2,ans[26],dir;
  int last=0,r,c,more=1,count=1;
  memset(s,0,sizeof(s));
  f=fopen("d19.txt","r");
  fgets(s[last],sizeof(s[0]),f);
  while (!feof(f)) {
    if((s2=strchr(s[last],'\n')))*s2=0;
    last++;
    fgets(s[last],sizeof(s[0]),f);
  }  
  fclose(f);
  r=0;
  c=strchr(s[0],'|')-s[0];
  dir='d';
  last=0;
  r=0;
  while (more) {
    switch (dir) {
      case 'd': while (s[r+1][c]!=' ') {
                  r++;
                  count++;
                  if (s[r][c]>='A' && s[r][c]<='Z') ans[last++]=s[r][c];
                }  
                if (s[r][c-1]!=' ') dir='l';
                else if (s[r][c+1]!=' ') dir='r';
                else more=0;
                break;
      case 'u': while (s[r-1][c]!=' ') { 
                  r--;
                  count++;
                  if (s[r][c]>='A' && s[r][c]<='Z') ans[last++]=s[r][c];
                }  
                if (s[r][c-1]!=' ') dir='l';
                else if (s[r][c+1]!=' ') dir='r';
                else more=0;
                break;
      case 'r': while (s[r][c+1]!=' ') {
                  c++;
                  count++;
                  if (s[r][c]>='A' && s[r][c]<='Z') ans[last++]=s[r][c];
                }  
                if (s[r-1][c]!=' ') dir='u';
                else if (s[r+1][c]!=' ') dir='d';
                else more=0;
                break;
      case 'l': while (s[r][c-1]!=' ') {
                  c--;
                  count++;
                  if (s[r][c]>='A' && s[r][c]<='Z') ans[last++]=s[r][c];
                }  
                if (s[r-1][c]!=' ') dir='u';
                else if (s[r+1][c]!=' ') dir='d';
                else more=0;
                break;
    }
  }
  ans[last]=0;
  printf("Path=%s\n",ans);
  printf("%d total steps\n",count);              
}
