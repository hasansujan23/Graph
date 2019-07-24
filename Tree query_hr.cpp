#include<bits/stdc++.h>
using namespace std;
#define M 100010

int inDeg[M];
int outDeg[M];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        inDeg[y]++;
        outDeg[x]++;
    }

    int mx1=0,mx2=0;

    for(int i=1;i<=n;i++){
        if(inDeg[i]==0)
            mx1++;
        if(outDeg[i]==0)
            mx2++;
    }


    cout<<max(mx1,mx2)<<endl;

    return 0;
}
