//Select, StrSpisania

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct record_ssp
{
    int sp;
    int kn_ek;
    int PK;
};

void load_ssp(record_ssp* base, int n, FILE*f);
void strwork_ssp (FILE* h, char* s, record_ssp* base, int n);

int SelectStrSp (FILE* h, char* s){
  FILE*f = fopen ("Stroki Spisaniy.txt", "r");
  if (f == 0)
    {
      fprintf (h,"File error!\n");
      return 0;
    }

  //printf("Start loading...\n");

  int n=480;

  record_ssp *base= new record_ssp [n];

  load_ssp(base, n, f);
  fprintf(h,"Loading completed!\n\n");

    strwork_ssp (h, s, base, n);

  fclose(f);
  return 0;
}


void load_ssp(record_ssp* base, int n, FILE*f)
{
  int i;

  for (i=0; i<n; i++)
    {
      fscanf (f, "%d%d%d", &base[i].PK, &base[i].sp, &base[i].kn_ek);
    }

}

void strwork_ssp (FILE* h, char* s, record_ssp* base, int n)
{
  bool fl_sp = 0;
  bool fl_kn_ek = 0;
  int sp, kn_ek;

  char *p = strstr (s, "sp=");
  if (p != 0)
    {
      if (sscanf (p + 3, "%d", &sp) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }
      fl_sp = 1;
    }
  p = strstr (s, "kn_ek=");
  if (p != 0)
    {
      if (sscanf (p + 6, "%d", &kn_ek) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }
      fl_kn_ek = 1;
    }

  if (!fl_sp && !fl_kn_ek)
    {
      fprintf (h,"\nNo parameters found\n");
      return;
    }
  fprintf (h,"\nResults:\n");

  int k = 0;
  for (int i = 0; i < n; i++){
      if (fl_sp && base[i].sp != sp)
        continue;
      if (fl_kn_ek && base[i].kn_ek != kn_ek)
        continue;

      fprintf (h,"%d) PK: %d Spisanie: %d Kniga-exepliar: %d \n", k+1, base[i].PK,  base[i].sp, base[i].kn_ek);
      k++;

    }

  fprintf (h,"\n%d/%d records found\n", k, n);
}

