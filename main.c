#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sm2.h"


extern int sm2_test();

int main(){

	printf("begin sm2 test...\n");
	
	sm2_test();

	printf("\n``````````````````this is end```````````````````````\n");
	return 0;
}