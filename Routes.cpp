#include<bits/stdc++.h>
using namespace std;
#define M 100010

vector<int>v[M];
vector<int>cost[M];
vector<int>vt[M];
vector<int>vp;
int dist[M];
int tim[M];
int path[M];

struct pr{
    int x,y;
    pr(int _x,int _y){
        x=_x;
        y=_y;
    }
    pr(){}
};

bool operator < (pr a,pr b){
    return a.y>b.y;
}


bool dijkstra(int s,int d,int k){
    for(int i=0;i<M;i++){
        dist[i]=INT_MAX;
    }
    priority_queue<pr>pq;

    dist[s]=0;
    tim[s]=0;
    pq.push(pr(s,dist[s]));

    while(!pq.empty()){
        pr top=pq.top();
        pq.pop();
        int u=top.x;
        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];

            int tmp=0;
                if(path[u]!=0){
                    tmp=k;
                }

            if((dist[u]+(cost[u][i]+(vt[u][i]*k)+tmp))<dist[p]){
                dist[p]=dist[u]+(cost[u][i]+(vt[u][i]*k)+tmp);
                tim[p]=vt[u][i]+tim[u];
                path[p]=u;
                pq.push(pr(p,dist[p]));
            }

        }
    }

    if(dist[d]==INT_MAX)
        return false;

    vp.push_back(d);
    int now=d;
    while(now!=s){
        now=path[now];
        vp.push_back(now);
    }

    return true;
}


int main()
{
    int k;
    cin>>k;
    int n,x;
    cin>>n>>x;
    int tmp = min(x,(n*(n-1))/2);
    for(int i=0;i<x;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(tmp==x){
            v[a].push_back(b);
            v[b].push_back(a);
            cost[a].push_back(d);
            cost[b].push_back(d);
            vt[a].push_back(c);
            vt[b].push_back(c);
        }
    }

    int src,des;
    cin>>src>>des;

    if(dijkstra(src,des,k)){
        for(int i=vp.size()-1;i>=0;i--){
            cout<<vp[i];
            if(i>0)
                cout<<"->";
        }

        int t=tim[des]+(vp.size()-2);

        cout<<" "<<t<<" "<<dist[des]<<endl;
        //cout<<dist[4]<<endl;

    }else{
        cout<<"Error"<<endl;
    }

    return 0;
}

