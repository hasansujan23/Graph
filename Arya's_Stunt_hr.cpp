#include<bits/stdc++.h>
using namespace std;
#define M 10010

vector<int>v[M];
vector<int>node;
vector<int>light;
int visit[M];
int cost[M];

void dfs(int s){
    if(visit[s]==1)
        return;
    visit[s]=1;

    for(int i=0;i<v[s].size();i++){
        dfs(v[s][i]);
    }
    node.push_back(s);
}

int maxKill(){
    int mx=0,mn=0;
    sort(node.begin(),node.end());
    for(int i=0;i<node.size();i++){
        if(mx<cost[node[i]]){
            mx=cost[node[i]];
            mn=node[i];
        }
    }

    light.push_back(mn);
    node.clear();

    return mx;
}

int main()
{
    int n,e,sum=0;
    cin>>n>>e;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
        sum+=cost[i];
    }

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    int kill=0;

    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            dfs(i);
            kill+=maxKill();
        }
    }

    cout<<kill<<" "<<abs(sum-kill)<<endl;
    sort(light.begin(),light.end());
    for(int i=0;i<light.size();i++){
        cout<<light[i];
        if(i<light.size()-1)
            cout<<" ";
    }
    cout<<endl;

    return 0;
}
