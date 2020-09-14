//Join Kniga-op Kniga-eks
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

class KnOp_KnEk{
public:
    int ID_kn_ek;
    int ID_kn_op;
    string nazv;
    string avt;
    int god;
        KnOp_KnEk(const int & t_ID_kn_ek, const int & t_ID_kn_op, const string& t_nazv, const string& t_avt,
                const int & t_god){
        ID_kn_ek=t_ID_kn_ek;
        ID_kn_op=t_ID_kn_op;
        nazv=t_nazv;
        avt=t_avt;
        god=t_god;
    }
~KnOp_KnEk(){;}
};

void JoinKnEO(FILE *h, char* s, DataBase5 d5, DataBase6 d6){
vector<KnOp_KnEk> KnEO;
KnEO.reserve (3000*12000);
for(int i=0;i<12000;++i){
    for(int j=0;j<3000;++j){
        if(d6.mass[i].ID_kn_op==d5.mass[j].get_ID_kn_op()){
            KnOp_KnEk Kn(d6.mass[i].get_ID_kn_ek(),  d5.mass[j].get_ID_kn_op(),
                       d5.mass[j].nazv,  d5.mass[j].avt,   d5.mass[j].god);
            KnEO.push_back(Kn);
        }
    }
}
char* p1=strstr(s,"nazv=");
char* p2=strstr(s,"avt=");
char* p3=strstr(s,"god=");
char* p4=strstr(s,"ID_kn_ek=");
char* p5=strstr(s,"ID_kn_op=");

char* t1=strstr(s,"nazv ");
char* t2=strstr(s,"avt ");
char* t3=strstr(s,"god ");
char* t4=strstr(s,"ID_kn_ek ");
char* t5=strstr(s,"ID_kn_op ");

if(p1!=0){  //"nazv="
    char nazv [128];
    if (sscanf (p1 + 5, "%s", nazv) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t4!=0){  //"ID_kn_ek "
        int k=1;
        vector <KnOp_KnEk> a;
        for(unsigned i=0;i<KnEO.size();++i){
            if(strcmp(KnEO[i].nazv.c_str(),nazv)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(KnEO[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, KnEO[i].ID_kn_ek);
                a.push_back(KnEO[i]);
                k++;
            }
        }
    } else {
    fprintf(h,"Wrong\n");
    return;
    }
} else if (p2!=0){  //"avt="
   char avt [128];
    if (sscanf (p2 + 4, "%s", avt) != 1){
          fprintf (h,"Wrong\n");
          return;
        }
    if(t4!=0){  //"ID_kn_ek "
        int k=1;
        vector <KnOp_KnEk> a;
        for(unsigned i=0;i<KnEO.size();++i){
            if(strcmp(KnEO[i].avt.c_str(),avt)==0){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(KnEO[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, KnEO[i].ID_kn_ek);
                a.push_back(KnEO[i]);
                k++;
            }
        }
    } else {
    fprintf(h,"Wrong\n");
    return;
    }
} else if (p3!=0){  //"god="
    int god;
    if (sscanf (p3 + 4, "%d", &god) != 1){
          fprintf (h,"Wrong\n");
          return;
        }
    if(t4!=0){  //"ID_kn_ek "
        int k=1;
        vector <KnOp_KnEk> a;
        for(unsigned i=0;i<KnEO.size();++i){
            if(KnEO[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(KnEO[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, KnEO[i].ID_kn_ek);
                a.push_back(KnEO[i]);
                k++;
            }
        }
    } else {
    fprintf(h,"Wrong\n");
    return;
    }
} else if (p4!=0) {  //"ID_kn_ek="
    int ID_kn_ek;
    if (sscanf (p4 + 9, "%d", &ID_kn_ek) != 1){
          fprintf (h,"Wrong\n");
          return;
        }
    if(t1!=0){  //"nazv "
        int k=1;
        vector <KnOp_KnEk> a;
        for(unsigned i=0;i<KnEO.size();++i){
            if(KnEO[i].ID_kn_ek==ID_kn_ek){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(KnEO[i].nazv==a[j].nazv){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %s\n", k, KnEO[i].nazv.c_str());
                a.push_back(KnEO[i]);
                k++;
            }
        }
        }else if(t2!=0){
             int k=1;
            vector <KnOp_KnEk> a;
            for(unsigned i=0;i<KnEO.size();++i){
                if(KnEO[i].ID_kn_ek==ID_kn_ek){
                    bool c=0;
                    for(unsigned j=0;j<a.size();++j){
                        if(KnEO[i].avt==a[j].avt){
                            c=1;
                            break;
                        }
                    }
                    if (c==1) continue;
                    fprintf(h,"%d) %s\n", k, KnEO[i].avt.c_str());
                    a.push_back(KnEO[i]);
                    k++;
                }
            }
        }else if(t3!=0){
             int k=1;
            vector <KnOp_KnEk> a;
            for(unsigned i=0;i<KnEO.size();++i){
                if(KnEO[i].ID_kn_ek==ID_kn_ek){
                    bool c=0;
                    for(unsigned j=0;j<a.size();++j){
                        if(KnEO[i].god==a[j].god){
                            c=1;
                            break;
                        }
                    }
                    if (c==1) continue;
                    fprintf(h,"%d) %d\n", k, KnEO[i].god);
                    a.push_back(KnEO[i]);
                    k++;
                }
            }
        }else if(t5!=0){
             int k=1;
            vector <KnOp_KnEk> a;
            for(unsigned i=0;i<KnEO.size();++i){
                if(KnEO[i].ID_kn_ek==ID_kn_ek){
                    bool c=0;
                    for(unsigned j=0;j<a.size();++j){
                        if(KnEO[i].ID_kn_op==a[j].ID_kn_op){
                            c=1;
                            break;
                        }
                    }
                    if (c==1) continue;
                    fprintf(h,"%d) %d\n", k, KnEO[i].ID_kn_op);
                    a.push_back(KnEO[i]);
                    k++;
                }
            }
        }else{
            fprintf(h,"Wrong\n");
            return;
        }
} else if (p5!=0){  //"ID_kn_op="
    int ID_kn_op;
    if (sscanf (p5 + 9, "%d", &ID_kn_op) != 1){
          fprintf (h,"Wrong\n");
          return;
        }
    if(t4!=0){  //"ID_kn_ek "
        int k=1;
        vector <KnOp_KnEk> a;
        for(unsigned i=0;i<KnEO.size();++i){
            if(KnEO[i].ID_kn_op==ID_kn_op){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(KnEO[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, KnEO[i].ID_kn_ek);
                a.push_back(KnEO[i]);
                k++;
            }
        }
    } else {
    fprintf( h,"Wrong\n");
    return;
    }
    }else{
    fprintf(h,"Wrong query\n");
    return;
    }
return;
}
