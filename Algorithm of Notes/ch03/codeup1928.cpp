#include<stdio.h>
//日期的差值 
int month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
// 判断是否为闰年 
bool isLeap(int year){
	return (year%4==0&&year%100!=0)||(year%400==0);
}
int main(){
	int time1,y1,m1,d1;
	int time2,y2,m2,d2;
	while(scanf("%d %d",&time1,&time2)!=EOF){
		if(time1>time2){
			int temp=time1;
			time1=time2;
			time2=temp;
		}
		y1=time1/10000,m1=time1%1000/100,d1=time1%100;
		y2=time2/10000,m2=time2%1000/100,d2=time2%100;
		//计算的时候要算上这一天 
		int ans=1;
		while(y1<y2||m1<m2||d1<d2){
			d1++;
			if(d1==month[m1][isLeap(y1)]+1){
			// 当天数加一之后，与这个月的天数是一样的时候，月数就要加一，天数变为1号				 
				m1++;
				d1=1;
			}
			if(m1==13){
			// 月数等于13时，年数加一，月数变为一月 
				y1++;
				m1=1;
			}
			ans++;
			// 不断计算遍历天数，直达不满足 y1<y2||m1<m2||d1<d2为止，即两者相等 
		}
		printf("%d\n",ans);
	}
	return 0;
}
