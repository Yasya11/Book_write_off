
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>
#include "SelectSotr.h"
#include "SelectFil.h"
#include "SelectSp.h"
#include "SelectStrSp.h"
#include "SelectKn_op.h"
#include "SelectKn_ek.h"
#include "JoinFSotr.h"
#include "JoinSpSotr.h"
#include "JoinFSp.h"
#include "JoinStrSp.h"
#include "JoinStrKnek.h"
#include "JoinKnEO.h"

using namespace std;

DataBase1 generate1(ofstream &out);
DataBase2 generate2(ofstream &out);
DataBase3 generate3(ofstream &out);
DataBase4 generate4(ofstream &out);
DataBase5 generate5(ofstream &out);
DataBase6 generate6(ofstream &out);
expr Analis_virazhenia(FILE* g);
void Vivod(FILE *h,expr Exp, DataBase1 data1, DataBase2 data2, DataBase3 data3,
           DataBase4 data4, DataBase5 data5, DataBase6 data6);

int main (void){
srand(time(NULL));
ofstream out1 ("Sotrudniki.txt");
ofstream out2 ("Spisania.txt");
ofstream out3 ("Filiali.txt");
ofstream out4 ("Stroki Spisaniy.txt");
ofstream out5 ("Knigi_opisania.txt");
ofstream out6 ("Knigi_eksempliari.txt");
DataBase1 data1=generate1(out1);
DataBase2 data2=generate2(out2);
DataBase3 data3=generate3(out3);
DataBase4 data4=generate4(out4);
DataBase5 data5=generate5(out5);
DataBase6 data6=generate6(out6);


  FILE *g1, *g2, *g3, *g4, *g5;
  g1=fopen("Vvod1.txt", "r");
  g2=fopen("Vvod2.txt", "r");
  g3=fopen("Vvod3.txt", "r");
  g4=fopen("Vvod4.txt", "r");
  g5=fopen("Vvod5.txt", "r");
  FILE *h1, *h2, *h3, *h4, *h5;
  h1=fopen("Vivod1.txt", "w");
  h2=fopen("Vivod2.txt", "w");
  h3=fopen("Vivod3.txt", "w");
  h4=fopen("Vivod4.txt", "w");
  h5=fopen("Vivod5.txt", "w");
  expr Exp1=Analis_virazhenia(g1);
  Vivod(h1, Exp1, data1, data2, data3, data4, data5, data6);

  expr Exp2=Analis_virazhenia(g2);
  Vivod(h2, Exp2, data1, data2, data3, data4, data5, data6);

  expr Exp3=Analis_virazhenia(g3);
  Vivod(h3, Exp3, data1, data2, data3, data4, data5, data6);

  expr Exp4=Analis_virazhenia(g4);
  Vivod(h4, Exp4, data1, data2, data3, data4, data5, data6);

  expr Exp5=Analis_virazhenia(g5);
  Vivod(h5, Exp5, data1, data2, data3, data4, data5, data6);

    fclose(g1);
    fclose(g2);
    fclose(g3);
    fclose(g4);
    fclose(g5);
    fclose(h1);
    fclose(h2);
    fclose(h3);
    fclose(h4);
    fclose(h5);
return 0;
}


DataBase1 generate1(ofstream &out){
vector<basic_string<char> > names;
names.reserve (8);
names.push_back ("Elena");
names.push_back ("Anastasia");
names.push_back ("Maya");
names.push_back ("Irina");
names.push_back ("Ivan");
names.push_back ("Mihail");
names.push_back ("Pavel");
names.push_back ("Maxim");
vector<basic_string <char> > surnames;
surnames. reserve (7);
surnames.push_back ("Belih");
surnames.push_back ("Adler");
surnames.push_back ("Lebed");
surnames.push_back ("Fomenko");
surnames.push_back ("Gol'dberg");
surnames.push_back ("Bagdasarian");
surnames.push_back ("Volk");
vector<basic_string<char> > positions;
positions.reserve (7);
positions.push_back ("Librarian");
positions.push_back ("Custodian");
positions.push_back ("Accountant");
positions.push_back ("Chief_Accountant");
positions.push_back ("Assistant");
positions.push_back ("Manager");
positions.push_back ("Loader");
DataBase1 data1;
int i=0;
for (int k = 0; k < 14; ++k){
    int l=rand()%7+1;
    for (int j=0; j<l;++j){
        if(i+j>=70) break;
        data1.add_sotrudnik(names[rand() % 8], surnames[rand() % 7], positions[rand() % 7], k);
    }
    i=i+l;
    }
    if(i<70){
        while(i<70){
            data1.add_sotrudnik(names[rand() % 8], surnames[rand() % 7], positions[rand() % 7], 14);;
            ++i;
        }
    }
out << data1;
return data1;
}

