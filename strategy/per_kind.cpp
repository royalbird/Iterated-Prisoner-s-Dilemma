#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
Agent plays periodically [cooperate, cooperate, defect]. 
*/

int main(int argc,char *argv[]){
	if(argc == 1){
		printf("c\n");
		return 0;
	}
	int mod = (strlen( argv[1] ) + 1) % 3;
	if(mod == 0)
		printf("t\n");
	else
		printf("c\n");
return 0;
}
