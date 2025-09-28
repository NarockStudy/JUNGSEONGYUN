#include <iostream>
using namespace std;

int a,b;

void rec(int n, int m, int x, int y, int d){
    if(n==1){
        a =x, b=y;
        return;
    }

    int half=n/2;
    int part=half*half;
    
    if(d==0){   
        if(m<=part)          rec(half,m,x,y,1);   
        else if(m<=part*2)   rec(half,m-part,x,y+half,0);   
        else if(m<=part*3)   rec(half,m-part*2,x+half,y+half,0);   
        else if(m<=part*4)   rec(half,m-part*3,x+half,y,2);  
    }
    if(d==1){   
        if(m<=part)          rec(half,m,x,y,0);   
        else if(m<=part*2)   rec(half,m-part,x+half,y,1);   
        else if(m<=part*3)   rec(half,m-part*2,x+half,y+half,1);    
        else if(m<=part*4)   rec(half,m-part*3,x,y+half,3);   
    }
    if(d==2){   
        if(m<=part)          rec(half,m,x+half,y+half,3);   
        else if(m<=part*2)   rec(half,m-part,x,y+half,2);   
        else if(m<=part*3)   rec(half,m-part*2,x,y,2);   
        else if(m<=part*4)   rec(half,m-part*3,x+half,y,0);  
    }
    if(d==3){   
        if(m<=part)          rec(half,m,x+half,y+half,2);  
        else if(m<=part*2)   rec(half,m-part,x+half,y,3);  
        else if(m<=part*3)   rec(half,m-part*2,x,y,3);   
        else if(m<=part*4)   rec(half,m-part*3,x,y+half,1);   
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    rec(n,m,1,1,0);
    cout << a << ' ' << b << '\n';

    return 0;
}