DataBase2 generate2(ofstream &out){
DataBase2 data2;
int i=0;
    for(int k=0;k<69;k++){ //prisvoit' FK sotrudnika spisaniam
        int l=rand()%3+1;
        for(int j=0;j<l;++j){
            if(i+j>=120)
                break;
            data2.add_spisanie(rand()%28+1, rand()%12+1, rand()%8+2010, k);
        }
        i=i+l;
    }
    if(i<120){
        while(i<120){
            data2.add_spisanie(rand()%28, rand()%12, rand()%15+2001, 69);
            ++i;
        }
    }
    i=0;
    for(int k=0;k<14;k++){    //prisvoit' FK filialov spisaniam
        int l=rand()%12+1;
            for(int j=0;j<l;++j){
                if(i+j>=120)
                    break;
                data2.mass[i+j].ID_fil=k;
            }
            i=i+l;
    }
    if(i<120){
        while(i<120){
            data2.mass[i].ID_fil=14;
            ++i;
        }
    }
out << data2;
return data2;
}

DataBase3 generate3(ofstream& out){
vector<basic_string<char> > namesfil;
namesfil.reserve (15);
namesfil.push_back ("Zaria");
namesfil.push_back ("Voshod");
namesfil.push_back ("Rassvet");
namesfil.push_back ("Zakat");
namesfil.push_back ("Mahaon");
namesfil.push_back ("Rosmen");
namesfil.push_back ("Vesna");
namesfil.push_back ("Biblioteka_MSU");
namesfil.push_back ("Dom_Knigi");
namesfil.push_back ("Mechta");
namesfil.push_back ("Glavnaya");
namesfil.push_back ("Biblioteka_im_Lenina");
namesfil.push_back ("Chitai_Gorod");
namesfil.push_back ("Labirint");
namesfil.push_back ("Yunost'");
vector<basic_string<char> > adrfil;
adrfil.reserve (15);
adrfil.push_back ("Prophsoyusnaya_ul");
adrfil.push_back ("Novaya_pl");
adrfil.push_back ("Dvortsovaya_pl");
adrfil.push_back ("Leninsky_pr");
adrfil.push_back ("Ul_Lebedeva");
adrfil.push_back ("Krasnaya_pl");
adrfil.push_back ("Bolotnaya_pl");
adrfil.push_back ("Lomonosovsky_pr");
adrfil.push_back ("Shosse_Entusiastov");
adrfil.push_back ("Yakimanka");
adrfil.push_back ("Tverskaya_ul");
adrfil.push_back ("Vozdvizhenka");
adrfil.push_back ("Ul_Novatorov");
adrfil.push_back ("Mohovaya_ul");
adrfil.push_back ("Kuznetsky_most");
DataBase3 data3;
for (int i = 0; i < 15; ++i){
data3.add_fil( namesfil[i], adrfil[i]);
}
out << data3;
return data3;
}

DataBase4 generate4(ofstream& out){
DataBase4 data4;
int i=0;
for(int k=0;k<119;k++){  // prisvoit' FK spisanii strokam
        int l=rand()%8;
        for(int j=0;j<l;++j){
            if(i+j>=480)
                break;
            data4.add_strsp(k);
        }
        i=i+l;
    }
    if(i<480){
        while(i<480){
            data4.add_strsp(119);
            ++i;
        }
    }
    i=0;
    for(int k=0;k<12000;k++){    //prisvoit' FK king eksempliarov strokam
        int l=rand()%2;
        if(l!=0){
            for(int j=0;j<l;++j){
                if(i+j>=480)
                    break;
                data4.mass[i+j].ID_kn_ek=k;
            }
            i=i+l;
        }
    }
    if(i<480){
        while(i<480){
            data4.mass[i].ID_kn_ek=11999;
            ++i;
        }
    }

out << data4;
return data4;
}

DataBase5 generate5(ofstream& out){
vector<basic_string<char> > avtori;
avtori.reserve (10);
avtori.push_back ("Chekhov");
avtori.push_back ("Tolstoi");
avtori.push_back ("Dostoyevsky");
avtori.push_back ("Turgenev");
avtori.push_back ("Hawking");
avtori.push_back ("Tsvetaeva");
avtori.push_back ("Vern");
avtori.push_back ("Karamsin");
avtori.push_back ("Zorich");
avtori.push_back ("Darvin");
vector<basic_string<char> > nazvs;
nazvs.reserve (20);
nazvs.push_back ("Rasskasy"); nazvs.push_back("Tri_sesrti");
nazvs.push_back ("Voina_i_mir"); nazvs.push_back("Kazaki");
nazvs.push_back ( "Bratia_Karamasovi"); nazvs.push_back("Idiot");
nazvs.push_back ("Otsi_i_deti"); nazvs.push_back("Zapiski_okhotnika");
nazvs.push_back ("Kratkaya_istoria_vremeni"); nazvs.push_back("Visshii_zamisel");
nazvs.push_back ( "Stihi"); nazvs.push_back("Pis'ma");
nazvs.push_back ("Puteshestvie_k_tsentru_Zemli"); nazvs.push_back("Deti_Kapitana_Granta");
nazvs.push_back ("Istoria_gosudarstva_rossiiskogo"); nazvs.push_back("Bednaya_Lisa");
nazvs.push_back ("Mat_analis_ch_1"); nazvs.push_back("Mat_analis_ch_2");
nazvs.push_back ("Proishozhdenie_vidov"); nazvs.push_back("Biografia");
DataBase5 data5;
for (int i = 0; i < 3000; ++i){
    int l=rand()%10;
    data5.add_kniga_op(avtori [l], nazvs[rand()%2+2*l], rand()%112+1904);
}
out << data5;
return data5;
}

