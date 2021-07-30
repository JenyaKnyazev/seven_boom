#include <stdio.h>

void seven_boom_rec(int max,int stop,int sum,int *boom){
	int i,mul;
	if(*boom)
		printf("Boom\n");
	else
		printf("%d\n",sum);
	for(mul=1;mul<max&&mul<stop;mul*=10,sum-=sum%(mul*10)){
		for(i=1;i<=9&&sum+mul*i<=max;i++){
				if(i==7&&*boom==0){
					*boom=1;
					seven_boom_rec(max,mul,sum+i*mul,boom);
					*boom=0;
				}else
					seven_boom_rec(max,mul,sum+i*mul,boom);
		}
	}
}	
void seven_boom(){
	int boom=0;
	int max;
	printf("Enter max number\n");
	scanf("%d",&max);
	seven_boom_rec(max,max*10,0,&boom);
}
void main(){
	seven_boom();
}
