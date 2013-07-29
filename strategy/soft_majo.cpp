#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
Agent plays the opponent's most used move and cooperates in case of equality (first move considered as equality).
*/

int main(int argc,char *argv[]){
	if(argc == 1){
		printf("c\n");
		return 0;
	}
	size_t coop = 0;
	size_t betray = 0;
	int i;
	for(i = 0;argv[1][i];i++){
		if(argv[1][i]=='K' || argv[1][i]=='S')
			coop++;
		else
			betray++;
	}
	if(betray > coop)
		printf("t\n");
	else
		printf("c\n");
return 0;
}
