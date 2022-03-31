typedef struct Process{
	int id;
	int r_time;// temp d'exection
	int a_time;// temp d'arrive
	int priority;
	struct Process* next;
}process;
struct File{
	process* head;
	process* tail;
	int size;
};
typedef struct File* file;