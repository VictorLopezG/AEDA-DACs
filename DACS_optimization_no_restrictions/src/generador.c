#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char* argv[]){
	if(argc>1){
		int n = atoi(argv[1]);
		srand(time(NULL));
		int x;
		for(int i=0;i<n;i++){
			x = rand()%INT_MAX;
			printf("%d\n",x);
		}
	}
}