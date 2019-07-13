#include<bits/stdc++.h>
using namespace std;
#define M 1010

vector<int>v[M];
vector<int>loc;
int visit[M];
int temp[M];

void initiat(int a[],int val){
    for(int i=0;i<M;i++){
        a[i]=val;
    }
}

void dfs(int s){
    if(visit[s]==1)
        return;
    visit[s]=1;

    for(int i=0;i<v[s].size();i++){
        dfs(v[s][i]);
    }
}

void journey(int s){
    if(temp[s]==1)
        return;
    temp[s]=1;

    for(int i=0;i<v[s].size();i++){
        journey(v[s][i]);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int a=0;a<t;a++){
        int k,n,m;
        cin>>k>>n>>m;

        for(int i=0;i<k;i++){
            int pos;
            cin>>pos;
            loc.push_back(pos);
        }

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }

        initiat(visit,0);
        dfs(loc[0]);

        for(int i=1;i<loc.size();i++){
            initiat(temp,0);
            journey(loc[i]);

            for(int j=1;j<=n;j++){
                visit[j]=(visit[j] & temp[j]);
            }
        }

        int ck=0;
        for(int i=1;i<=n;i++){
            if(visit[i]==1)
                ck++;
        }

        cout<<"Case "<<a+1<<": "<<ck<<endl;
        loc.clear();
        for(int i=0;i<M;i++){
            v[i].clear();
        }
    }
    return 0;
}
