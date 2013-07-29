#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	srandom(time(0)+getpid());
	int v = random()%2;
	int output = 't'*v + (1-v)*'c';
	printf("%c",output);
	return 0;
}
