#include<stdio.h>
#include<math.h>
const double eps=1e-8;
#define Equ(a,b) (fabs((a)-(b))<(eps))
// (fabs(a-b)<(eps))Ҳ�ǿ��Եģ����ǽ����������д��
// Ϊ�˷�ֹ�궨����ܴ����Ĵ��� 


#define More(a,b)	 	(((a)-(b))>(eps))		// >
#define Less(a,b)	 	(((a)-(b))<(-eps))		// <
#define MoreEqu(a,b)	(((a)-(b))>(-eps))		// >=
#define LessEqu(a,b) 	(((a)-(b))<(-eps))		// <=

int main(){
	double db=1.23;
	
	double db1=4*asin(sqrt(2.0)/2);
	double db2=3*asin(sqrt(3.0)/2);
	// �𰸶���pi 
	if(Equ(db,1.23)){
		printf("true\n");
	}
	else printf("false\n");
	// ���������Ƚ��бȽ� 
	if(Equ(db1,db2)){
		printf("true\n");
	}
	else printf("false\n");
	// ֤��������10��-8�η��ǿ��е� 
	if(db1==db2){
		printf("true\n");
	}
	else printf("false\n");
	// ����ֱ�ӱȽϻ���ֲ���ȵ���� 
	return 0;
}
