#include<bits/stdc++.h>
using namespace std;
#define M 205

int cell[M][M];
int dist[M][M];
int visit[M][M];
int row=0,col=0;

int fx[]={-1,1,0,0};
int fy[]={0,0,-1,1};

int ax[]={-1,1,0,0,-1,-1,1,1};
int ay[]={0,0,-1,1,1,-1,1,-1};

struct pr{
    int x,y;
    pr(int _x,int _y){
        x=_x;
        y=_y;
    }
    pr(){}
};

int dis(int x,int y,int x1,int y1){
    x=x-x1;
    y=y-y1;
    return (x*x)+(y*y);
}

bool valid(int x,int y){
    if(x>=0 && x<row && y>=0 && y<col && cell[x][y]==0){
        return true;
    }
    return false;
}

void init(int x,int y,int c){
    int x1=x-c;
    int y1=y-c;
    //int len=(2*c)-1;

    for(int i=x1;i<=x+c;i++){
        for(int j=y1;j<=y+c;j++){
            if(i>=0 && i<row && j>=0 && j<col){
                if((c*c)>=dis(i,j,x,y))
                    cell[i][j]=1;
            }
        }
    }
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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(1){
        int r,c;
        cin>>r>>c;
        if(r==0 && c==0)
            break;

        row=r;col=c;

        int n;
        cin>>n;

        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;

            cell[x-1][y-1]=1;
        }

        int m;
        cin>>m;

        for(int i=0;i<m;i++){
            int x,y,c;
            cin>>x>>y>>c;
            cell[x-1][y-1]=1;
            init(x-1,y-1,c);
        }


        bfs(0,0);
        if(visit[r-1][c-1]==0){
            cout<<"Impossible."<<endl;
        }
        else{
            cout<<dist[r-1][c-1]<<endl;
        }

        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                cell[i][j]=0;
                visit[i][j]=0;
                dist[i][j]=0;
            }
        }
    }
    return 0;
}
