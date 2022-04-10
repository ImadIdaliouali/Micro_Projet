typedef struct Process{
	int id;// the id of the process
	int r_time;// Remaining time
	int a_time;// Arrival time
	int priority;// Priority
	int wait_time;// Waiting time
	struct Process* next;
}process;
typedef struct{
	process* head;// head of file
	process* tail;// tail of file
	int size;// size of file
}File;
typedef File* file;