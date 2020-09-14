//Join Filial Sotrudnik
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

class FilSotr{
public:
    int ID_sotr;
    int ID_fil;
    string name;
    string nazv;
    string adr;
    string sur;
    string pos;
        FilSotr(int t_ID_sotr, int t_ID_fil, const string& t_name, const string& t_nazv,
                const string& t_adr, const string& t_sur, const string& t_pos){
        ID_sotr=t_ID_sotr;
        ID_fil=t_ID_fil;
        name=t_name;
        nazv=t_nazv;
        adr=t_adr;
        sur=t_sur;
        pos=t_pos;
    }
~FilSotr(){;}
};

void JoinFSotr(FILE* h, char* s, DataBase1 d1, DataBase3 d3){
vector<FilSotr> FSotr;
FSotr.reserve (70*15);
for(int i=0;i<70;++i){
    for(int j=0;j<15;++j){
        if(d1.mass[i].ID_fil==d3.mass[j].get_ID_fil()){
            FilSotr FS(d1.mass[i].get_ID_sotr(),  d3.mass[j].get_ID_fil(),
                       d1.mass[i].name,  d3.mass[j].nazv,   d3.mass[j].adr,
                       d1.mass[i].surname,  d1.mass[i].position);
            FSotr.push_back(FS);
        }
    }
}
char* p1=strstr(s,"nazv=");
char* p2=strstr(s,"adr=");
char* p3=strstr(s,"name=");
char* p4=strstr(s,"sur=");
char* p5=strstr(s,"pos=");
char* p6=strstr(s,"ID_fil=");
char* p7=strstr(s,"ID_sotr=");

char* t1=strstr(s,"nazv ");
char* t2=strstr(s,"adr ");
char* t3=strstr(s,"name ");
char* t4=strstr(s,"sur ");
char* t5=strstr(s,"pos ");
char* t6=strstr(s,"ID_fil ");
char* t7=strstr(s,"ID_sotr ");
if(p1!=0){  //"nazv="
    char nazv [128];
    if (sscanf (p1 + 5, "%s", nazv) != 1){
          fprintf (h,"Wrong\n");
          return;
        }
    if(t3!=0){  //"name "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].name==a[j].name){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].name.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    } else if(t4!=0){  //"sur "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].sur==a[j].sur){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].sur.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    }else if(t5!=0){  //"pos "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].pos==a[j].pos){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].pos.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    }else if(t7!=0){  //"ID_sotr "
            int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSotr[i].ID_sotr);
                a.push_back(FSotr[i]);
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
    if(t3!=0){  //"name "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].adr.c_str(),adr)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].name==a[j].name){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].name.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    } else if(t4!=0){  //"sur "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].adr.c_str(),adr)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].sur==a[j].sur){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].sur.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    }else if(t5!=0){  //"pos "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].adr.c_str(),adr)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].pos==a[j].pos){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].pos.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
        } else if(t7!=0){  //"ID_sotr "
            int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].adr.c_str(),adr)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, FSotr[i].ID_sotr);
                a.push_back(FSotr[i]);
                k++;
            }
        }
            }else{
    fprintf(h, "Wrong\n");
    return;
    }
} else if (p3!=0){  //"name="
    char name [128];
    if (sscanf (p3 + 5, "%s", name) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"nazv "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].name.c_str(),name)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %s\n", k, FSotr[i].nazv.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"adr "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].name.c_str(),name)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].adr==a[j].adr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].adr.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"ID_fil "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].name.c_str(),name)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSotr[i].ID_fil);
                a.push_back(FSotr[i]);
                k++;
            }
        }
        }else{
    fprintf(h, "Wrong\n");
    return;
    }
} else if (p4!=0) {  //"sur="
    char sur [128];
    if (sscanf (p4 + 4, "%s", sur) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"nazv "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].sur.c_str(),sur)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].nazv.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"adr "
        int k=1;

        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].sur.c_str(),sur)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].adr==a[j].adr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].adr.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"ID_fil "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].sur.c_str(),sur)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSotr[i].ID_fil);
                a.push_back(FSotr[i]);
                k++;
            }
        }
        }else{
    fprintf(h, "Wrong\n");
    return;
    }
} else if (p5!=0){  //"pos="
    char pos [128];
    if (sscanf (p5 + 4, "%s", pos) != 1){
          fprintf (h,"Wrong\n");
          return;
        }
    if(t1!=0){  //"nazv "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].pos.c_str(),pos)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].nazv.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"adr "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].pos.c_str(),pos)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].adr==a[j].adr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].adr.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"ID_fil "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(strcmp(FSotr[i].pos.c_str(),pos)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSotr[i].ID_fil);
                a.push_back(FSotr[i]);
                k++;
            }
        }
        }else{
    fprintf(h, "Wrong\n");
    return;
    }
} else if(p6!=0){   //"ID_fil="
    int ID_fil;
    if (sscanf (p6 + 7, "%d", &ID_fil) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t3!=0){  //"name "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(FSotr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].name==a[j].name){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].name.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    } else if(t4!=0){ //"sur "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(FSotr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].sur==a[j].sur){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].sur.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    }else if(t5!=0){  //"pos "
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(FSotr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j = 0; j < a.size(); ++j){
                    if(FSotr[i].pos==a[j].pos){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].pos.c_str());
                a.push_back (FSotr[i]);
                k++;
            }
        }
    }else if(t7!=0){  //"ID_sotr "
            int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(FSotr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSotr[i].ID_sotr);
                a.push_back (FSotr[i]);
                k++;
            }
        }
            }else{
    fprintf(h, "Wrong\n");
    return;
    }
    }else if(p7!=0){  //"ID_sotr="
         int ID_sotr;
    if (sscanf (p7 + 8, "%d", &ID_sotr) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(FSotr[i].ID_sotr==ID_sotr){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].nazv.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    } else if(t2!=0){
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(FSotr[i].ID_sotr==ID_sotr){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].adr==a[j].adr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %s\n", k, FSotr[i].adr.c_str());
                a.push_back(FSotr[i]);
                k++;
            }
        }
    }else if(t6!=0){
        int k=1;
        vector <FilSotr> a;
        for(unsigned i=0;i<FSotr.size();++i){
            if(FSotr[i].ID_sotr==ID_sotr){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(FSotr[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, FSotr[i].ID_fil);
                a.push_back(FSotr[i]);
                k++;
            }
        }
        }else{
    fprintf(h,"Wrong\n");
    return;
    }
        }else{
fprintf(h,"Wrong query\n");
return;
}
return;
}

