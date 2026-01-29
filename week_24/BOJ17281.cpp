#include <iostream>
#include <algorithm>
using namespace std;

int N;
int st[52][10]; //이닝별 결과
int order[10];    //타순
bool used[10];
int ans;

int sim(){      //현재 타순으로 시뮬
    int score=0;
    int cur=1;
    for(int inn=1;inn<=N;inn++){
        int out=0;
        int b1=0, b2=0, b3=0;
        while(out<3){
            int player=order[cur];
            int stt=st[inn][player];
            if(stt==0){
                out++;
            }
            else if(stt==1){
                score+=b3;
                b3=b2;
                b2=b1;
                b1=1;
            }
            else if(stt==2){
                score+=(b3+b2);
                b3=b1;
                b2=1;
                b1=0;
            }
            else if(stt==3){
                score+=(b3+b2+b1);
                b3=1;
                b2=0;
                b1=0;
            }
            else{
                score+=(b3+b2+b1+1);
                b3=0;
                b2=0;
                b1=0;
            }
            cur++;
            if(cur==10) cur=1;
        }
    }
    return score;
}

void dfs(int k){    //타순 배치
    if(k==10){
        ans=max(ans, sim());
        return;
    }
    if(k==4){
        dfs(k+1);
        return;
    }

    for(int num=2;num<=9;num++){
        if(used[num]) continue;
        order[k]=num;
        used[num]=true;
        dfs(k+1);
        used[num]=false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=9;j++){
            cin >> st[i][j];
        }
    }
    order[4]=1;   //1번 타자 4번째로 고정
    used[1]=true;
    
    dfs(1);
    
    cout << ans << '\n';

    return 0;
}