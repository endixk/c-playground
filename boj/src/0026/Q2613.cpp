#include <ios>
#define f(i,n) for(int i=0;i<n;i++)
int N,M,K=1,A[301];
bool S[301];
bool split(int k,bool p){
    int c=1,s=0;
    f(i,N){
        if(A[i]>k)return 0;
        if(s+A[i]>k){
            if(p){S[i-1]=1;K++;}
            if(++c>M)return 0;
            s=A[i];
        }
        else s+=A[i];
    }
    return 1;
}
int main(){
    scanf("%d %d",&N,&M);
    f(i,N)scanf("%d",&A[i]);
    int l=0,r=3e4;
    while(l<r){
        int m=(l+r)/2;
        if(split(m,0))r=m;
        else l=m+1;
    }
    split(l,1);
    f(i,N){if(!S[i]&&K<M){S[i]=1;K++;}}
    printf("%d\n",l);
    int b=0;
    f(i,N){if(S[i]){printf("%d ",i-b+1); b=i+1;}}
    printf("%d\n", N-b);
}