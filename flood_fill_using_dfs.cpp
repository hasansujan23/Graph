#include<bits/stdc++.h>
using namespace std;
#define M 100

char cell[M][M];
int visit[M][M];
int row=0,col=0;
int fx[]={1,-1,0,0,1,-1,1,-1};
int fy[]={0,0,1,-1,1,1,-1,-1};

bool valid(int x,int y){
    if(x>=0 && x<row && y>=0 && y<col && cell[x][y]=='.'){
        return true;
    }
    return false;
}

//void dfs(int sx,int sy){
//    if(sx<0 || sx>=row || sy<0 || sy>=col)
//        return;
//
//    if(cell[sx][sy]=='.' && visit[sx][sy]==0){
//        visit[sx][sy]=1;
//            for(int i=0;i<8;i++){
//            int tx=sx+fx[i];
//            int ty=sy+fy[i];
//            dfs(tx,ty);
//        }
//    }
//}

void dfs(int sx,int sy){
    if(sx<0 || sx>=row || sy<0 || sy>=col)
        return;

    if(visit[sx][sy]==1)
        return;

    visit[sx][sy]=1;
    cell[sx][sy]='+';

    for(int i=0;i<8;i++){
            int tx=sx+fx[i];
            int ty=sy+fy[i];
            if(valid(tx,ty)){
                cell[tx][ty]='+';
                dfs(tx,ty);
            }
    }
}

int main()
{
    int r,c;
    cin>>r>>c;
    row=r;col=c;
    cin.ignore();
    for(int i=0;i<r;i++){
        string s;
        //cin>>s;
        getline(cin,s);
        //cin.ignore();
        for(int j=0;j<c;j++){
            cell[i][j]=s[j];
        }
    }

    cout<<"Output:-"<<endl;

    int ck=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(cell[i][j]=='.' && visit[i][j]==0){
                dfs(i,j);
                ck++;
            }
        }
    }

    cout<<ck<<endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<cell[i][j];
        }
        cout<<endl;
    }

    return 0;
}
