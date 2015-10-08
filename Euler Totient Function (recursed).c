#include<stdio.h>

int gcd(int,int);

int main(){
    int t;
    int n,i,c;
    scanf("%d",&t);
    while(t--!=0){
        scanf("%ld",&n);
        i=2,c=1;
        while(i<=n){
            if(gcd(n,i)==1)c++;
            i++;
        }
        printf("%ld\n",c);
    }
    return 0;
}

int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}