#include <stdio.h>

int main() {
	int num = 0;
	scanf("%d", &num);
	if (0 < num && num < 10000) {
		for (int i=1; i<=num; i++){
			if (i%3==0 && i%5==0) printf("tiktak");
			else if (i%3 == 0) printf("tik");
			else if (i%5 == 0) printf("tak");
			else printf("%d", i);
			printf("\n");
		}
	}
	else printf("%d\n",-1);
	return 0;
}
