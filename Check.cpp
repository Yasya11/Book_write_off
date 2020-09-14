
#include <cstdio>
#include <cstdlib>
#include <string>
#include <string.h>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>
#include "Classes.h"
using namespace std;

int main(void){   //int Check(char *s){}
  Dictionary D;
  char s[128];
  FILE* f;
  f=fopen("Vvod.txt","r");
   fgets(s,128,f);
   fclose(f);

  printf("Check: the query is: %s\n\n", s);
  char *p1 = strstr (s, "select");
  char *p2 = strstr (s, "from");
  char *p3 = strstr (s, "where");
  if (p1==0 || p2==0 || p3==0){
      printf("there is no 'select' or 'from' or 'where'\n");
      return 1;
    }
  char *p4;
  int i, a=-1;
  for(i=0;i<6;++i){ //6=D.classes.size()
      p4= strstr (s, D.classes[i]);
      if(p4!=0) {
        a=i;
        break;
      }
  }
  if (a<0) {
        printf("there is no such class in the library\n");
        return 1;
  }
  int b=-1;
  if(a==0){
    for(i=0;i<5;++i){ //5=D.atr_sotr.size()
      p4= strstr (s, D.atr_sotr[i]);
      if(p4!=0) {
        b=i;
        break;
      }
    }
    if(b<0){
      printf("wrong attribute\n");
      return 1;
    }
  } else if(a==1){
    for(i=0;i<6;++i){ //6=D.atr_sp.size()
      p4= strstr (s, D.atr_sp[i]);
      if(p4!=0) {
        b=i;
        break;
      }
    }
    if(b<0){
      printf("wrong attribute\n");
      return 1;
    }
  } else if(a==2){
    for(i=0;i<3;++i){ //3=D.atr_fil.size()
      p4= strstr (s, D.atr_fil[i]);
      if(p4!=0) {
        b=i;
        break;
      }
    }
    if(b<0){
      printf("wrong attribute\n");
      return 1;
    }
    } else if(a==3){
        for(i=0;i<3;++i){ //3=D.atr_str_sp.size()
      p4= strstr (s, D.atr_str_sp[i]);
      if(p4!=0) {
        b=i;
        break;
      }
    }
    if(b<0){
      printf("wrong attribute\n");
      return 1;
    }
    } else if(a==4){
        for(i=0;i<4;++i){ //4=D.atr_kniga_op.size()
      p4= strstr (s, D.atr_kniga_op[i]);
      if(p4!=0) {
        b=i;
        break;
      }
    }
    if(b<0){
      printf("wrong attribute\n");
      return 1;
    }
    }else {
        for(i=0;i<2;++i){ //2=D.atr_kniga_ek.size()
      p4= strstr (s, D.atr_kniga_ek[i]);
      if(p4!=0) {
        b=i;
        break;
      }
    }
    if(b<0){
      printf("wrong attribute\n");
      return 1;
    }
    }

  char* p5= strstr(s, D.tabs[a]);
  if (p5==0){
    printf("the table doesn't corresponds to class\n");
    return 1;
  }


int d=-1;
int g=-1;
  char* p6= strstr(s, "join");
  char *p7;
  char *p8;
  if(p6!=0){

  for(i=0;i<6;++i){ //6=D.classes.size()
     if(i==a)
        continue;
     p7 = strstr (s, D.tabs[i]);
     if(p7!=0){
        d=i;
       break;
     }
  }
  } else d=a;
  if(d<0){
    printf("wrong second table\n");
  }
  if(d==0){
    for(i=0;i<5;++i){ //5=D.atr_sotr.size()
        if(i==b) continue;
      p4= strstr (s, D.atr_sotr[i]);
      if(p4!=0) {
        g=i;
        break;
      }
    }
    if(g<0){
      printf("wrong attribute\n");
      return 1;
    }
  } else if(d==1){
    for(i=0;i<6;++i){ //6=D.atr_sp.size()
        if(i==b) continue;
      p4= strstr (s, D.atr_sp[i]);
      if(p4!=0) {
        g=i;
        break;
      }
    }
    if(g<0){
      printf("wrong attribute\n");
      return 1;
    }
  } else if(d==2){
    for(i=0;i<3;++i){ //3=D.atr_fil.size()
        if(i==b) continue;
      p4= strstr (s, D.atr_fil[i]);
      if(p4!=0) {
        g=i;
        break;
      }
    }
    if(g<0){
      printf("wrong attribute\n");
      return 1;
    }
    } else if(d==3){
        for(i=0;i<3;++i){ //3=D.atr_str_sp.size()
            if(i==b) continue;
      p4= strstr (s, D.atr_str_sp[i]);
      if(p4!=0) {
        g=i;
        break;
      }
    }
    if(g<0){
      printf("wrong attribute\n");
      return 1;
    }
    } else if(d==4){
        for(i=0;i<4;++i){ //4=D.atr_kniga_op.size()
            if(i==b) continue;
      p4= strstr (s, D.atr_kniga_op[i]);
      if(p4!=0) {
        g=i;
        break;
      }
    }
    if(g<0){
      printf("wrong attribute\n");
      return 1;
    }
    }else {
        for(i=0;i<2;++i){ //2=D.atr_kniga_ek.size()
            if(i==b) continue;
      p4= strstr (s, D.atr_kniga_ek[i]);
      if(p4!=0) {
        g=i;
        break;
      }
    }
    if(g<0){
      printf("wrong attribute\n");
      return 1;
    }
    }

return 0;
}
