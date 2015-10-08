#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t-->0){
        int M[1000],W[1000],N[1000];n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",M[i]);
        for(i=0;i<n;i++) scanf("%d",W[i]);
        int s=max(M,W,N,n,0);
    }
    return 0;
}

int max(int M[],int W[],int N[],int n,int i){
    for(j=0;j<n;j++){
        if(N[j]!=-1){
            s+=
            N[j]=-1;
            s+=max(M,W,N,n,i);
            break;
        
        }
    }
}