#include <stdio.h>
#include <string.h>
char nm[1500][8],root[1500];
int lnm,tt[1500][9];
int find(char *s) {
  int i;
  for (i=1; i<lnm; i++) if (strcmp(s,nm[i])==0) break;
  if (i==lnm) strcpy(nm[lnm++],s); else root[i]=0;
  return i;
}
char *strsep2(char **s,char *sep) { // strsep() doesn't handle multiple separators like strtok()
  char *s2;
  s2=strsep(s,sep);
  if (*s2) return s2;
  return strsep(s,sep);
}  
int getwgt(int k) {
  int ww=0,i,n,w[8],bad=0;
//  for (i=1;i<8;i++) printf("%d\t",tt[k][i]);
//  printf("%d\n",k);
// if (k>1490) exit(0);
  if (tt[k][1]) {
    i=1;
    while (tt[k][i]) {
      w[i]=getwgt(tt[k][i]);
      ww+=w[i];
      if (w[i]!=w[1]) bad=1;
      i++;
    }
    if (bad) {
      for (n=1; n<i; n++) printf("(%d %d %d) ",tt[k][n],w[n],tt[tt[k][n]][0]);
      printf("\n");
    }     
    return ww+tt[k][0]; 
  }
  else return tt[k][0];
}  
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,s3[8];
  int wgt,n,j;
  lnm=1;
  memset(tt,0,sizeof(tt));
  memset(root,1,sizeof(root));
  f=fopen("d07.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    sscanf(s,"%s (%d)",s3,&wgt);
    n=find(s3);
    tt[n][0]=wgt;
//    printf("%s %d %d\n",s3,wgt,n);
    if ((s2=strchr(s,'>'))) {
      s2+=2;
      j=1;
      while (s2) tt[n][j++]=find(strsep2(&s2,", "));
    }    
    fgets(s,sizeof(s),f);
  }
  fclose(f);
  for (n=1; n<lnm; n++) if (root[n]) break;
  printf("root at %s\n",nm[n]);
  printf("%d\n",getwgt(n)); 
}
