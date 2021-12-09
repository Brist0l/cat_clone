#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[]){
	char c;
	int word_count = 0;
	int new_lines = 0;

	for(int i = 1;i < argc ; i++){

		FILE *input = fopen(argv[i],"r");


		while((c = fgetc(input)) != EOF){
			printf("%c",c);
			
			word_count++;
			
			if(c == '\n')
				new_lines ++;
		}
	}

	printf("\nwords = %d\n",word_count - 1 - (new_lines - 1 ));
}
