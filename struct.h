typedef struct Process{
	int id;
	int r_time;// temp d'exection
	int a_time;// temp d'arrive
	int att_time;// temp d'attente
	int priority;
	struct Process* next;
}process;
typedef struct{
	process* head;
	process* tail;
	int size;
}File;
typedef File* file;
