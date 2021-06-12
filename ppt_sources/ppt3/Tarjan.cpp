#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define DBG 0

using namespace std;

int N,M,id[5010],dis[5010],p[5010],qry[500][2],lca[5010][5010];
vector<int>egs[5000],qeg[5000];
int find(int a){
    if(id[a]==a)return a;
    return id[a]=find(id[a]);
}
void merge(int c,int p){
    if(DBG)printf("merge %d to %d\n",c,p);
    id[find(c)]=find(p);
    if(DBG)printf("id[%d]=%d\n",c,id[find(c)]);
}
void tarjan(int c){
    if(DBG)printf("tarjan: %d\n",c);
    id[c]=c;
    rep(i,egs[c].size()){
        if(id[egs[c][i]]<0){
            dis[egs[c][i]]=dis[c]+1,p[egs[c][i]]=c;
            tarjan(egs[c][i]);
            merge(egs[c][i],c);}
    }
    rep(i,qeg[c].size()){
        if(id[qeg[c][i]]>=0)lca[qeg[c][i]][c]=lca[c][qeg[c][i]]=find(qeg[c][i]);
    }
}
void raise(int a,int d,int d2,int &x,int &y){
    rep(i,d/2+d2)a=p[a];
    x=a;
    if(d%2){y=p[a];if(x>y)swap(x,y);}
}
void getP(int i,int &x,int &y){
    int a=qry[i][0],b=qry[i][1],
    c=lca[a][b],
    d1=dis[a]-dis[c],d2=dis[b]-dis[c];
    if(DBG)printf("a b c d1 d2 %d %d %d %d %d\n",a,b,c,d1,d2);
    if(c==a)raise(b,(d2),0,x,y);
    else if(c==b)raise(a,(d1),0,x,y);
    else if(d1>d2)raise(a,d1-d2,d2,x,y);
    else if(d1<d2)raise(b,d2-d1,d1,x,y);
    else x=c;
}
void ans(){
    memset(dis,-1,sizeof(dis));
    memset(id,-1,sizeof(id));
    dis[1]=0;
    tarjan(1);
    if(DBG)rep(i,M)printf("lca %d %d: %d\n",qry[i][0],qry[i][1],lca[qry[i][0]][qry[i][1]]);
    int x,y;
    rep(i,M){
        x=-1,y=-1;
        getP(i,x,y);
        if(x>0&&y>0)printf("The fleas jump forever between %d and %d.\n",x,y);
        else printf("The fleas meet at %d.\n",x);
    }
}
int main(){
    int a,b,c,n,m;
    while(scanf("%d",&N)==1){
        if(!N)break;
        memset(dis,0,sizeof(dis));rep(i,500)qeg[i].clear();
        rep(i,5000)egs[i].clear();
        rep(i,N-1)scanf("%d%d",&a,&b),egs[a].push_back(b),egs[b].push_back(a);
        scanf("%d",&M);
        rep(i,M){
            scanf("%d%d",&qry[i][0],&qry[i][1]);
            qeg[qry[i][0]].push_back(qry[i][1]),
            qeg[qry[i][1]].push_back(qry[i][0]);
        }
        ans();
    }
}
