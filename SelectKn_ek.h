//Select, Kniga-ekzempl'ar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct record_ke
{
    int opisanie;
    int PK;
};


void load_ke(record_ke* base, int n, FILE*f);
void strwork_ke (FILE* h, char* s, record_ke* base, int n);

int SelectKn_ek (FILE* h, char* s){
  FILE* f = fopen ("Knigi_eksempliari.txt", "r");
  if (f == 0)
    {
      fprintf (h,"File error!\n");
      return 0;
    }

  //printf("Start loading...\n");

  int n=12000;

  record_ke *base= new record_ke [n];

  load_ke(base, n, f);
  fprintf(h,"Loading completed!\n\n");

    strwork_ke (h, s,base,n);

    fclose(f);
  return 0;
}


void load_ke(record_ke* base, int n, FILE*f)
{
  int i;
  for (i=0; i<n; i++)
    {
      fscanf (f, "%d%d", &base[i].PK, &base[i].opisanie);
    }

}

void strwork_ke (FILE *h, char* s, record_ke* base, int n)
{
  bool fl_opisanie = 0;

  int opisanie;

  char *p = strstr (s, "ID_kn_op=");
  if (p != 0)
    {
      if (sscanf (p + 9, "%d", &opisanie) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }
      fl_opisanie = 1;
    }

  if (!fl_opisanie)
    {
      fprintf (h,"\nNo parameters found\n");
      return;
    }

  fprintf (h,"\nResults:\n");

  int k = 0;
  for (int i = 0; i < n; i++){
    if (fl_opisanie && base[i].opisanie != opisanie)
      continue;
      fprintf (h,"%d) PK: %d Opisanie: %d \n", k+1, base[i].PK,  base[i].opisanie);
      k++;

    }

  fprintf (h, "\n%d/%d records found\n", k, n);
}

