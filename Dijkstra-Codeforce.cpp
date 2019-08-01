#include<bits/stdc++.h>
using namespace std;

#define M 205010

long long dist[M];
long long visit[M];
long long path[M];
vector<long long>v[M];
vector<long long>cost[M];

struct pr{
    long long x,y;
    pr(long long _x,long long _y){
        x=_x;
        y=_y;
    }
    pr(){}

    bool operator < ( const pr& p ) const { return y > p.y; }
};



void dijkstra(long long s,long long n){


    for(long long i=0;i<M;i++){
        dist[i]=99999999999999;
        visit[i]=0;
    }

//    fill(dist,dist+M,long long_MAX);
//    fill(visit,visit+M,0);

    priority_queue<pr>pq;
    dist[s]=0;
    visit[s]=1;

    pq.push(pr(s,dist[s]));

    while(!pq.empty()){
        pr top= pq.top();
        pq.pop();

        long long u=top.x;

        for(long long i=0;i<v[u].size();i++){
            long long p=v[u][i];

            if((dist[u]+cost[u][i])<dist[p]){
                dist[p]=dist[u]+cost[u][i];
                pq.push(pr(p,dist[p]));
                visit[p]=1;
                path[p]=u;
            }

        }
    }

    if(visit[n]==0){
        cout<<"-1"<<endl;
    }
    else{
       vector<long long>pt;

       pt.push_back(n);
       long long now=n;
       while(now!=s){
            now=path[now];
            pt.push_back(now);
       }


       for(long long i=pt.size()-1;i>=0;i--){
            cout<<pt[i];
            if(i>0)
                cout<<" ";
       }
       cout<<endl;
    }

}


int main()
{
        long long n,m;
        cin>>n>>m;

        for(long long i=0;i<m;i++){
            long long x,y,c;
            cin>>x>>y>>c;

            v[x].push_back(y);
            v[y].push_back(x);
            cost[x].push_back(c);
            cost[y].push_back(c);
        }

        dijkstra(1,n);
    return 0;
}
