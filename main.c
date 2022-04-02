#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "function.h"
int main(){
	file f = init_file();
	int n;
	printf("Donner le nombre des process : ");
	scanf("%d",&n);
	create_file(f,n);
	diagramme_Gant(f,n);
	return 0;
}
