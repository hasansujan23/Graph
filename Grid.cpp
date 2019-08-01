#include<bits/stdc++.h>
using namespace std;
#define M 1010


int visit[M][M];
int cell[M][M];
int dist[M][M];
int row=0,col=0;

int fx[]={-1,1,0,0};
int fy[]={0,0,-1,1};


struct pr{
    int x,y;
    pr(int _x,int _y){
        x=_x;
        y=_y;
    }
    pr(){}
};

bool valid(int x,int y){
    if(x>=0 && x<row && y>=0 && y<col && cell[x][y]==0){
        return true;
    }
    return false;
}


void bfs(int sx,int sy){

    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            dist[i][j]=INT_MAX;
        }
    }

    visit[sx][sy]=1;
    dist[sx][sy]=0;

    queue<pr>q;

    q.push(pr(sx,sy));

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int tx=top.x+fx[i];
            int ty=top.y+fy[i];

            if(valid(tx,ty) && (dist[top.x][top.y]+1)<dist[tx][ty]){
                dist[tx][ty]=dist[top.x][top.y]+1;
                visit[tx][ty]=1;
                q.push(pr(tx,ty));
            }
        }
    }
}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    row=n;col=m;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        for(int j=0;j<m;j++){
            if(s[j]=='0')
                cell[i][j]=0;
            if(s[j]=='*')
                cell[i][j]=1;
        }
    }

    int sx,sy;
    cin>>sx>>sy;
    bfs(sx-1,sy-1);

//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cout<<dist[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    for(int i=0;i<q;i++){
        int dx,dy;
        cin>>dx>>dy;

        if(visit[dx-1][dy-1]==1){
            cout<<dist[dx-1][dy-1]<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }

    return 0;
}
