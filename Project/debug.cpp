#include<bits/stdc++.h>

using namespace std;

#define read() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define day() time_t now = time(0);char* x = ctime(&now);cerr<<"Right Now Is : "<<x<<"\n"

#define ii pair<int,int>
#define X first
#define Y second 

const long long MAX = (int)1e5 + 5;
const long long INF = (int)1e9;
const long long MOD = (int)1e9 + 7;

struct data{
    
};
void readdata(){
    ifstream inp("database.inp");
}
void log(){
    ifstream logx("log.txt");
    fstream nowx("log.txt");
    vector<string> st;
    while(!logx.eof()){
        string sx;
        getline(logx,sx);
        if(sx == "")break;
        nowx << sx << "\n";
    }
    
    time_t now = time(0);
    char* x = ctime(&now);
    nowx << x;
}
void savedata(){
    fstream rb("database.inp");
    // dosth
}
signed main(){

    readdata();
    log();


    savedata();
}