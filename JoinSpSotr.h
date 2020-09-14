//Join Spisanie Sotrudnik
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

class SpSotr{
public:
    int ID_sotr;
    int ID_sp;
    string name;
    string sur;
    string pos;
    int num;
    int mon;
    int god;
    int ID_fil;  //(FK)
        SpSotr(const int & t_ID_sotr, const int & t_ID_sp, const string& t_name, const string& t_sur,
                const string& t_pos, int & t_num, int & t_mon, int & t_god, int & t_ID_fil){
        ID_sotr=t_ID_sotr;
        ID_sp=t_ID_sp;
        name=t_name;
        sur=t_sur;
        pos=t_pos;
        num=t_num;
        mon=t_mon;
        god=t_god;
        ID_fil=t_ID_fil;
    }
~SpSotr(){;}
};

void JoinSpSotr(FILE *h, char* s, DataBase1 d1, DataBase2 d2){
vector<SpSotr> SSotr;
SSotr.reserve (70*120);
for(int i=0;i<70;++i){
    for(int j=0;j<120;++j){
        if(d2.mass[j].ID_sotr==d1.mass[i].get_ID_sotr()){
            SpSotr SpS(d1.mass[i].get_ID_sotr(),  d2.mass[j].get_ID_sp(),
                       d1.mass[i].name, d1.mass[i].surname,  d1.mass[i].position,
                       d2.mass[j].number, d2.mass[j].month, d2.mass[j].year, d2.mass[j].ID_fil);
            SSotr.push_back(SpS);
        }
    }
}
char* p1=strstr(s,"name=");
char* p2=strstr(s,"sur=");
char* p3=strstr(s,"pos=");
char* p4=strstr(s,"num=");
char* p5=strstr(s,"mon=");
char* p6=strstr(s,"god=");
char* p7=strstr(s,"ID_fil=");
char* p8=strstr(s,"ID_sp=");
char* p9=strstr(s,"ID_sotr=");

char* t1=strstr(s,"name ");
char* t2=strstr(s,"sur ");
char* t3=strstr(s,"pos ");
char* t4=strstr(s,"num ");
char* t5=strstr(s,"mon ");
char* t6=strstr(s,"god ");
char* t7=strstr(s,"ID_fil ");
char* t8=strstr(s,"ID_sp ");
char* t9=strstr(s,"ID_sotr ");

if(p1!=0){  //"name="
    char name [128];
    if (sscanf (p1 + 5, "%s", name) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t4!=0){  //"num "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].name.c_str(),name)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].num==a[j].num){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, SSotr[i].num);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    } else if(t5!=0){  //"mon "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].name.c_str(),name)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].mon==a[j].mon){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, SSotr[i].mon);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"god "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].name.c_str(),name)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].god==a[j].god){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, SSotr[i].god);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t7!=0){  //"ID_fil "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].name.c_str(),name)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_fil);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t8!=0){  //"ID_sp "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].name.c_str(),name)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_sp==a[j].ID_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_sp);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else{
        fprintf(h,"Wrong\n");
        return;
    }
} else if (p2!=0){  //"sur="
    char sur [128];
    if (sscanf (p2 + 4, "%s", sur) != 1){
          fprintf (h,"Wrong\n");
          return;
        }
    if(t4!=0){  //"num "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].sur.c_str(),sur)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].num==a[j].num){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].num);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    } else if(t5!=0){  //"mon "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].sur.c_str(),sur)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].mon==a[j].mon){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].mon);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"god "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].sur.c_str(),sur)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].god==a[j].god){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].god);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t7!=0){  //"ID_fil "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].sur.c_str(),sur)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_fil);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t8!=0){  //"ID_sp "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].sur.c_str(),sur)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_sp==a[j].ID_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_sp);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if (p3!=0){  //"pos="
    char pos [128];
    if (sscanf (p3 + 4, "%s", pos) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t4!=0){  //"num "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].pos.c_str(),pos)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].num==a[j].num){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].num);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    } else if(t5!=0){  //"mon "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].pos.c_str(),pos)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].mon==a[j].mon){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].mon);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"god "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].pos.c_str(),pos)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].god==a[j].god){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].god);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t7!=0){  //"ID_fil "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].pos.c_str(),pos)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_fil);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t8!=0){  //"ID_sp "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(strcmp(SSotr[i].pos.c_str(),pos)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_sp==a[j].ID_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_sp);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if (p4!=0) {  //"num="
    int num;
    if (sscanf (p4 + 4, "%d", &num) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"name "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].num==num){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].name==a[j].name){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].name.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"sur "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].num==num){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].sur==a[j].sur){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].sur.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t3!=0){ //"pos "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].num==num){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].pos==a[j].pos){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].pos.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t9!=0){  //"ID_sotr "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].num==num){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_sotr);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
    } else if (p5!=0){  //"mon="
    int mon;
    if (sscanf (p5 + 4, "%d", &mon) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"name "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].mon==mon){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].name==a[j].name){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].name.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"sur "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].mon==mon){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].sur==a[j].sur){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].sur.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t3!=0){ //"pos "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].mon==mon){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].pos==a[j].pos){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].pos.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t9!=0){  //"ID_sotr "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].mon==mon){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_sotr);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if(p6!=0){   //"god="
    int god;
    if (sscanf (p6 + 4, "%d", &god) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"name "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].name==a[j].name){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].name.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"sur "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].sur==a[j].sur){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].sur.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t3!=0){ //"pos "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].pos==a[j].pos){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].pos.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t9!=0){  //"ID_sotr "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_sotr);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
    }else if(p7!=0){  //"ID_fil="
        int ID_fil;
    if (sscanf (p7 + 7, "%d", &ID_fil) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"name "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].name==a[j].name){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].name.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"sur "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].sur==a[j].sur){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].sur.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t3!=0){ //"pos "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].pos==a[j].pos){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].pos.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t9!=0){  //"ID_sotr "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_sotr);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
    }else if(p8!=0){  //"ID_sp="
        int ID_sp;
    if (sscanf (p8 + 6, "%d", &ID_sp) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"name "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].ID_sp==ID_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].name==a[j].name){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].name.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"sur "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].ID_sp==ID_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].sur==a[j].sur){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].sur.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t3!=0){ //"pos "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].ID_sp==ID_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].pos==a[j].pos){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, SSotr[i].pos.c_str());
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else if(t9!=0){  //"ID_sotr "
        int k=1;
        vector <SpSotr> a;
        for(unsigned i=0;i<SSotr.size();++i){
            if(SSotr[i].ID_sp==ID_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SSotr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SSotr[i].ID_sotr);
                a.push_back(SSotr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
        }else if(p9!=0){  //"ID_sotr="
        int ID_sotr;
        if (sscanf (p9 + 8, "%d", &ID_sotr) != 1){
            fprintf (h, "Wrong\n");
            return;
            }
        if(t4!=0){  //"num "
            int k=1;
            vector <SpSotr> a;
            for(unsigned i=0;i<SSotr.size();++i){
                if(SSotr[i].ID_sotr==ID_sotr){
                    bool c=0;
                    for(unsigned j=0;j<a.size();++j){
                        if(SSotr[i].num==a[j].num){
                            c=1;
                            break;
                        }
                    }
                    if (c==1) continue;
                    fprintf(h, "%d) %d\n", k, SSotr[i].num);
                    a.push_back(SSotr[i]);
                    k++;
                }
            }
        } else if(t5!=0){  //"mon "
            int k=1;
            vector <SpSotr> a;
            for(unsigned i=0;i<SSotr.size();++i){
                if(SSotr[i].ID_sotr==ID_sotr){
                    bool c=0;
                    for(unsigned j=0;j<a.size();++j){
                        if(SSotr[i].mon==a[j].mon){
                            c=1;
                            break;
                        }
                    }
                    if (c==1) continue;
                    fprintf(h, "%d) %d\n", k, SSotr[i].mon);
                    a.push_back(SSotr[i]);
                    k++;
                }
            }
        }else if(t6!=0){  //"god "
            int k=1;
            vector <SpSotr> a;
            for(unsigned i=0;i<SSotr.size();++i){
                if(SSotr[i].ID_sotr==ID_sotr){
                    bool c=0;
                    for(unsigned j=0;j<a.size();++j){
                        if(SSotr[i].god==a[j].god){
                            c=1;
                            break;
                        }
                    }
                    if (c==1) continue;
                    fprintf(h, "%d) %d\n", k, SSotr[i].god);
                    a.push_back(SSotr[i]);
                    k++;
                }
            }
        }else if(t7!=0){  //"ID_fil "
            int k=1;
            vector <SpSotr> a;
            for(unsigned i=0;i<SSotr.size();++i){
                if(SSotr[i].ID_sotr==ID_sotr){
                    bool c=0;
                    for(unsigned j=0;j<a.size();++j){
                        if(SSotr[i].ID_fil==a[j].ID_fil){
                            c=1;
                            break;
                        }
                    }
                    if (c==1) continue;
                    fprintf(h, "%d) %d\n", k, SSotr[i].ID_fil);
                    a.push_back(SSotr[i]);
                    k++;
                }
            }
        }else if(t8!=0){  //"ID_sp "
            int k=1;
            vector <SpSotr> a;
            for(unsigned i=0;i<SSotr.size();++i){
                if(SSotr[i].ID_sotr==ID_sotr){
                    bool c=0;
                    for(unsigned j=0;j<a.size();++j){
                        if(SSotr[i].ID_sp==a[j].ID_sp){
                            c=1;
                            break;
                        }
                    }
                    if (c==1) continue;
                    fprintf(h, "%d) %d\n", k, SSotr[i].ID_sp);
                    a.push_back(SSotr[i]);
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

