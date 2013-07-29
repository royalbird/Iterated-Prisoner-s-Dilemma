#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
	Spite is the strategy in which agent cooperates until the opponent defects, after which the agent starts defecting.
*/

int main(int argc,char *argv[]){
	int i;

	if(argc == 1){
		printf("c\n");	
		return 0;
	}
	for(i = 0;argv[1][i];i++){
		if(argv[1][i]=='R' || argv[1][i]=='E')
			break;
	}
	if(argv[1][i]){
		printf("t\n");
	}
	else
		printf("c\n");
return 0;
}
