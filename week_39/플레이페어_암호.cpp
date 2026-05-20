#include <iostream>
#include <string>
#include <vector>
using namespace std;

char board[6][6];
pair<int,int> p[26];

void mk_board(string& k){
    bool used[26]={false,};
    used['J'-'A']=true;
    int cur=1;

    //key먼저 채우고
    for(char& c:k){
        if(used[c-'A']) continue;
        used[c-'A']=true;
        int x=(cur-1)/5;
        int y=(cur-1)%5;
        board[x][y]=c;
        p[c-'A']={x,y};
        cur++;
    }
    //나머지 채우기
    for(int i=0;i<26;i++){
        if(used[i]) continue;
        used[i]=true;
        int x=(cur-1)/5;
        int y=(cur-1)%5;
        board[x][y]='A'+i;
        p[i]={x,y};
        cur++;
    }
}

vector<string> split_msg(string& s){
    vector<string> vs;
    int idx=0;
    int sz=s.size();

    while(idx<sz){
        char cur=s[idx];
        idx++;
        char t;
        
        //끝에 한글자만 남을 때
        if(idx==sz){
            //t = (cur=='X')? 'Q':'X';
            t='X';
        }

        else if(cur!=s[idx]){
            t=s[idx];
            idx++;
        }
        else{
            t = (cur=='X')? 'Q':'X';
        }

        vs.push_back({cur,t});
    }
    return vs;
}

string enc_k(string& s, string& k){
    mk_board(k);
    vector<string> vs=split_msg(s);
    string ans="";

    for(auto& w:vs){
        int x1=p[w[0]-'A'].first,
            y1=p[w[0]-'A'].second,
            x2=p[w[1]-'A'].first,
            y2=p[w[1]-'A'].second;
        
        //1.같은 행
        if(x1==x2){
            int ny1=(y1+1)%5;
            int ny2=(y2+1)%5;
            ans+=board[x1][ny1];
            ans+=board[x2][ny2];
        }
        else if(y1==y2){
            int nx1=(x1+1)%5;
            int nx2=(x2+1)%5;
            ans+=board[nx1][y1];
            ans+=board[nx2][y2];
        }
        else{
            int ny1=y2;
            int ny2=y1;
            ans+=board[x1][ny1];
            ans+=board[x2][ny2];
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, k;
    cin >> s >> k;

    string ans=enc_k(s,k);

    cout << ans << '\n';

    return 0;
}