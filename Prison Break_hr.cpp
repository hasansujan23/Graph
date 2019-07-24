#include<bits/stdc++.h>
using namespace std;
#define M 25

int cell[M][M];
int visit[M][M];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int numPath=0;
int row=0,col=0;

void clr(){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            visit[i][j]=0;
        }
    }
}

bool valid(int x,int y){
    if(x>=0 && x<row && y>=0 && y<col && cell[x][y]==0){
        return true;
    }
    return false;
}

void dfs(int sx,int sy){
    if(sx==row-1 && sy==col-1){
        numPath++;
        return;
    }
    visit[sx][sy]=1;

    for(int i=0;i<4;i++){
        int dx=sx+fx[i];
        int dy=sy+fy[i];

        if(valid(dx,dy) && visit[dx][dy]==0){

            dfs(dx,dy);
            visit[dx][dy]=0;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        row=n;col=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>cell[i][j];
            }
        }

        dfs(0,0);
        cout<<numPath<<endl;
        numPath=0;
        clr();
    }
    return 0;
}
