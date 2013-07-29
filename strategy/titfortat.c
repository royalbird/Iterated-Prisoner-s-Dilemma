#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]){
	if(argc==1){
		printf("c");
		return 0;
	}
	if(argc==2){
		int i;
		int n = strlen(argv[1]);
		if(argv[1][n-1]=='K'||argv[1][n-1]=='S') printf("c");
		else printf("t");
		return 0;
	}
	return 0;
}
