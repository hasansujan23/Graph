#include<bits/stdc++.h>
using namespace std;
#define M 1010

int cell[M][M];
int dist[M][M];

int fx[]={-2,-2,2,2,-1,-1,1,1};
int fy[]={-1,1,-1,1,-2,2,-2,2};

int row=1001,col=1001;

struct pr{
    int x,y;
    pr(int _x,int _y){
        x=_x;
        y=_y;
    }
};

void init(){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            dist[i][j]=INT_MAX;
        }
    }
}

bool valid(int x,int y){
    if(x>0 && x<row && y>0 && y<col){
        return true;
    }
    return false;
}

void bfs(int sx,int sy){
    dist[sx][sy]=0;

    queue<pr>q;

    q.push(pr(sx,sy));

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        for(int i=0;i<8;i++){
            int tx=top.x+fx[i];
            int ty=top.y+fy[i];

            if(valid(tx,ty) && dist[top.x][top.y]+1<dist[tx][ty]){
                dist[tx][ty]=dist[top.x][top.y]+1;
                q.push(pr(tx,ty));
            }
        }
    }
}

int main()
{
    init();
    bfs(1,1);
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",dist[x][y]);
    }

    return 0;
}
