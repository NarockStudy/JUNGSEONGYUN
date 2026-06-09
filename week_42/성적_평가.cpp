#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v(N,0); //개인별 점수 합 
    
    /*
    //정렬
    //각 대회별 등수 처리 
    for(int i=0;i<3;i++){
        vector<int> score(N);
        //입력
        for(int j=0;j<N;j++){
            int cur;
            cin >> cur;
            board[j]=cur;
            score[j]=cur;
            v[j]+=cur;
        }
        
        //정렬 및 등수 계산
        //"나보다 점수가 큰 사람"의 수를 세어 1을 더한 것이 자신의 등수
        sort(score.begin(),score.end());
        for(int j=0;j<N;j++){
            int s=board[j];
            int cnt=N-(upper_bound(score.begin(),score.end(),s)-score.begin());
            cout << cnt+1 << ' ';
        }
        cout << '\n';
    }
    
    //전체 등수 처리
    vector<int> tmp=v;
    sort(tmp.begin(), tmp.end());
    for(int i=0;i<N;i++){
        int s=v[i];
        int cnt=N-(upper_bound(tmp.begin(),tmp.end(),s)-tmp.begin());
        cout << cnt+1 << ' ';
    }
    */

    
    //배열 카운팅
    //각 대회별 등수 처리
    for(int i=0;i<3;i++){
        int score[1001]={0,};
        int rnk[1001]={0,};
        //입력
        for(int j=0;j<N;j++){
            int cur;
            cin >> cur;
            board[j]=cur;
            score[cur]++;
            v[j]+=cur;
        }
        int num=0;
        //각 점수별 등수 계산
        for(int j=1000;j>=0;j--){
            if(score[j]!=0){
                rnk[j]=num+1;
                num+=score[j];
            }
        }
        //출력
        for(int j=0;j<N;j++){
            cout << rnk[board[j]] << ' ';
        }
        cout << '\n';
    }

    //전체 등수 처리
    int score[3001]={0,};
    int rnk[3001]={0,};
    int n=0;
    for(auto& i:v){
        score[i]++;
    }
    //각 점수별 등수 계산
    for(int i=3000;i>=0;i--){
        if(score[i]!=0){
            rnk[i]=n+1;
            n+=score[i];
        }
    }
    //출력 
    for(auto& i:v){
        cout << rnk[i] << ' ';
    }
    

    return 0;
}