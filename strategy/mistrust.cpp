#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
has the same behavior as tit-for-tat but defects on the first move.
*/

int main(int argc,char *argv[]){
	if(argc == 1){
		printf("t\n");
		return 0;
	}
	if(argv[1][0] && (argv[1][0]=='R' || argv[1][0]=='E') )
		printf("t\n");
	else
		printf("c\n");
return 0;
}
