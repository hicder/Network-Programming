#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	char *hostname =(char *) malloc(1000*sizeof(char));
	gethostname(hostname, sizeof hostname);
	printf("%s\n",hostname);
}
