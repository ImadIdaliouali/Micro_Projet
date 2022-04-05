typedef struct Process{
	int id;
	int r_time;// temp d'execusion
	int a_time;// temp d'arrive
	int wait_time;// temp d'attente
	int priority;// Priorite
	struct Process* next;
}process;
typedef struct{
	process* head;// tete de la file
	process* tail;// queue de la file
	int size;
}File;
typedef File* file;
