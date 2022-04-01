#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "function.h"
int main(){
	file f = init_file();
	create_file(f);
	diagramme_Gant(f);
	return 0;
}
