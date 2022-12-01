#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int fwlen[100],fwloc[100];
  int n,c,k,last,sum,parta,bad,nmax=0;
  memset(fwlen,0,sizeof(fwlen));
  f=fopen("d13.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    sscanf(s,"%d: %d",&n,&c);
    fwlen[n]=c;
//    printf("%d %d\n",n,c);
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  last=n;
  k=0;
  do {
    for (n=0;n<=last;n++) if (fwlen[n]) fwloc[n]=k % (2*(fwlen[n]-1));
if (k==36756720) for (n=0; n<=last;n++) if (fwlen[n]) printf("%d ",fwloc[n]);
    sum=0;
    bad=0;
    for (n=0;n<=last;n++) {
      if (fwlen[n] && fwloc[n]==0) {
        bad=1;
        if (k) break;
        sum+=n*fwlen[n];
      }  
      for (c=0; c<=last; c++) if (fwlen[c]) {
        fwloc[c]++;
        if (fwloc[c]==2*(fwlen[c]-1)) fwloc[c]=0;
      }
    }
    if (k==0) parta=sum;
    k++;
  } while (bad && k<100000000);
  printf("severity=%d\n",parta);
  printf("delay=%d\n",k-1); //maybe
}
