#include<bits/stdc++.h>
using namespace std;
#define M 105

int node[M][M];
int dist[M][M];

void init(){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(i==j){
                dist[i][j]=0;
            }else{
                dist[i][j]=1000;
            }
        }
    }
}

void warsal(){
    for(int k=1;k<M;k++){
        for(int i=1;i<M;i++){
            for(int j=1;j<M;j++){
                if((dist[i][k]+dist[k][j])<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

double solve(){
    double ck=0,sum=0;

    for(int i=1;i<M;i++){
        for(int j=1;j<M;j++){
            if(dist[i][j]<1000 && dist[i][j]!=0){
                ck++;
                sum+=dist[i][j];

            }
            //cout<<dist[i][j]<<" ";
        }
        //cout<<endl;
    }

    return sum/ck;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t=1;
    while(1){
        init();
        int a,b;
        cin>>a>>b;
        if(a==0 && b==0)
            break;
        dist[a][b]=1;

        while(1){
            int c,d;
            cin>>c>>d;
            if(c==0 & d==0)
                break;
            dist[c][d]=1;
        }
        warsal();
        printf("Case %d: average length between pages = %0.3f clicks\n",t,solve());
        t++;

    }
    return 0;
}
