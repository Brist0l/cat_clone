#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
	char c;
	int word_count = 0;

	FILE *input = fopen(argv[1],"r");
	
	while((c = fgetc(input)) != EOF){
		printf("%c",c);
		word_count++;
	}


	printf("\nwords = %d\n",word_count - 1);
}
