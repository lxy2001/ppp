#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
struct student{
    char num[10];
    char college[10];
    char name[10];
    char tname[10];
    int score[8]={0};
    double average_score;
    double average_score2;
    int location;
};
struct zuida{
    int e;
    int max;
};
struct zuixiao{
    int w;
    int min;
};
bool paixu(const student &s1,const student &s2){
    return s1.average_score2>s2.average_score2;
}
int main (){
    int n=4,y=0;
    student m[n];
    zuida a[n];
    zuixiao b[n];
    
    ifstream outf("/Users/s20181106279/Desktop/ggg.txt");
    ifstream out("/Users/s20181106279/Desktop/eee.txt");
    for(int i=0;i<n;i++){
        out>>m[i].num>>m[i].college>>m[i].name;
    }
    for(int i=0;i<n;i++){
        outf>>m[i].tname;
        for(int j=0;j<7;j++){
            outf>>m[i].score[j];
        }
    }
    for(int i=0;i<n;i++){
        a[i].max=m[i].score[0];
        a[i].e=0;
        b[i].min=m[i].score[0];
        b[i].w=0;
        for(int j=1;j<7;j++){
            if(a[i].max<m[i].score[j]){
                a[i].max=m[i].score[j];
                a[i].e=j;
            }
            if(b[i].min>m[i].score[j]){
                b[i].min=m[i].score[j];
                b[i].w=j;
            }
        }
    }
    for(int i=0;i<n;i++){
        double v=0;
        for(int k=0;k<7;k++){
            if(k!=a[i].e&&k!=b[i].w){
                v=v+m[i].score[k];
            }
        }
        m[y].average_score=v*1.0/5;
        m[y].average_score2=v*1.0/5;
        y++;
    }
    sort(m,m+n,paixu);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i].average_score2==m[j].average_score){
                m[i].location=j;
            }
        }
    }
    ofstream in("/Users/s20181106279/Desktop/88.txt");
    if(in.is_open())
    {
        for(int i=0;i<4;i++){
            in<<m[m[i].location].num<<" "<<m[m[i].location].college<<" "<<m[m[i].location].name
            <<" "<<"排名:"<<i+1<<" "<<"平均分:"<<m[i].average_score2<<endl;
        }
        in.close();
    }
    return 0;
    
}
