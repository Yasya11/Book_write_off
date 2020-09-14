//Join Stroka Spisanie
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

class SpStr{
public:
    int ID_str_sp;
    int ID_sp;
    int num;
    int mon;
    int god;
    int ID_fil;
    int ID_sotr;
    int ID_kn_ek;
        SpStr(const int & t_ID_str_sp, const int & t_ID_sp, int & t_num,
              int & t_mon, int & t_god, int & t_ID_fil, const int & t_ID_sotr, const int & t_ID_kn_ek){
        ID_str_sp=t_ID_str_sp;
        ID_sp=t_ID_sp;
        num=t_num;
        mon=t_mon;
        god=t_god;
        ID_fil=t_ID_fil;
        ID_sotr=t_ID_sotr;
        ID_kn_ek=t_ID_kn_ek;
    }
~SpStr(){;}
};

void JoinStrSp(FILE* h, char* s, DataBase2 d2, DataBase4 d4){
vector<SpStr> SStr;
SStr.reserve (480*120);
for(int i=0;i<480;++i){
    for(int j=0;j<120;++j){
        if(d2.mass[j].get_ID_sp()==d4.mass[i].ID_sp){
            SpStr SpS(d4.mass[i].get_ID_str_sp(),  d2.mass[j].get_ID_sp(), d2.mass[j].number,
                       d2.mass[j].month, d2.mass[j].year, d2.mass[j].ID_fil,d2.mass[j].ID_sotr, d4.mass[i].ID_kn_ek);
            SStr.push_back(SpS);
        }
    }
}
char* p1=strstr(s,"num=");
char* p2=strstr(s,"mon=");
char* p3=strstr(s,"god=");
char* p4=strstr(s,"ID_fil=");
char* p5=strstr(s,"ID_sotr=");
char* p6=strstr(s,"ID_sp=");
char* p7=strstr(s,"ID_kn_ek=");
char* p8=strstr(s,"ID_str_sp=");

char* t1=strstr(s,"num ");
char* t2=strstr(s,"mon ");
char* t3=strstr(s,"god ");
char* t4=strstr(s,"ID_fil ");
char* t5=strstr(s,"ID_sotr ");
char* t6=strstr(s,"ID_sp ");
char* t7=strstr(s,"ID_kn_ek ");
char* t8=strstr(s,"ID_str_sp ");

if(p1!=0){  //"num="
    int num;
    if (sscanf (p1 + 4, "%d", &num) != 1){
          fprintf ( h, "Wrong\n");
          return;
        }
    if(t7!=0){  //"ID_kn_ek "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].num==num){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_kn_ek);
                a.push_back(SStr[i]);
                k++;
            }
        }
    } else if(t8!=0){  //"ID_str_sp "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].num==num){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_str_sp==a[j].ID_str_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_str_sp);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if (p2!=0){  //"mon="
   int mon;
    if (sscanf (p2 + 4, "%d", &mon) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t7!=0){  //"ID_kn_ek "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].mon==mon){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_kn_ek);
                a.push_back(SStr[i]);
                k++;
            }
        }
    } else if(t8!=0){  //"ID_str_sp "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].mon==mon){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_str_sp==a[j].ID_str_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_str_sp);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if (p3!=0){  //"god="
    int god;
    if (sscanf (p3 + 4, "%d", &god) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t7!=0){  //"ID_kn_ek "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_kn_ek);
                a.push_back(SStr[i]);
                k++;
            }
        }
    } else if(t8!=0){  //"ID_str_sp "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].god==god){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_str_sp==a[j].ID_str_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf( h, "%d) %d\n", k, SStr[i].ID_str_sp);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else{
        fprintf( h, "Wrong\n");
        return;
    }
} else if (p4!=0) {  //"ID_fil="
    int ID_fil;
    if (sscanf (p4 + 7, "%d", &ID_fil) != 1){
          fprintf ( h, "Wrong\n");
          return;
        }
    if(t7!=0){  //"ID_kn_ek "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_kn_ek);
                a.push_back(SStr[i]);
                k++;
            }
        }
    } else if(t8!=0){  //"ID_str_sp "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_fil==ID_fil){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_str_sp==a[j].ID_str_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_str_sp);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if (p5!=0){  //"ID_sotr="
    int ID_sotr;
    if (sscanf (p5 + 8, "%d", &ID_sotr) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t7!=0){  //"ID_kn_ek "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_sotr==ID_sotr){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_kn_ek);
                a.push_back(SStr[i]);
                k++;
            }
        }
    } else if(t8!=0){  //"ID_str_sp "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_sotr==ID_sotr){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_str_sp==a[j].ID_str_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_str_sp);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
} else if(p6!=0){   //"ID_sp="
    int ID_sp;
    if (sscanf (p6 + 6, "%d", &ID_sp) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t7!=0){  //"ID_kn_ek "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_sp==ID_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_kn_ek==a[j].ID_kn_ek){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_kn_ek);
                a.push_back(SStr[i]);
                k++;
            }
        }
    } else if(t8!=0){  //"ID_str_sp "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_sp==ID_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_str_sp==a[j].ID_str_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_str_sp);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
}else if(p7!=0){  //"ID_kn_ek="
    int ID_kn_ek;
    if (sscanf (p7 + 9, "%d", &ID_kn_ek) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"num "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_kn_ek==ID_kn_ek){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].num==a[j].num){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].num);
                a.push_back(SStr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"mon "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_kn_ek==ID_kn_ek){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].mon==a[j].mon){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].mon);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else if(t3!=0){ //"god "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_kn_ek==ID_kn_ek){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].god==a[j].god){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].god);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else if(t4!=0){  //"ID_fil "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_kn_ek==ID_kn_ek){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_fil);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else if(t5!=0){  //"ID_sotr "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_kn_ek==ID_kn_ek){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_sotr);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else if(t6!=0){  //"ID_sp "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_kn_ek==ID_kn_ek){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_sp==a[j].ID_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].ID_sp);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else{
        fprintf(h, "Wrong\n");
        return;
    }
    }else if(p8!=0){  //"ID_str_sp="
    int ID_str_sp;
    if (sscanf (p8 + 10, "%d", &ID_str_sp) != 1){
          fprintf (h, "Wrong\n");
          return;
        }
    if(t1!=0){  //"num "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_str_sp==ID_str_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].num==a[j].num){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h, "%d) %d\n", k, SStr[i].num);
                a.push_back(SStr[i]);
                k++;
            }
        }
    } else if(t2!=0){  //"mon "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_str_sp==ID_str_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].mon==a[j].mon){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf( h, "%d) %d\n", k, SStr[i].mon);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else if(t3!=0){ //"god "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_str_sp==ID_str_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].god==a[j].god){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf( h,"%d) %d\n", k, SStr[i].god);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else if(t4!=0){  //"ID_fil "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_str_sp==ID_str_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_fil==a[j].ID_fil){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf( h, "%d) %d\n", k, SStr[i].ID_fil);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else if(t5!=0){  //"ID_sotr "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_str_sp==ID_str_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_sotr==a[j].ID_sotr){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf( h,"%d) %d\n", k, SStr[i].ID_sotr);
                a.push_back(SStr[i]);
                k++;
            }
        }
    }else if(p6!=0){  //"ID_sp "
        int k=1;
        vector <SpStr> a;
        for(unsigned i=0;i<SStr.size();++i){
            if(SStr[i].ID_str_sp==ID_str_sp){
                bool c=0;
                for(unsigned j=0;j<a.size();++j){
                    if(SStr[i].ID_sp==a[j].ID_sp){
                        c=1;
                        break;
                    }
                }
                if (c==1) continue;
                fprintf(h,"%d) %d\n", k, SStr[i].ID_sp);
                a.push_back(SStr[i]);
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


