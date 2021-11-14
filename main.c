#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

char ** parse_args( char * line ) {
	char **ans = malloc(6*sizeof(char*));
	ans[0] = 0;
	int index = 0;
	while (line) {
		ans[index] = strsep(&line, " ");
		ans[++index] = 0;
	}
	return ans;
}

int main() {
	char c[500];
	printf("Enter a command: ");
	fgets(c, 500, stdin);
	*strchr(c, '\n') = 0;
	char **args = parse_args(c);
	execvp(args[0], args);
}
