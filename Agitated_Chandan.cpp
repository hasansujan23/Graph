#include<bits/stdc++.h>
using namespace std;
#define M 100005
vector<long long>v[M],cost[M];
queue<long long>q;
long long visit[M];
long long dist[M];

long long sNode(long long s){
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    q.push(s);
    visit[s]=1;
    dist[s]=0;
    long long mx=0;
    long long temp=0;
    while(!q.empty()){
        long long u=q.front();
        q.pop();

        for(long long i=0;i<v[u].size();i++){
            long long p=v[u][i];
            if(visit[p]==0){
                visit[p]=1;
                dist[p]=dist[u]+cost[u][i];
                if(dist[p]>mx){
                    mx=dist[p];
                    temp=p;
                }
                q.push(p);
            }
        }

    }
    return temp;
}

long long sAvg(long long s){
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    q.push(s);
    visit[s]=1;
    dist[s]=0;
    long long mx=0;
    long long temp=0;
    while(!q.empty()){
        long long u=q.front();
        q.pop();

        for(long long i=0;i<v[u].size();i++){
            long long p=v[u][i];
            if(visit[p]==0){
                visit[p]=1;
                dist[p]=dist[u]+cost[u][i];
                if(dist[p]>mx){
                    mx=dist[p];
                }
                q.push(p);
            }
        }

    }
    return mx;
}


int main()
{
    long long q,mn=99999;
    cin>>q;
    for(long long i=0;i<q;i++){
        long long n;
        cin>>n;
        for(long long i=0;i<n-1;i++){
            long long x,y,z;
            cin>>x>>y>>z;
            v[x].push_back(y);
            v[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
            mn=min(mn,x);
            mn=min(mn,y);
        }

        long long sorce=sNode(mn);
        //cout<<sorce<<endl;
        memset(dist,0,sizeof(dist));
        long long avg=sAvg(sorce);
        //cout<<avg<<endl;
        long long cos=0;
        if(avg<100)
            cos=0;
        else if(avg>=100 && avg<1000)
            cos=100;
        else if(avg>=1000 && avg<10000)
            cos=1000;
        else
            cos=10000;
        cout<<cos<<" "<<avg<<endl;
        for(long long i=0;i<M;i++){
            v[i].clear();
            cost[i].clear();
        }
        mn=99999;
    }



    return 0;
}