DataBase6 generate6(ofstream& out){
DataBase6 data6;
int i=0;
for (int k = 0; k < 2999; ++k){
    int l=rand()%7+1;
    for (int j=0; j<l;++j){
        if(i+j>=12000) break;
        data6.add_kniga_ek(k);
    }
    i=i+l;
    }
    if(i<12000){
        while(i<12000){
            data6.add_kniga_ek(2999);
            ++i;

        }
    }
out << data6;
return data6;
}

expr Analis_virazhenia(FILE *g){
  Dictionary D;
  expr Exp;
  Exp.a[0]=-1;
  Exp.a[1]=-1;
  Exp.a[2]=-1;
  Exp.b=1;
  char s[128];
  fgets (s, 128, g);
  fclose(g);
  printf("The query is: %s\n\n", s);
  char *p1 = strstr (s, "select");
  char *p2 = strstr (s, "from");
  char *p3 = strstr (s, "where");
  if (p1==0 || p2==0 || p3==0){
      Exp.b=0;
      return Exp;
    }

  char *p4;
  int i;
  for(i=0;i<6;++i){ //6=D.classes.size()
      p4= strstr (s, D.classes[i]);
      if(p4!=0) {
        Exp.a[0]=i;
        break;
      }
  }
  if (Exp.a[0]<0) {
        Exp.b=0;
        return Exp;
  }

  char* p5= strstr(s, D.tabs[Exp.a[0]]);
  if (p5==0){
    Exp.b=0;
    return Exp;
  }

  char* p6= strstr(s, "join");
  if(p6!=0)
    Exp.a[1]=1;
  else{
    Exp.a[1]=0;
    strcpy(Exp.s,s);
    return Exp;
  }
  for(i=0;i<6;++i){ //6=D.classes.size()
     if(i==Exp.a[0])
        continue;
     p4 = strstr (s, D.tabs[i]);
     if(p4!=0){
       Exp.a[2]=i;
       break;
     }
  }
  if(p4==0)
    Exp.b=0;
  strcpy(Exp.s,s);
  return Exp;
}

void Vivod(FILE *h,expr Exp, DataBase1 data1, DataBase2 data2, DataBase3 data3,
           DataBase4 data4, DataBase5 data5, DataBase6 data6){
    if(Exp.b==0){
        fprintf(h,"Error!\n");
        return;
    }
    if (Exp.a[1]==0){
        if (Exp.a[0]==0){
            SelectSotr(h, Exp.s); ///
        }
        if (Exp.a[0]==1){
            SelectSp(h, Exp.s);   ///
        }
        if (Exp.a[0]==2){
            SelectFil(h,Exp.s);  ///
        }
        if (Exp.a[0]==3){
            SelectStrSp(h,Exp.s); ///
        }
        if (Exp.a[0]==4){
            SelectKn_op(h,Exp.s);   ///
        }

        if (Exp.a[0]==5){
            SelectKn_ek(h,Exp.s);   ///
        }
    }else{
        if((Exp.a[0]==0 && Exp.a[2]==2) || (Exp.a[0]==2 && Exp.a[2]==0)){  //Filial + Sotrudnik
            JoinFSotr(h, Exp.s,data1, data3);  ///
        } else if((Exp.a[0]==0 && Exp.a[2]==1) || (Exp.a[0]==1 && Exp.a[2]==0)){  //Spisanie + Sotrudnik
            JoinSpSotr(h, Exp.s,data1, data2);   ///
        }else if((Exp.a[0]==1 && Exp.a[2]==2) || (Exp.a[0]==2 && Exp.a[2]==1)){  //Spisanie + Filial
            JoinFilSp(h, Exp.s,data2, data3);   ///
        }else if((Exp.a[0]==1 && Exp.a[2]==3) || (Exp.a[0]==3 && Exp.a[2]==1)){  //Spisanie + Stroka
            JoinStrSp(h, Exp.s,data2, data4);     ///
        }else if((Exp.a[0]==3 && Exp.a[2]==5) || (Exp.a[0]==5 && Exp.a[2]==3)){  //Kniga-eks + Stroka
            JoinStrKn_ek(h, Exp.s,data4, data6);     ///
        }else if((Exp.a[0]==4 && Exp.a[2]==5) || (Exp.a[0]==5 && Exp.a[2]==4)){  //Kniga-eks + Kniga-op
            JoinKnEO(h, Exp.s,data5, data6);        ///
        }else{
            printf("Couldn't find JOIN");
        }
    }
    return;
}
