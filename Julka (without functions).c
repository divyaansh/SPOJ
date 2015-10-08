#include<stdio.h>
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
        
        int temp,c=0,f=m[ml-1]==1?ml-1:ml;
        while(ml!=0){
            temp=(c*10+m[--ml]-48)/2;
            c=m[ml]%2;
            m[ml]=temp+48;
        }
        ml=f;
        
        c=0;
        f=p[pl-1]==1?pl-1:pl;
        while(pl!=0){
            temp=(c*10+p[--pl]-48)/2;
            c=p[pl]%2;
            p[pl]=temp+48;
        }
        pl=f;
        
        int z=0;
        while(ml!=0){
            if(m[--ml]!='0') z=1;
            if(z||ml==0) printf("%c",m[ml]);
        }
        if(u) printf(".5");
        printf("\n");
        
        z=0;
        if(r) printf("-");
        while(pl!=0){
            if(p[--pl]!='0') z=1;
            if(z||pl==0) printf("%c",p[pl]);
        }
        if(u) printf(".5");
        printf("\n");
    }
    return 0;
}