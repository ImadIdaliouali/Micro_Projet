#include "struct.h"
process* create_process(process p){
	process* p1 = (process*)malloc(sizeof(process));
	p1->id = p.id;
	p1->r_time = p.r_time;
	p1->a_time = p.a_time;
	p1->priority = p.priority;
	p1->next = NULL;
	return p1;
}
file init_file(){
	file f = (file)malloc(sizeof(File));
	f->head = NULL;
	f->tail = NULL;
	return f;
}
process* pop_process(file f){
	if(f->tail == NULL)
		exit(1);
	else{
		process* pop_process = f->head;
		f->head = f->head->next;
		f->size--;
		return pop_process;
	}
}
process* read_process(file f){
	return f->head;
}
process* search_before_end(file f){
	process* tmp = f->head;
	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}
	return tmp;
}
void push_FIFO(file f,process* p){
	if(f->tail == NULL)
		f->head = f->tail = p;
	else{
		if(f->tail->r_time > p->a_time){// hadi hiya li ktbdl temp d'arrive
			p->att_time = f->tail->a_time + f->tail->r_time - p->a_time;
			p->a_time = f->tail->a_time + f->tail->r_time;
		}
		if(f->tail->a_time < p->a_time){
			f->tail->next = p;
			f->tail = p;
		}
		else{
			process* before_end = search_before_end(f);
			before_end->next = p;
			p->next = f->tail;
		}
	}
	f->size++;
}
// void push_SJF(file f,process* p){
// 	if(f->tail == NULL)
// 		f->head = f->tail = p;
// 	else{
// 		if(f->tail->r_time > p->a_time){// hadi hiya li ktbdl temp d'arrive
// 			p->a_time = f->tail->a_time+f->tail->r_time;
// 		}
// 		if(f->tail->a_time < p->a_time){
// 			f->tail->next = p;
// 			f->tail = p;
// 		}
// 		else if(f->tail->a_time == p->a_time){
// 			if(f->tail->r_time > p->r_time){
// 				process* before_end = search_before_end(f);
// 				before_end->next = p;
// 				p->next = f->tail;
// 			}
// 			else{
// 				f->tail->next = p;
// 				f->tail = p;
// 			}
// 		}
// 		else{
// 			process* before_end = search_before_end(f);
// 			before_end->next = p;
// 			p->next = f->tail;
// 		}
// 	}
// 	(f->size)++;
// }
// void push_SRFT(file f,process* p){
// 	if(f->tail == NULL)
// 		f->head = f->tail = p;
// 	else{

// 	}
// 	f->size++;
// }
// void push_tourniquet(file f,process* p){
// 	if(f->tail == NULL)
// 		f->head = f->tail = p;
// 	else{

// 	}
// 	f->size++;
// }
void create_file(file f){
	process p;
	process* p1 = NULL;
	int n;
	printf("Donner le nombre des process : ");
	scanf("%d",&n);
	int choice;
	t:
	printf("Choose an push : \n");
	printf("1) Push FIFO\n");
	printf("2) Push SJF\n");
	printf("3) Push SRTF\n");
	printf("4) Push Tourniquet\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Execute push FIFO function\n");
			break;
		// case 2:
		// 	printf("Execute push SJF function\n");
		// 	break;
		// case 3:
		// 	printf("Execute push SRTF function\n");
		// 	break;
		// case 4:
		// 	printf("Execute push Tourniquet function\n");
		// 	break;
		default:
			printf("Invalid choice\n");
			goto t;
	}
	for(int i=1;i<=n;i++){
		p.id = i;
		printf("Donner a_time de P%d : ",i);
		scanf("%d",&p.a_time);
		printf("Donner r_time de P%d : ",i);
		scanf("%d",&p.r_time);
		printf("Donner priority de P%d : ",i);
		scanf("%d",&p.priority);
		p1 = create_process(p);
		switch(choice){
			case 1:
				push_FIFO(f,p1);
				break;
			// case 2:
			// 	push_SJF(f,p1);
			// 	break;
			// case 3:
			// 	push_SRTF(f,p1);
			// 	break;
			// case 4:
			// 	push_tourniquet(f,p);
			// 	break;
		}
	}
}
void diagramme_Gant(file f){
	int i = 0;
	printf("process :");
	for(i=0;i<(f->size);i++){
		printf(" %d",i);
	}
	printf("\n");
	process* p = NULL;
	while(f->tail != NULL){
		while(i < f->head->r_time){
			printf("%d       :",i);
			for(int j=0;j < 5-(f->size);j++){
				printf("  ");
			}
			printf(" o");
			if(f->head->next->att_time >= i)
				printf(" x");
			printf("\n");
			i++;
		}
		p = pop_process(f);
	}
}
