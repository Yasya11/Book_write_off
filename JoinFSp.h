//Join Filial Spisanie 
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

class FilSp{
public:
    int ID_fil;
    int ID_sp;
    string nazv;
    string adr;
    int num;
    int mon;
    int god;
    int ID_sotr;
    FilSp(const int & t_ID_fil, const int & t_ID_sp, const string& t_nazv, const string& t_adr,
               const int & t_num, const int & t_mon, const int & t_god, const int & t_ID_sotr){
        ID_fil=t_ID_fil;
        ID_sp=t_ID_sp;
        nazv=t_nazv;
        adr=t_adr;
        num=t_num;
        mon=t_mon;
        god=t_god;
        ID_sotr=t_ID_sotr;
    }
~FilSp(){;}
};

void JoinFilSp(FILE* h, char* s, DataBase2 d2, DataBase3 d3){
vector<FilSp> FSp;
FSp.reserve (15*120);
for(int i=0;i<15;++i){
    for(int j=0;j<120;++j){
        if(d2.mass[j].ID_fil==d3.mass[i].get_ID_fil()){
            FilSp FS(d3.mass[i].get_ID_fil(),  d2.mass[j].get_ID_sp(),
                       d3.mass[i].nazv, d3.mass[i].adr, d2.mass[j].number,
                       d2.mass[j].month, d2.mass[j].year, d2.mass[j].ID_sotr);
            FSp.push_back(FS);
        }
    }
}
char* p1=strstr(s,"nazv=");
char* p2=strstr(s,"adr=");
char* p3=strstr(s,"num=");
char* p4=strstr(s,"mon=");
char* p5=strstr(s,"god=");
char* p6=strstr(s,"ID_fil=");
char* p7=strstr(s,"ID_sp=");
char* p8=strstr(s,"ID_sotr=");

char* t1=strstr(s,"nazv ");
char* t2=strstr(s,"adr ");
char* t3=strstr(s,"num ");
char* t4=strstr(s,"mon ");
char* t5=strstr(s,"god ");
char* t6=strstr(s,"ID_fil ");
char* t7=strstr(s,"ID_sp ");
char* t8=strstr(s,"ID_sotr ");

if(p1!=0){  //"nazv="
    char nazv [128];
    if (sscanf (p1 + 5, "%s", nazv) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t3!=0){  //"num "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].num==a[j].num){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].num);
                a.push_back(FSp[i]);
                k++;
            }
        }
    } else if(t4!=0){  //"mon "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].mon==a[j].mon){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].mon);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t5!=0){  //"god "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].god==a[j].god){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].god);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t7!=0){  //"ID_sp "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_sp==a[j].ID_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_sp);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t8!=0){  //"ID_sotr "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_sotr);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if (p2!=0){  //"adr="
    char adr [128];
    if (sscanf (p2 + 4, "%s", adr) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t3!=0){  //"num "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].adr.c_str(),adr)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].num==a[j].num){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].num);
                a.push_back(FSp[i]);
                k++;
            }
        }
    } else if(t4!=0){  //"mon "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].adr.c_str(),adr)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].mon==a[j].mon){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].mon);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t5!=0){  //"god "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].adr.c_str(),adr)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].god==a[j].god){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].god);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t7!=0){  //"ID_sp "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].adr.c_str(),adr)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_sp==a[j].ID_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_sp);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t8!=0){  //"ID_sotr "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(strcmp(FSp[i].adr.c_str(),adr)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_sotr);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if (p3!=0) {  //"num="
    int num;
    if (sscanf (p3 + 4, "%d", &num) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"nazv "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].num==num){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].nazv.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"adr "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].num==num){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].adr==a[j].adr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].adr.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"ID_fil "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].num==num){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_fil);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
    } else if (p4!=0){  //"mon="
    int mon;
    if (sscanf (p4 + 4, "%d", &mon) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"nazv "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].mon==mon){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].nazv.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"adr "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].mon==mon){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].adr==a[j].adr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].adr.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"ID_fil "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].mon==mon){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_fil);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if(p5!=0){   //"god="
    int god;
    if (sscanf (p5 + 4, "%d", &god) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"nazv "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].nazv.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"adr "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].adr==a[j].adr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].adr.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"ID_fil "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_fil);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
    }else if(p6!=0){  //"ID_fil="
        int ID_fil;
    if (sscanf (p6 + 7, "%d", &ID_fil) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t3!=0){  //"num "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].num==a[j].num){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].num);
                a.push_back(FSp[i]);
                k++;
            }
        }
    } else if(t4!=0){  //"mon "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].mon==a[j].mon){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].mon);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t5!=0){  //"god "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].god==a[j].god){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].god);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t7!=0){  //"ID_sp "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_sp==a[j].ID_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_sp);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t8!=0){  //"ID_sotr "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_sotr);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
    }else if(p7!=0){  //"ID_sp="
        int ID_sp;
    if (sscanf (p7 + 6, "%d", &ID_sp) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"nazv "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_sp==ID_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].nazv.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"adr "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_sp==ID_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].adr==a[j].adr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].adr.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"ID_fil "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_sp==ID_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_fil);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
        }else if(p8!=0){  //"ID_sotr="
        int ID_sotr;
        if (sscanf (p8 + 8, "%d", &ID_sotr) != 1){
            fprintf (h, "Wrong\n");
            return;
            }
    if(t1!=0){  //"nazv "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_sotr==ID_sotr){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].nazv.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"adr "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_sotr==ID_sotr){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].adr==a[j].adr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSp[i].adr.c_str());
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"ID_fil "
        int k=1;
        vector <FilSp> a;
        for(unsigned i=0;i<FSp.size();++i){
            if(FSp[i].ID_sotr==ID_sotr){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSp[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSp[i].ID_fil);
                a.push_back(FSp[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
    }else{
        fprintf(h, "Wrong query\n");
        return;
    }
    return;
}
