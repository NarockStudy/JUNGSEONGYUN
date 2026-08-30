#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
vector<int> graph[100001];
vector<int> start_points;

void bfs(int S, vector<int>& dist){
    queue<int> q;
    q.push(S);
    dist[S]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int dst : graph[cur]){
            if(dist[dst]!=-1) continue;
            dist[dst]=dist[cur]+1;
            q.push(dst);   
        }
    }
    return;
}

int main() {
    cin >> n >> m >> k;
    vector<vector<int>> dist(k, vector<int>(n+1,-1)); //각 사람별 거리

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    start_points.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> start_points[i];
    }

    //사람별로 모든 도시 거리 계산
    for(int i=0;i<k;i++){
        bfs(start_points[i], dist[i]);
    }

    //가장 오래걸리는 사람의 시간의 최솟값 구하기 
    int ans=n;
    for(int i=1;i<=n;i++){
        int tmp=0;
        bool flag=false;    //도달 불가 판정
        for(int j=0;j<k;j++){
            if(dist[j][i]==-1){
                flag=true;
                break;
            }
            tmp=max(tmp,dist[j][i]);    //가장 오래 걸리는 시간
        }
        if(flag) continue;
        ans=min(ans,tmp);   //도시들 중 최솟값
    }
    if(ans==n) ans=-1;
    cout << ans;

    return 0;
}
