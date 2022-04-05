#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "functions.h"
int main(){
	file f = init_file();
	int n;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	create_file(f,n);
	display(f);
	diagramme_Gant(f,n);
	return 0;
}
