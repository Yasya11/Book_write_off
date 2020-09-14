//Join Stroka Kniga-eks
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

class StrKn_ek{
public:
    int ID_str_sp;
    int ID_kn_ek;
    int ID_kn_op;
        StrKn_ek(const int & t_ID_str_sp, const int & t_ID_kn_ek, const int & t_ID_kn_op){
        ID_str_sp=t_ID_str_sp;
        ID_kn_ek=t_ID_kn_ek;
        ID_kn_op=t_ID_kn_op;
    }
~StrKn_ek(){;}
};

void JoinStrKn_ek(FILE *h, char* s, DataBase4 d4, DataBase6 d6){
vector<StrKn_ek> StrKn;
StrKn.reserve (480*3000);
for(int i=0;i<480;++i){
    for(int j=0;j<3000;++j){
        if(d4.mass[i].ID_kn_ek==d6.mass[j].get_ID_kn_ek()){
            StrKn_ek SK(d4.mass[i].get_ID_str_sp(),  d6.mass[j].get_ID_kn_ek(), d6.mass[i].ID_kn_op);
            StrKn.push_back(SK);
        }
    }
}
char* p1=strstr(s,"ID_str_sp=");
char* p2=strstr(s,"ID_kn_ek=");
char* p3=strstr(s,"ID_kn_op=");

char* t1=strstr(s,"ID_str_sp ");
char* t2=strstr(s,"ID_kn_ek ");
char* t3=strstr(s,"ID_kn_op ");

if(p1!=0){  //"ID_str_sp="
    int ID_str_sp;
    if (sscanf (p1 + 10, "%d", &ID_str_sp) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t2!=0){  //"ID_kn_ek "
        int k=1;
        vector <StrKn_ek> a;
        for(unsigned i=0;i<StrKn.size();++i){
            if(StrKn[i].ID_str_sp==ID_str_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(StrKn[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, StrKn[i].ID_kn_ek);
                a.push_back(StrKn[i]);
                k++;
            }
        }
    }else if(t3!=0){  //"ID_kn_op "
        int k=1;
        vector <StrKn_ek> a;
        for(unsigned i=0;i<StrKn.size();++i){
            if(StrKn[i].ID_str_sp==ID_str_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(StrKn[i].ID_kn_op==a[j].ID_kn_op){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf( h,"%d) %d\n", k, StrKn[i].ID_kn_op);
                a.push_back(StrKn[i]);
                k++;
            }
        }
    } else{
        fprintf( h,"Wrong\n");
        return;
    }
} else if (p2!=0){  //"ID_kn_ek="
    int ID_kn_ek;
    if (sscanf (p2 + 9, "%d", &ID_kn_ek) != 1){
          fprintf ( h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"ID_str_sp "
        int k=1;
        vector <StrKn_ek> a;
        for(unsigned i=0;i<StrKn.size();++i){
            if(StrKn[i].ID_kn_ek==ID_kn_ek){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(StrKn[i].ID_str_sp==a[j].ID_str_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf( h,"%d) %d\n", k, StrKn[i].ID_str_sp);
                a.push_back(StrKn[i]);
                k++;
            }
        }
     }else{
        fprintf( h,"Wrong\n");
        return;
    }
}else if(p3!=0){  //"ID_kn_op="
    int ID_kn_op;
    if (sscanf (p3 + 9, "%d", &ID_kn_op) != 1){
          fprintf ( h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"ID_str_sp "
        int k=1;
        vector <StrKn_ek> a;
        for(unsigned i=0;i<StrKn.size();++i){
            if(StrKn[i].ID_kn_op==ID_kn_op){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(StrKn[i].ID_str_sp==a[j].ID_str_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf( h, "%d) %d\n", k, StrKn[i].ID_str_sp);
                a.push_back(StrKn[i]);
                k++;
            }
        }
     }else{
        fprintf( h, "Wrong\n");
        return;
    }
}else{
    fprintf( h, "Wrong query\n");
    return;
}
return;
}



