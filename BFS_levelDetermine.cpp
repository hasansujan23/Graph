#include<bits/stdc++.h>
using namespace std;
#define M 100001
vector<int>v[M];
queue<int>q;
int visit[M];
int level[M];
int ck[M];

void bfsLevel(int s){
    q.push(s);
    visit[s]=1;
    level[s]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];
            if(visit[p]==0){
                level[p]=level[u]+1;
                q.push(p);
                visit[p]=1;
            }
        }
    }
}

int main()
{
    int e;
    cin>>e;
    for(int i=0;i<e-1;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int s=1;
    //cout<<"source:"<<endl;
    //cin>>s;
    bfsLevel(s);
    int f;
    cin>>f;

    for(int i=0;i<M;i++){
        if(level[i]>0)
            ck[level[i]]++;
    }

    //for(int i=0;i<M;i++)
        //cout<<i<<" "<<level[i]<<endl;;
    //cout<<endl;
    if((f-1)==0){
        cout<<1<<endl;
    }else{
        cout<<ck[f-1]<<endl;
    }


    return 0;
}
