#include <iostream>
using namespace std;

int A[5002];    //A값
int P[5002];    //A(i)-A(i+1)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //입력
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    int ans=0;

    //burst전 미리 계산
    int psum=0; //P누적합
    for(int i=0;i<N-1;i++){
        P[i]=abs(A[i]-A[i+1]);
        psum+=P[i];
    }

    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            int c1=i;
            int c2=j;
            int sum=psum;
            //c1&c2가 연속x
            if(c1+1<c2){
                if(0<=c1-1){
                    sum+=abs(A[c1-1]-A[c1]*2)-abs(A[c1-1]-A[c1]);
                }
                sum+=abs(A[c1]*2-A[c1+1])-abs(A[c1]-A[c1+1]);
                sum+=abs(A[c2-1]-A[c2]*2)-abs(A[c2-1]-A[c2]);
                if(c2+1<=N-1){
                    sum+=abs(A[c2]*2-A[c2+1])-abs(A[c2]-A[c2+1]);
                }
            }
            //c1&c2 연속
            else{
                if(0<=c1-1){
                    sum+=abs(A[c1-1]-A[c1]*2)-abs(A[c1-1]-A[c1]);
                }
                sum+=abs(A[c1]*2-A[c1+1]*2)-abs(A[c1]-A[c1+1]);
                if(c2+1<=N-1){
                    sum+=abs(A[c2]*2-A[c2+1])-abs(A[c2]-A[c2+1]);
                }
            }
            ans=max(ans, sum);
        }
    }

    cout << ans;

    return 0;
}