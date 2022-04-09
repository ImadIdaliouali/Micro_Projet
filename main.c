#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"
#include "functions.h"
/**
 * Author : Oussama Makouar, Imad Idali Ouali
 * Date : 05/04/2022
 * Language : C
 */
int main(){
	file f = init_file();
	int n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	create_file(f,n);
	display(f);
	Gantt_chart(f);
	return 0;
}
