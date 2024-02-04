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

int ran(int l,int r){
    srand(time(0));
    return rand() % (r - l + 1) + l;
};

int n;
struct data{
    string name;
    string password;
    int money;
}player[MAX];

struct node{
    node *a[26];
    int id;
    
    node(){
        for(int i = 0;i < 26;i++){
            a[i] = NULL;
        }
        id = 0;
    }
};
node *root;
void addroot(string s,int id){
    node *rt = root;
    for(int i = 0;i < (int)s.size();i++){
        if(rt -> a[s[i] - 'a'] == NULL)rt -> a[s[i] - 'a'] = new node();
        rt = rt -> a[s[i] - 'a'];
    }
    rt -> id = id;
}
int ok(string s){
    node *rt = root;
    for(int i = 0;i < (int)s.size();i++){
        if(rt -> a[s[i] - 'a'] == NULL)return 0;
        rt = rt -> a[s[i] - 'a'];
    }
    return (int)rt -> id;
}
void readdata(){
    ifstream inp("database.inp");
    root = new node();

    inp >> n;
    for(int i = 1;i <= n;i++){
        inp >> player[i].name >> player[i].password >> player[i].money;
        addroot(player[i].name,i);
    }
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
    rb << n << '\n';
    for(int i = 1;i <= n;i++){
        rb << player[i].name << " " << player[i].password << " " << player[i].money << "\n";
    }
    // dosth
}
bool odd_or_even(){
    cout << "1 or 0\n";
    int x;
    cin >> x;
    int y = ran(0,1);

    if(x == y)return 1;
    else return 0;
}
void addplayer(){
    n++;
    cout << "Username : ";
    cin >> player[n].name;
    while(player[n].name == "" || ok(player[n].name) > 0){
        cout << "Fill other username : ";
        cin >> player[n].name;
    }
    cout << "Password : ";
    cin >> player[n].password;
    cout << "You have receive 1000 dola\n";
    player[n].money = 1000;
}
int payy(int id){
    int bet = 0;
    cout << "BET : \n";
    cin >> bet;
    int cnt = 0;
    while(bet > player[id].money){
        
        cnt++;
        if(cnt >= 5){
            cout << "Go away mendicity\n";
            return -1;
        }
        
        cout << "You dont have enough money!\n";
        cout << "Enter how much money do you want to bet :\n";
        cin >> bet;
        
    }
    return bet;
}
void calc(int id,bool ok,int x){
    player[id].money += (ok) ? x : -x;
    if(ok)cout << "You won " << x << " dola\n";
    else cout << "You lost " << x << " dola\n";
}
void menu(int id){

    cout << "Choose your game : \n";
    cout << "[1] : ODD or EVEN \n";

    int chx;
    cin >> chx;

    switch(chx){
        case 1 : {
            int x = payy(id);
            if(x == -1)return;
            calc(id,odd_or_even(),x);
        }
    }


    cout << "Do you want to play more (1,0) :\n";
    int x;
    cin >> x;
    if(x == 1)menu(id);
    
    menu(id);
}
void profile(){
    cout << "Player count : " << n << '\n';
    for(int i = 1;i <= n;i++){
        cout << "[" << i << "] (n,p,m): " << player[i].name << " " << player[i].password << " " << player[i].money << '\n';
    }
}
signed main(){

    readdata();
    log();

    cout << "Wellcome to nguyenphong233'casino \n";
    cout << "Do you have an account ? (y/n)\n";

    char x;
    cin >> x;

    if(x == 'y' || x == 'Y'){

        int xx = 0;

        while(xx == 0){
            cout << "Username : ";
            string s,t;
            cin >> s;
            cout << "Password : ";
            cin >> t;
            
            xx = ok(s);
            if(xx == 0 || player[xx].password != t)cout << "Wrong username or password\n";
        }
        if(xx == 1){
            cout << "Do you want to save database boss ? (0,1)\n";
            bool x;
            cin >> x;
            if(x == 1){
                profile();
            }
        }
        menu(xx);
    }else{
        addplayer();
        menu(n);
    }




    //profile();
    savedata();
}