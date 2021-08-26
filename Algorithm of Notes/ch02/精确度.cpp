#include<stdio.h>
#include<math.h>
const double eps=1e-8;
#define Equ(a,b) (fabs((a)-(b))<(eps))
// (fabs(a-b)<(eps))也是可以的，都是建议是上面的写法
// 为了防止宏定义可能带来的错误 


#define More(a,b)	 	(((a)-(b))>(eps))		// >
#define Less(a,b)	 	(((a)-(b))<(-eps))		// <
#define MoreEqu(a,b)	(((a)-(b))>(-eps))		// >=
#define LessEqu(a,b) 	(((a)-(b))<(-eps))		// <=

int main(){
	double db=1.23;
	
	double db1=4*asin(sqrt(2.0)/2);
	double db2=3*asin(sqrt(3.0)/2);
	// 答案都是pi 
	if(Equ(db,1.23)){
		printf("true\n");
	}
	else printf("false\n");
	// 浮点数精度进行比较 
	if(Equ(db1,db2)){
		printf("true\n");
	}
	else printf("false\n");
	// 证明精度是10的-8次方是可行的 
	if(db1==db2){
		printf("true\n");
	}
	else printf("false\n");
	// 若是直接比较会出现不相等的情况 
	return 0;
}
