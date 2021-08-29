#include<cstdio>
int main(){
    int variety,number,i,flag;
    double all=0.0,max;
    if(scanf("%d%d",&variety,&number)){};
    int storage[variety],gross[variety];
    double price[variety];
    for(i=0;i<variety;i++){
        if(scanf("%d",&storage[i])){};
    }
    for(i=0;i<variety;i++){
        if(scanf("%d",&gross[i])){};
    }
    for(i=0;i<variety;i++){
        price[i]=gross[i]/double(storage[i]);
    }
    for(int j=0;j<=variety;j++){
        max=0.0;
        for(i=0;i<variety;i++){
            if(max<price[i]){
                max=price[i];
                flag=i;
            }
        }
        if(storage[flag]<number){
            all+=gross[flag];
            number-=storage[flag];
            price[flag]=0;
        }
        else{
            all+=number*price[flag];
            break;
        }
    }

    printf("%.2lf",all);
    return 0;
}

