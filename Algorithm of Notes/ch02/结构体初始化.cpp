#include<stdio.h>
struct studentInfo{
	int id;
	char gender;
	// Ĭ�Ϲ��캯�������ڳ�ʼ�� 
	studentInfo(){}
	// ����һ��ֵ�ĳ�ʼ�� 
	studentInfo(int _id){
		id=_id;
	}
	// ��������ֵ�ĳ�ʼ�� 
	studentInfo(int _id,char _gender){
		id=_id;
		gender=_gender;
	}
	// �������߿�ͬʱ����
	// �򻯹��캯��д�� 
	// studentInfo(int _id��char _gender): id(_id),gender(_gender) {}
} stu[10];
int main(){
	int num=0;
	for(int i=0;i<3;i++){
		for(char j='a';j<'z';j++){
			stu[num++]=studentInfo(i,j);
		}
	}
	for(int i=0;i<num;i++){
		printf("%d %c\n",stu[i].id,stu[i].gender);
	}
}
