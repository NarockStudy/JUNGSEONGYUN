#include <iostream>
using namespace std;

int n;
int sfty[202];
bool vis[202];

//n번칸
int rr(int fr){
    return (fr+n-2)%(2*n)+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> n >> k;
    for(int i=1;i<=2*n;i++)
        cin >> sfty[i];
    
    int cnt_z=0;
    int fr=1;  //1번칸
    int ans=0;
    while(1){
        ans++;
        //1. 무빙워크 한 칸 회전
        fr=(fr-1-1+2*n)%(2*n)+1;
        if(vis[rr(fr)]) vis[rr(fr)]=false;
        //2. 먼저 탄 사람부터 이동
        for(int i=1;i<n;i++){
            int cur=(fr+n-2-i)%(2*n)+1;
            int nxt=cur%(2*n)+1;
            if(vis[cur]){
                if(vis[nxt]||sfty[nxt]==0) continue;
                sfty[nxt]--;
                if(sfty[nxt]==0){
                    cnt_z++;
                }
                vis[cur]=false;
                if(nxt!=rr(fr)){
                    vis[nxt]=true;
                }
            }
        }
        //3. 1번칸 추가
        if(!vis[fr]&&sfty[fr]!=0){
            vis[fr]=true;
            sfty[fr]--;
            if(sfty[fr]==0){
                cnt_z++;
            }
        }
        //4. 안정성 체크
        if(cnt_z>=k){
            break;
        }
    }
    cout << ans;

    return 0;
}