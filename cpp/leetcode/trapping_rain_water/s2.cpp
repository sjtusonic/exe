#include <stdio.h>
#include <stdlib.h>
void gen(int numbers)
{
	int temp;
	int a[numbers], upto = numbers+1, temp2;
	for( temp2 = 1 ; temp2 <= numbers; temp2++){
		a[temp2]=1;
	}
	a[numbers]=0;
	temp=numbers;
	while(1){
		if(a[temp]==upto-1){
			temp--;
			if(temp==0)
				break;
		}
		else{
			a[temp]++;
			while(temp<numbers){
				temp++;
				a[temp]=1;
			}
 
			printf("(");
			for( temp2 = 1 ; temp2 <= numbers; temp2++){
				printf("%d", a[temp2]-1);
			}
			printf(")\n");
		}
	}
}
 
int main(){	
	gen(1);
	return 0;
}
