#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

char ** parse_args( char * line ) {
	int cnt = 1;
	char *copy = line;
	while (*copy) {
		if (*copy==' ') *copy='\0', cnt++;
		copy++;
	}
	printf("%d\n", cnt);
	char **ans = malloc(cnt * sizeof(char*)+1);
	ans[cnt]=0;
	copy = line;
	for (int i = 0; i < cnt; i++) {
		ans[i] = copy;
		copy += strlen(copy)+1;
	}
	return ans;
}

int main() {
	char c[100] = "ls -a -l";
	char **args = parse_args(c);
	execvp(args[0], args);
}
