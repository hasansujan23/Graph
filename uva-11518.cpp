#include<bits/stdc++.h>
using namespace std;
#define M 10010

vector<int>v[M];
int visit[M];

void dfs(int s){
    if(visit[s]==1)
        return;
    visit[s]=1;

    for(int i=0;i<v[s].size();i++){
        dfs(v[s][i]);
    }
}


int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n,m,l;
        cin>>n>>m>>l;

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);

        }
        for(int i=0;i<l;i++){
            int s;
            cin>>s;
            dfs(s);
        }

        int ck=0;
        for(int i=1;i<=n;i++){
            if(visit[i]==1)
                ck++;
        }
        cout<<ck<<endl;

        for(int i=0;i<M;i++){
            v[i].clear();
            visit[i]=0;
        }
    }
    return 0;
}
