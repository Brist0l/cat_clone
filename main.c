#include<stdio.h>

int main(int argc,char *argv[]){
	char c;
	int word_count = 0;

	for(int i = 1;i < argc ; i++){

		FILE *input = fopen(argv[i],"r");


		while((c = fgetc(input)) != EOF){
			printf("%c",c);
			word_count++;
	}
	}

	printf("\nwords = %d\n",word_count - 1);
}
