//Select, Filial

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct record_f
{
    char nazv[128];
    char adr[128];
    int PK;
};

void load_fil(record_f* base, int n, FILE*f);
void strwork_fil (FILE *h, char* s, record_f* base, int n);

int SelectFil (FILE* h, char* s){
  FILE* f = fopen ("Filiali.txt", "r");
  if (f == 0)
    {
      fprintf (h, "File error!\n");
      return 0;
    }

  //printf("Start loading...\n");

  int n=15;
  record_f *base= new record_f [n];

  load_fil(base, n, f);
  fprintf(h, "Loading completed!\n\n");
    strwork_fil (h, s, base, n);
    fclose(f);
  return 0;
}


void load_fil(record_f* base, int n, FILE*f)
{
  int i;
  for (i=0; i<n; i++)
    {
      fscanf (f, "%d%s%s", &base[i].PK,  base[i].nazv,  base[i].adr);
    }

}

void strwork_fil (FILE* h, char* s, record_f* base, int n)
{
  bool fl_adr = 0;
  bool fl_nazv = 0;

  char nazv[128];
  char adr[128];

  char* p = strstr (s, "nazv=");
  if (p != 0)
    {
      if (sscanf (p + 5, "%s", nazv) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }

      if (nazv[strlen(nazv) - 1] == '\n')
          nazv[strlen(nazv) - 1] = '0';

      fl_nazv = 1;
    }

  p = strstr (s, "adr=");
  if (p != 0)
    {
      if (sscanf (p + 4 , "%s", adr) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }

      if (adr[strlen(adr) - 1] == '\n')
          adr[strlen(adr) - 1] = '0';
      fl_adr = 1;
    }

  if (!fl_nazv &&  !fl_adr)
    {
      fprintf (h,"\nNo parameters found\n");
      return;
    }
  fprintf (h,"\nResults:\n");

  int k = 0;
  for (int i = 0; i < 15; i++){
      if (fl_nazv   && strcmp (nazv, base[i].nazv)     )
        continue;
      if (fl_adr  && strcmp (adr, base[i].adr)  )
        continue;

      fprintf (h,"%d) PK: %d %s %s \n", k+1,  base[i].PK, base[i].nazv, base[i].adr);
      k++;

    }

  fprintf (h,"\n%d/%d records found\n", k, n);
}
