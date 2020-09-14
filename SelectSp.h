//Select, Spisanie

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Classes.h"


struct record_sp
{
    int num, mon, god;
    int sotr, fil;
    int PK;
};


void load_sp(record_sp* base, int n, FILE*f);
void strwork_sp (FILE* h, char* s, record_sp* base, int n);

int SelectSp (FILE* h, char* s){
  FILE*f = fopen ("Spisania.txt", "r");
  if (f == 0)
    {
      fprintf (h,"File error!\n");
      return 0;
    }

  //printf("Start loading...\n");

  int n=120;

  record_sp *base= new record_sp [n];

  load_sp(base, n, f);
  fprintf(h,"Loading completed!\n\n");

    strwork_sp (h, s, base, n);

    fclose(f);
  return 0;
}


void load_sp(record_sp* base, int n, FILE*f)
{
  int i;
  for (i=0; i<n; i++)
    {
      fscanf (f, "%d%d%d%d%d%d", &base[i].PK, &base[i].num, &base[i].mon,
             &base[i].god, &base[i].sotr, &base[i].fil);
    }

}

void strwork_sp (FILE* h, char* s, record_sp* base, int n)
{
  bool fl_num = 0;
  bool fl_mon = 0;
  bool fl_god = 0;
  bool fl_sotr = 0;
  bool fl_fil = 0;

  int num, mon, god, sotr, fil;

  char *p = strstr (s, "num=");
  if (p != 0)
    {
      if (sscanf (p + 4, "%d", &num) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }
      fl_num = 1;
    }

  p = strstr (s, "mon=");
  if (p != 0)
    {
      if (sscanf (p + 4, "%d", &mon) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }
      fl_mon = 1;
    }
p = strstr (s, "god=");
  if (p != 0)
    {
      if (sscanf (p + 4, "%d", &god) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }
      fl_god = 1;
    }
p = strstr (s, "sotr=");
  if (p != 0)
    {
      if (sscanf (p + 5, "%d", &sotr) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }
      fl_sotr = 1;
    }
p = strstr (s, "fil=");
  if (p != 0)
    {
      if (sscanf (p + 4, "%d", &fil) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }
      fl_fil = 1;
    }


  if (!fl_num && !fl_mon && !fl_god && !fl_sotr && !fl_fil)
    {
      fprintf (h,"\nNo parameters found\n");
      return;
    }
  fprintf (h,"\nResults:\n");

  int k = 0;
  for (int i = 0; i < n; i++){
    if (fl_num && base[i].num != num)
      continue;
    if (fl_mon && base[i].mon != mon)
      continue;
    if (fl_god && base[i].god != god)
      continue;
    if (fl_sotr && base[i].sotr != sotr)
      continue;
    if (fl_fil && base[i].fil != fil)
      continue;

      fprintf (h,"%d) PK: %d Data: %d.%d.%d ID Sotrudnika: %d  Nomer filiala: %d\n", k+1,  base[i].PK, base[i].num, base[i].mon,
                                        base[i].god, base[i].sotr, base[i].fil);
      k++;

    }

  fprintf (h,"\n%d/%d records found\n", k, n);
}


