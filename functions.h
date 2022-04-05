process* create_process(process p){
	process *p1 = (process *)malloc(sizeof(process));
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
		exit(0);
	else{
		process *pop_process = f->head;
		f->head = f->head->next;
		if(f->head == NULL)
			f->tail = NULL;
		f->size--;
		return pop_process;
	}
}
process* read_process(file f){
	if(f->head == NULL)
		exit(0);
	else
		return f->head;
}
void push_FIFO(file f, process *p){
	if(f->tail == NULL)
		f->head = f->tail = p;
	else{
		if(f->tail->a_time + f->tail->r_time > p->a_time){ // hadi hiya li ktbdl temp d'arrive
			p->wait_time = f->tail->a_time + f->tail->r_time - p->a_time;
			p->a_time = f->tail->a_time + f->tail->r_time;
		}
		if(f->tail->a_time < p->a_time){
			f->tail->next = p;
			f->tail = p;
		}
		else{
			process *before_end = f->head;
			while(before_end->next->next != NULL){
				before_end = before_end->next;
			}
			before_end->next = p;
			p->next = f->tail;
		}
	}
	f->size++;
}
void push_SJF(file f, process *p){
	if(f->tail == NULL)
		f->head = f->tail = p;
	else{

	}
	f->size++;
}
void push_SRTF(file f,process* p){
	if(f->tail == NULL)
		f->head = f->tail = p;
	else{

	}
	f->size++;
}
void push_tourniquet(file f,process* p){
	if(f->tail == NULL)
		f->head = f->tail = p;
	else{

	}
	f->size++;
}
void create_file(file f, int n){
	process p;
	process *p1 = NULL;
	int choice;
	t:
	printf("Choose an push : \n");
	printf("1) Push FIFO\n");
	printf("2) Push SJF\n");
	printf("3) Push SRTF\n");
	printf("4) Push Tourniquet\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("Execute push FIFO function\n");
			break;
		case 2:
			printf("Execute push SJF function\n");
			break;
		case 3:
			printf("Execute push SRTF function\n");
			break;
		case 4:
			printf("Execute push Tourniquet function\n");
			break;
		default:
			printf("Invalid choice\n");
			goto t;
	}
	printf("==================================\n");
	for(int i = 1; i <= n; i++){
		p.id = i;
		printf("Donner Date d'arrivee de P%d : ", i);
		scanf("%d", &p.a_time);
		printf("Donner Duree d'execusion de P%d : ", i);
		scanf("%d", &p.r_time);
		printf("Donner Priorite de P%d : ", i);
		scanf("%d", &p.priority);
		p1 = create_process(p);
		switch(choice){
			case 1:
				push_FIFO(f, p1);
				break;
			case 2:
				push_SJF(f, p1);
				break;
			case 3:
				push_SRTF(f,p1);
				break;
			case 4:
				push_tourniquet(f,p1);
				break;
		}
		printf("==================================\n");
	}
}
void display(file f){
	process* tmp = f->head;
	printf("Tableau:\n");
	printf("+-----------+----------------+-------------------+----------+\n");
	printf("| Processus | Date d'arrivee | Duree d'execusion | Priorite |\n");
	for(int i = 1; i <= f->size; i++){
		printf("+-----------+----------------+-------------------+----------+\n");
		printf("|    P%d     |        %d       |         %d         |     %d    |\n",i,tmp->a_time - tmp->wait_time,tmp->r_time,tmp->priority);
		tmp = tmp->next;
	}
	printf("+-----------+----------------+-------------------+----------+\n");
}
void diagramme_Gant(file f, int n){
	int i = 0;
	int j;
	printf("Diagramme de Gant:\n");
	printf("process  :");
	for(j = 1; j <= f->size; j++){//kadir 1 2 3 4 ...
		printf(" %d", j);
	}
	printf("\n");
	process *p = NULL;
	process *tmp = NULL;
	while(f->tail != NULL){
		while(i < f->head->a_time + f->head->r_time){
			printf("%d       ", i);
			if(i <= 9)
				printf(" ");
			printf(":");
			for(j = 0; j < n - (f->size); j++){
				printf("  ");
			}
			printf(" o");
			//if(f->head->next != NULL){
				for(tmp = f->head->next; tmp != NULL; tmp = tmp->next){
					if(tmp->a_time - tmp->wait_time <= i)
						printf(" x");
				}
			//}
			printf("\n");
			i++;
		}
		p = pop_process(f);
	}
}
