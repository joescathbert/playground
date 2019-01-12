#include<stdio.h>
#include<conio.h>
using namespace std;
struct syntaxtable{
	char data_type[];
	char value[];
	char variable_name[];
};
main(){
	int no_s;
	char statements[100][100];
	char newstat[100][100][100];
	struct syntaxtable tab;
	printf("Enter the no of statments:\n");
	scanf("%d",&no_s);
	printf("Go on...\n");
	gets(statements[0]);
	for(int i=0;i<no_s;i++){
		gets(statements[i]);	
	} 
	for(int i=0;i<no_s;i++){
		int j = 0;
		while(statements[i][j]!='\0'){
			printf("%d",j);
			int k = 0;
			printf("%c\t",statements[i][j]);
			if(statements[i][j])
			/*while(statements[i][j]!=' '){
				printf("%d",k);
				newstat[i][j][k] = statements[i][j];
				k++;
			}*/
			j++;
		}
		printf("\n");
	}
	for(int i=0;i<no_s;i++){
		for(int j=0;j<10;j++){
			puts(newstat[i][j]);
		}
	}
}
