#include<stdio.h>

int div2(char[],int);
int printRev(char[],int,int,int);

int main(){
    int i,kl,nl,ml,pl,s,d,u,r,j;
    char k[102],n[102],m[102],p[102];
    for(i=1;i<=10;i++){
        scanf("%s",k);
        scanf("%s",n);
        for(kl=0;k[kl]!='\0';kl++);
        for(nl=0;n[nl]!='\0';nl++);
        ml=pl=s=d=u=r=0;
        if(((k[kl-1]+n[nl-1]))%2) u=1;
        if(nl>kl) r=1;
        else if(nl==kl){
            j=0;
            while(j<nl){
                if(n[j]>k[j]){
                    r=1;
                    break;
                }
                j++;
            }
        }
        
        
        while(kl!=0&&nl!=0){
            s=(int)k[--kl]+(int)n[--nl]-96+s/10;
            m[ml++]=(char)(s%10+48);
            if(!r){
                d=(int)k[kl]-(int)n[nl]+(d<0?-1:0);  
            }
            else{
                d=(int)n[nl]-(int)k[kl]+(d<0?-1:0);  
            }
            p[pl++]=(char)((d<0?10+d:d)+48);
        }
        
        if(kl==0&&s/10!=0) m[ml++]=(char)(s/10+48);
        
        while(kl!=0){
            s=(int)k[--kl]-48+s/10;
            m[ml++]=(char)(s%10+48);
            d=(int)k[kl]-48+(d<0?-1:0);
            p[pl++]=(char)((d<0?10+d:d)+48);    
        }
        while(nl!=0){
            s=(int)n[--nl]-48+s/10;
            m[ml++]=(char)(s%10+48);
            d=(int)n[nl]-48+(d<0?-1:0);
            p[pl++]=(char)((d<0?10+d:d)+48);    
        }
        
        ml=div2(m,ml);
        pl=div2(p,pl);
        
        printRev(m,ml,u,0);
        printRev(p,pl,u,r); 
    }
    return 0;
}

int div2(char a[],int l){
    int temp,c=0,f=a[l-1]==1?l-1:l;
    while(l!=0){
        temp=(c*10+a[--l]-48)/2;
        c=a[l]%2;
        a[l]=temp+48;
    }
    return f;
}

int printRev(char a[],int l,int u,int r){
    int z=0;
    if (r) printf("-");
    while(l!=0){
        if(a[--l]!='0') z=1;
        if(z||l==0) printf("%c",a[l]);
    }
    if(u) printf(".5");
    printf("\n");
    return 0;
}

/*
9000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
900000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999 

10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998 

2 2
1 1
2 1
3 1
8 5
9 5
10 3
*/