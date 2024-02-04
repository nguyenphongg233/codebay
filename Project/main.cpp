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
    ifstream log("log.txt");

    int n;
    log >> n;

    cout << n << '\n';
    vector<string> ax;
    while(!log.eof()){
        string s;
        getline(log,s);
        cout << s << "\n";
        ax.push_back(s);
    }

    time_t now = time(0);
    char* x = ctime(&now);

    ax.push_back(x);

    // for(string v : ax){
    //     cout << v << '\n';
    // };

    for(int i = 0;i < (int)ax.size();i++){
        cout << ax[i] << "\n";
    }

}
void savedata(){
    fstream rb("database.inp");
    // dosth
}
signed main(){

    readdata();
    log();
   

    
    int a,b;
    cin >> a >> b;

    cout << a + 11 + b << '\n';
    


    // savedata();
}