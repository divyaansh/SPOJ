#include<stdio.h>
int main(){
    int t,n,i,c,a,b;
    scanf("%d",&t);
    while(t--!=0){
        scanf("%ld",&n);
        i=2,c=1;
        while(i<=n){
            a=n,b=i;
            while(a!=b&&b!=0){
                int te=b;
                b=a%b;
                a=te;
            }
            if(a==1)c++;
            i++;
        }
        printf("%ld\n",c);
    }
    return 0;
}