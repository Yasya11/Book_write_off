//Select, Kniga-opisanie

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct record_ko
{
    int god;
    char avt[128];
    char nazv[128];
    int PK;
};

void load_ko(record_ko* base, int n, FILE*f);
void strwork_ko (FILE* h, char* s, record_ko* base, int n);

int SelectKn_op (FILE* h, char* s){
  FILE*f = fopen ("Knigi_opisania.txt", "r");
  if (f == 0)
    {
      fprintf (h, "File error!\n");
      return 0;
    }

  //printf("Start loading...\n");

  int n=3000;

  record_ko *base= new record_ko [n];

  load_ko(base, n, f);
  fprintf(h,"Loading completed!\n\n");

    strwork_ko (h, s,base,n);

  fclose(f);
  return 0;
}


void load_ko(record_ko* base, int n, FILE*f)
{
  int i;
  for (i=0; i<n; i++)
    {
      fscanf (f, "%d%s%s%d", &base[i].PK,  base[i].avt,  base[i].nazv,
             &base[i].god);
    }

}

void strwork_ko (FILE* h, char* s, record_ko* base, int n)
{
  bool fl_god = 0;
  bool fl_avt = 0;
  bool fl_nazv = 0;

  int god;
  char avt[128];
  char nazv [128];

  char *p = strstr (s, "god=");
  if (p != 0)
    {
      if (sscanf (p + 4, "%d", &god) != 1)
        {
          fprintf (h, "Wrong\n");
          return;
        }
      fl_god = 1;
    }

  p = strstr (s, "nazv=");
  if (p != 0)
    {
      if (sscanf (p + 5, "%s", nazv) != 1)
        {
          fprintf (h, "Wrong\n");
          return;
        }

      if (nazv[strlen(nazv) - 1] == '\n')
          nazv[strlen(nazv) - 1] = '0';

      fl_nazv = 1;
    }

  p = strstr (s, "avt=");
  if (p != 0)
    {
      if (sscanf (p + 4, "%s", avt) != 1)
        {
          fprintf (h, "Wrong\n");
          return;
        }

      if (avt[strlen(avt) - 1] == '\n')
          avt[strlen(avt) - 1] = '0';

      fl_avt = 1;
    }

  if (!fl_god && !fl_nazv && !fl_avt)
    {
      fprintf (h, "\nNo parameters found\n");
      return;
    }
  fprintf (h, "\nResults:\n");

  int k = 0;
  for (int i = 0; i < n; i++){
      if (fl_god && base[i].god != god)
        continue;
      if (fl_nazv     && strcmp (nazv, base[i].nazv)     )
        continue;
      if (fl_avt && strcmp (avt,  base[i].avt) )
        continue;

      fprintf (h, "%d) PK: %d %s %s %d\n", k+1, base[i].PK, base[i].avt, base[i].nazv,
                                        base[i].god);
      k++;

    }

  fprintf (h, "\n%d/%d records found\n", k, n);
}

