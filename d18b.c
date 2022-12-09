#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FLEN 200
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,opc[50];
  int r1[50],r2[50];
  int pc,pc2,lastop=0,last=0,next=0,last2=0,next2=0,ok=1,ok2=1,count=0;
  long rg[26],rg2[26]; //a-z
  long val[50],fifo[FLEN],fifo2[FLEN];
  memset(rg,0,sizeof(rg));
  memset(rg2,0,sizeof(rg2));
  f=fopen("d18.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    r1[lastop]=s[4]-'a';
    if (s[5]) {
      if(s[6]>='a' && s[6]<='z') r2[lastop]=s[6]-'a';
      else {
        r2[lastop]=-1;
        val[lastop]=atoi(s+6);
      }
    }    
    if (strncmp(s,"set",3)==0) opc[lastop]='s';
    else if (strncmp(s,"mul",3)==0) opc[lastop]='m'; 
    else if (strncmp(s,"mod",3)==0) opc[lastop]='d';
    else if (strncmp(s,"add",3)==0) opc[lastop]='a';
    else if (strncmp(s,"snd",3)==0) opc[lastop]='t';
    else if (strncmp(s,"rcv",3)==0) opc[lastop]='r';
    else if (strncmp(s,"jgz",3)==0) {
      if(s[4]=='1') opc[lastop]='u'; //unconditional jump
      else opc[lastop]='j';
    }
    lastop++;  
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  pc=0;
  pc2=0;
  rg2['p'-'a']=1;
  while (ok || ok2) {
    ok=1;
    while (ok && pc>=0 && pc<lastop) {
      switch (opc[pc]) {
        case 's': rg[r1[pc]]=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                  break;
        case 'm': rg[r1[pc]]*=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                  break;
        case 'd': rg[r1[pc]]%=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                  break;
        case 'a': rg[r1[pc]]+=r2[pc]>=0 ? rg[r2[pc]] : val[pc];
                  break;
        case 't': if (last==FLEN) ok=0;
                  else fifo[last++]=rg[r1[pc]];
                  break;
        case 'r': if (last2>next2) rg[r1[pc]]=fifo2[next2++];
                  else {
                    last2=next2=0;
                    ok=0;
                  }  
                  break;
        case 'j': if (rg[r1[pc]]<=0) break;
        case 'u': pc+=(r2[pc]>=0 ? rg[r2[pc]] : val[pc])-1;
      }
      if (ok) pc++;
    }
    ok2=1;
    while (ok2 && pc2>=0 && pc2<lastop) {
      switch (opc[pc2]) {
        case 's': rg2[r1[pc2]]=r2[pc2]>=0 ? rg2[r2[pc2]] : val[pc2];
                  break;
        case 'm': rg2[r1[pc2]]*=r2[pc2]>=0 ? rg2[r2[pc2]] : val[pc2];
                  break;
        case 'd': rg2[r1[pc2]]%=r2[pc2]>=0 ? rg2[r2[pc2]] : val[pc2];
                  break;
        case 'a': rg2[r1[pc2]]+=r2[pc2]>=0 ? rg2[r2[pc2]] : val[pc2];
                  break;
        case 't': if (last2==FLEN) ok2=0;
                  else {
                    fifo2[last2++]=rg2[r1[pc2]];
                    count++;
                    ok=1;
                  }  
                  break;
        case 'r': if (last>next) rg2[r1[pc2]]=fifo[next++];
                  else {
                    last=next=0;
                    ok2=0;
                  }  
                  break;
        case 'j': if (rg2[r1[pc2]]<=0) break;
        case 'u': pc2+=(r2[pc2]>=0 ? rg2[r2[pc2]] : val[pc2])-1;
      }
      if (ok2) pc2++;
    }
  }
  printf("%d messages sent\n",count);  
}
