/*** Function for create the process ***/
process* create_process(process p){
	process *p1 = (process*)malloc(sizeof(process));
	p1->id = p.id;
	p1->r_time = p.r_time;
	p1->a_time = p.a_time;
	p1->priority = p.priority;
	p1->wait_time = 0;
	p1->next = NULL;
	return p1;
}
/*** Function for Initialize the file ***/
file init_file(){
	file f = (file)malloc(sizeof(File));
	f->head = NULL;
	f->tail = NULL;
	f->size = 0;
	return f;
}
/*** Pop the process in head ***/
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
/*** Read the head of the file ***/
process* read_process(file f){
	if(f->head == NULL)
		exit(0);
	else
		return f->head;
}
/*** Push a process with FIFO(First In First Out) ***/
void push_FIFO(file f, process *p){
	if(f->tail == NULL)
		f->head = f->tail = p;
	else{
		int b = f->tail->a_time + f->tail->r_time;
		if(b > p->a_time){
			p->wait_time = b - p->a_time;
			p->a_time += p->wait_time;
		}
		f->tail->next = p;
		f->tail = p;
	}
	f->size++;
}
/*** push a process with SJF(Short Job First) ***/
void push_SJF(file f, process *p){
	if(f->tail == NULL)
		f->head = f->tail = p;
	else{
		int b;
		process *tmp = f->head;
		process *previous = NULL;
		bool q = true;
		while(tmp != NULL && q == true){
			if(p->a_time < tmp->a_time && tmp->r_time > p->r_time){
				previous->next = p;
				p->next = tmp;
				b = previous->a_time + previous->r_time;
				p->wait_time = b - p->a_time;
				p->a_time += p->wait_time;
				process *count = tmp;
				process *pre = p;
				while(count != NULL){
					count->wait_time += p->r_time;
					count->a_time += p->r_time;
					pre = tmp;
					count = count->next;
				}
				q = false;
			}
			else{
				previous = tmp;
				if(tmp->next == NULL){
					b = tmp->a_time + tmp->r_time;
					if(b > p->a_time){
						p->wait_time = b - p->a_time;
						p->a_time += p->wait_time;
					}
					tmp->next = p;
					f->tail = p;
					q = false;
				}
				tmp = tmp->next;
			}
		}
	}
	f->size++;
}
/*** push a process with SRTF(Short Remaining Time First) ***/
void push_SRTF(file f,process* p){
	if(f->tail == NULL)
		f->head = f->tail = p;
	else{
		
	}
	f->size++;
}
/*** push a process with Tourniquet ***/
void push_tourniquet(file f,process* p){
	if(f->tail == NULL)
		f->head = f->tail = p;
	else{

	}
	f->size++;
}
/*** Create the file ***/
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
		printf("Enter Arrival time of P%d : ", i);
		scanf("%d", &p.a_time);
		printf("Enter Remaining time of P%d : ", i);
		scanf("%d", &p.r_time);
		printf("Enter Priority of P%d : ", i);
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
				push_SRTF(f, p1);
				break;
			case 4:
				push_tourniquet(f, p1);
				break;
		}
		printf("==================================\n");
	}
}
/*** Display ***/
void display(file f){
	process* tmp = f->head;
	printf("Tableau:\n");
	printf("+-----------+----------------+-------------------+----------+----------------+\n");
	printf("| Processus | Date d'arrivee | Duree d'execusion | Priorite | temp d'attente |\n");
	while(tmp != NULL){
		printf("+-----------+----------------+-------------------+----------+----------------+\n");
		printf("|    P%d     |        %d       |         %d         |     %d    |        %d       |\n", tmp->id, tmp->a_time - tmp->wait_time, tmp->r_time, tmp->priority,tmp->wait_time);
		tmp = tmp->next;
	}
	printf("+-----------+----------------+-------------------+----------+----------------+\n");
}
/*** search with id ***/
process* search_id(file f, int i){
	process *tmp =f->head;
	while(tmp != NULL && tmp->id != i)
		tmp = tmp->next;
	return tmp;
}
/*** Gantt Chart ***/
void Gantt_chart(file f){
	int i = 0, j, k = 1;
	printf("Diagramme de Gant:\n");
	printf("process  :");
	for(j = 1; j <= f->size; j++){
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
			for(j = 1; j < k; j++){
				printf("  ");
			}
			if(f->head->id == k){
				printf(" o");
				for(tmp = f->head->next; tmp != NULL; tmp = tmp->next){
					if(tmp->a_time - tmp->wait_time <= i)
						printf(" x");
				}
			}
			else{
				int d = k;
				tmp = search_id(f, d);
				while(tmp != NULL){
					if(tmp->id != f->head->id){
						if(tmp->a_time - tmp->wait_time <= i)
							printf(" x");
						else
							printf(" o");
					}
					else
						printf(" o");
					d++;
					tmp = search_id(f, d);
				}
			}
			printf("\n");
			i++;
		}
		if(f->head->id == k)
			k++;
		p = pop_process(f);
	}
}