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
	if(f == NULL)
		exit(1);
	else{
		process* pop_process = f->head;
		f->head = f->head->next;
		f->size--;
	}
	return pop_process;
}
process* read_process(file f){
	return f->head;
}
process* search_before_end(file f){
	process* temp = f->head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	return temp;
}
void push_FIFO(file f,process* p){
	if(f->head == f->tail == NULL)
		f->head = f->tail = p;
	else{
		if(f->tail->r_time > p->a_time){// hadi hiya li ktbdl temp d'arrive
			p->a_time = f->tail->a_time+f->tail->r_time;
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
void push_SJF(file f,process* p){
	if(f == NULL)
		f->head = f->tail = p;
	else{
		if(f->tail->r_time > p->a_time){// hadi hiya li ktbdl temp d'arrive
			p->a_time = f->tail->a_time+f->tail->r_time;
		}
		if(f->tail->a_time < p->a_time){
			f->tail->next = p;
			f->tail = p;
		}
		else if(f->tail->a_time == p->a_time){
			if(f->tail->r_time > p->r_time){
				process* before_end = search_before_end(f);
				before_end->next = p;
				p->next = f->tail;
			}
			else{
				f->tail->next = p;
				f->tail = p;
			}
		}
		else{
			process* before_end = search_before_end(f);
			before_end->next = p;
			p->next = f->tail;
		}
	}
	f->size++;
}
void push_SRFT(file f,process* p){
	if(f == NULL)
		f->head = f->tail = p;
	else{

	}
	f->size++;
}
void push_tourniquet(file f,process* p){
	
}
void diagramme_Gant(file f){
	printf("process : 1 2 3 4 5");
	for(int i=0;i<f->tail->a_time+f->tail->r_time;i++){
		printf("%d       :",i);
		for(int j=1;j<=f->size;j++){
			if(i == f->head->a_time){
				printf(" o");
			}
			else
				printf(" x");
		}
		printf("\n");
	}
}