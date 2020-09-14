//Select, Sotrudnik

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct record
{
    int PK;
    int fil;
    char sur[128];
    char name[128];
    char position[128];
};

void load_sotr(record* base, int n, FILE*f);
void strwork_sotr (FILE* h, char* s, record* base, int n);

int SelectSotr (FILE* h, char* s){
  FILE* f = fopen ("Sotrudniki.txt", "r");
  if (f == 0)
    {
      fprintf (h,"File error!\n");
      return 0;
    }

  //printf("Start loading...\n");

  int n=70;

  record *base= new record [n];

  load_sotr(base, n, f);
  fprintf(h,"Loading completed!\n\n");

    strwork_sotr (h, s,base,n);

  fclose(f);
  return 0;
}


void load_sotr(record* base, int n, FILE*f)
{
  int i;

  for (i=0; i<n; i++)
    {
      fscanf (f, "%d%s%s%s%d", &base[i].PK,  base[i].name, base[i].sur,
             base[i].position, &base[i].fil);
    }

}

void strwork_sotr (FILE* h, char* s, record* base, int n)
{
  bool fl_sur = 0;
  bool fl_name = 0;
  bool fl_position = 0;
  bool fl_fil = 0;

  int fl = 0;
  char name[128];
  char pos [128];
  char surn[128];


  char *p = strstr (s, "fil=");
  if (p != 0)
    {
      if (sscanf (p + 4, "%d", &fl) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }
      fl_fil = 1;
    }

  p = strstr (s, "name=");
  if (p != 0)
    {
      if (sscanf (p + 5, "%s", name) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }

      if (name[strlen(name) - 1] == '\n')
          name[strlen(name) - 1] = '0';

      fl_name = 1;
    }

  p = strstr (s, "pos=");
  if (p != 0)
    {
      if (sscanf (p + 4, "%s", pos) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }

      if (pos[strlen(pos) - 1] == '\n')
          pos[strlen(pos) - 1] = '0';

      fl_position = 1;
    }

  p = strstr (s, "sur=");
  if (p != 0)
    {
      if (sscanf (p + 4 , "%s", surn) != 1)
        {
          fprintf (h,"Wrong\n");
          return;
        }

      if (surn[strlen(surn) - 1] == '\n')
          surn[strlen(surn) - 1] = '0';
      fl_sur = 1;
    }

  if (!fl_fil && !fl_name && !fl_position && !fl_sur)
    {
      fprintf (h,"\nNo parameters found\n");
      return;
    }
  fprintf (h,"\nResults:\n");

  int k = 0;
  for (int i = 0; i < n; i++){
      if (fl_fil && base[i].fil != fl)
        continue;

      if (fl_name     && strcmp (name, base[i].name)     )
        continue;
      if (fl_position && strcmp (pos,  base[i].position) )
        continue;
      if (fl_sur  && strcmp (surn, base[i].sur)  )
        continue;


      fprintf (h,"%d) PK: %d %s %s %s  Nomer filiala: %d  \n", k+1, base[i].PK, base[i].name, base[i].sur,
                                        base[i].position, base[i].fil );
      k++;

    }

  fprintf (h,"\n%d/%d records found\n", k, n);
}


