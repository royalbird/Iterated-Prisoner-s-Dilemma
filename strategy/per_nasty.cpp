#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
Agent plays periodically [defect, defect, cooperate]
*/

int main(int argc,char *argv[]){
	if(argc == 1){
		printf("t\n");
		return 0;
	}
	int mod = (strlen( argv[1] ) + 1) % 3;
	if(mod == 0)
		printf("c\n");
	else
		printf("t\n");
return 0;
}
