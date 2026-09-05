#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;   //홀수만 입력됨

    long long WW = 4*(N-1)  //모서리 블록만 사용
                    *6      //6면
                    /2      //모서리 블록은 흰검이 번갈아 나오므로 그 중 흰색만
                    /2;     //도미노는 2칸을 차지 
    long long BB = WW;      //흰흰이나 검검은 타입만 바꾸면 같음
    long long WB = N*N*6/2; //전체 개수 /2

    cout << WW << ' ' << BB << ' ' << WB;

    return 0;
}