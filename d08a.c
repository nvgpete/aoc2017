#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int regv[2000],last,xmax=0;
char regn[2000][4];
static int getval(char *s,int n) {
  int i;
  for (i=0; i<last; i++) if (strcmp(s,regn[i])==0) break;
  if (i==last) strcpy(regn[last++],s);
  if (n) {
    regv[i]+=n;
    if (regv[i]>xmax) xmax=regv[i];
  }  
  return regv[i];
}  
  
int main(int argc,char **argv) {
  FILE *f;
  int max,n,val1,val2,rval2;
  char s[100],*s2,*ss,*sr1,*sr2,*cc,cond;
  memset(regv,0,sizeof(regv));
  last=0;
  f=fopen("d08.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    s2=s;
    sr1=strsep(&s2," ");
    ss=strsep(&s2," ");
    val1=atoi(strsep(&s2," "));
    if (ss[0]=='d') val1=-val1;
    s2+=3; //skip "if "
    sr2=strsep(&s2," ");
    cc=strsep(&s2," ");
    val2=atoi(s2);
    rval2=getval(sr2,0);
    if (cc[0]=='!') cond=(rval2!=val2);
    else if (cc[0]=='=') cond=(rval2==val2);
    else if (cc[0]=='<') {
      if (cc[1]) cond=(rval2<=val2); 
       else cond=(rval2<val2);
    }
    else if (cc[1]) cond=(rval2>=val2);
     else cond=(rval2>val2);
    if (cond) getval(sr1,val1);     
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  max=regv[0];
  for (n=1; n<last; n++) if (regv[n]>max) max=regv[n];
  printf("Ending max reg=%d\n",max);
  printf("All time max reg=%d\n",xmax);
}
