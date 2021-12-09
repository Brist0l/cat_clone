#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int clear_buffer(char *flag, int *argc,int *last_arg);

int main(int argc,char *argv[]){
	char c;
	unsigned int word_count = 0;
	unsigned int new_lines = 0;
	unsigned int num_of_letters = 0;
	int last_arg = argc - 1;
	char *last_arg_val;

	const char *cmd = "clear";

	last_arg_val = argv[last_arg];
	int use = clear_buffer(last_arg_val,&argc,&last_arg);

	
	for(int i = 1;i < argc ; i++){				
		if(use == 0){
			system(cmd);
		}

		FILE *input = fopen(argv[i],"r");
			

		while((c = fgetc(input)) != EOF){
			printf("%c",c);
			
			word_count++;
			
			if(c == '\n')
				new_lines ++;
		}
	}
	
	num_of_letters = word_count - 1 - (new_lines-1);
	
	printf("\nletters = %d\n",num_of_letters);
}

int clear_buffer(char *flag, int *argc,int *last_arg){
	if(strcmp(flag,"-c") == 0){
		*argc = *last_arg;
		return 0;
	}
	return 1;

}
