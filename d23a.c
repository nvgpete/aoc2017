#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,opc[50];
  int r1[50],r2[50];
  int pc,last=0,count=0;
  long rg[8]; //a-h
  long val[50];
  memset(rg,0,sizeof(rg));
  f=fopen("d23.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    r1[last]=s[4]-'a';
    if (s[5]) {
      if(s[6]>='a' && s[6]<='h') r2[last]=s[6]-'a';
      else {
        r2[last]=-1;
        val[last]=atoi(s+6);
      }
    }    
    if (strncmp(s,"set",3)==0) opc[last]='s';
    else if (strncmp(s,"mul",3)==0) opc[last]='m'; 
    else if (strncmp(s,"sub",3)==0) opc[last]='b';
    else if (strncmp(s,"jnz",3)==0) {
      if(s[4]=='1') opc[last]='u'; //unconditional jump
      else opc[last]='j';
    }
    last++;  
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  pc=0;
  while (pc>=0 && pc<last) {
    switch (opc[pc]) {
      case 's': rg[r1[pc]]=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                break;
      case 'm': rg[r1[pc]]*=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                count++;
                break;
      case 'b': rg[r1[pc]]-=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                break;
      case 'j': if (rg[r1[pc]]==0) break;
      case 'u': pc+=(r2[pc]>=0 ? rg[r2[pc]] : val[pc])-1;
    }
    pc++;
  }
  printf("%d multiplies\n",count);
}
