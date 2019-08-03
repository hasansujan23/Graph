#include<bits/stdc++.h>
using namespace std;
#define M 100010

long long node[M];
long long dist[M];
vector<long long>v[M];
vector<long long>cost[M];

struct pr{
    long long x,y;
    pr(long long _x,long long _y){
        x=_x;
        y=_y;
    }
    pr(){}
};

bool operator < (pr a,pr b){
    return a.y>b.y;
}

void dijkstra(long long s,long long n,long long k,long long f){
    for(long long i=0;i<M;i++){
        dist[i]=99999999999999;
    }

    dist[s]=0;

    priority_queue<pr>pq;

    pq.push(pr(s,dist[s]));

    while(!pq.empty()){
        pr top=pq.top();
        pq.pop();

        long long u=top.x;

        for(long long i=0;i<v[u].size();i++){
            long long p=v[u][i];

            if((dist[u]+cost[u][i])<dist[p]){
                dist[p]=dist[u]+cost[u][i];
                pq.push(pr(p,dist[p]));
            }
        }
    }

    for(long long i=1;i<=n;i++){
        pq.push(pr(node[i],dist[i]));
    }

    vector<long long>park;
    long long ck=0;

    while(!pq.empty()){
        pr top=pq.top();
        pq.pop();

        if(ck==k)
            break;

        if(top.x>=1){
            ck++;
            park.push_back(f+top.y);
            pq.push(pr(top.x-1,top.y));
        }
    }

    for(long long i=ck;i<k;i++){
        park.push_back(-1);
    }

    for(long long i=0;i<park.size();i++){
        cout<<park[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    long long n,m,f;
    cin>>n>>m>>f;
    for(long long i=1;i<=n;i++){
        cin>>node[i];
    }

    for(long long i=0;i<m;i++){
        long long x,y,c;
        cin>>x>>y>>c;

        v[x].push_back(y);
        v[y].push_back(x);
        cost[x].push_back(c);
        cost[y].push_back(c);
    }

    long long k;
    cin>>k;

    dijkstra(1,n,k,f);

    return 0;
}
