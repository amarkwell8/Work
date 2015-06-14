#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node { 
	int pid;
	int arrival_time; //make sure to take into account that there may be no process in cpu at arrival time 0
	int cpu_burst; //subract to zero throughout algs. 
	int wait_time;
	int finish_time;
	int wait; //0 if in cpu, 1 if waiting
	int finished; //0 if not finished, 1 otherwise
//	int count;
	struct node *next;
	struct node *prev;
};

int process_num = 0;
struct node *head = NULL;
struct node *current = NULL;

void create_list(int pid, int arrival_time, int cpu_burst) //creates and sorts by arrival time
{
	struct node *curr_node = (struct node*)malloc(sizeof(struct node));
	curr_node->next=NULL;
	curr_node->prev=NULL;
	curr_node->pid= pid;
	//printf("%d", pid);
	curr_node->arrival_time=arrival_time;
	//printf("\t%d", arrival_time);
	curr_node->cpu_burst=cpu_burst;
	//printf("\t%d\n", cpu_burst);
	curr_node->wait = 1;
	curr_node->finished = 0;
//	curr_node->count = process_num;
	process_num++;
	
	if (head == NULL)
	{
		head = curr_node;
		return;
	}
	
	struct node *point1 = head;
	struct node *point2 = head;
	
	while(point1 != NULL)
	{
		if(point1->arrival_time > curr_node->arrival_time)
		{
			if(point1 == head)
			{
				curr_node->next = head;
				point1->prev = curr_node;
				head = curr_node;
				break;
			}
			else
			{
				point2 = point1->prev;
				curr_node->prev = point1->prev;
				curr_node->next = point2->next;
				point2->next = point1->prev = curr_node;
				break;
			}
		}//end if
		else
		{
			if(point1->next == NULL)
			{
				point1->next = curr_node;
				curr_node->prev = point1;
				break;
			}
			else
			{
				point1 = point1->next;
			}
		}//end else
	}//end while
	
	return;
	
}

void FCFS()
{
	struct node *curr_node = head;
	int time = 0;
	while(curr_node != NULL)
	{
		if(curr_node->arrival_time <= time)
		{
			time = time + curr_node->cpu_burst;
			curr_node->finish_time = time;
			curr_node->wait_time = curr_node->finish_time - (curr_node->arrival_time + curr_node->cpu_burst);
			curr_node = curr_node->next;
		}
		else
		{
			time++;
		}
	}
	return;
}//FCFS end

void SRTF()
{
	struct node *curr_node = head; //head
	struct node *tail = head; //tail
	struct node *afterTail = tail->next;  
	struct node *travel = head;
	struct node *check = tail;
	struct node *check2 = tail->prev; 
	int curr_time = 0;
	
	while(process_num > 0)
	{
		//printf("%d\t%d\n", curr_node->pid, curr_node->cpu_burst);
		if(curr_node->cpu_burst == 0) // move head to remove process from ready queue
		{
			//printf("ghjkl\n");
			curr_node->finish_time = curr_time; //final change to finish time
			//printf("%d\n", curr_node->cpu_burst);
			curr_node = curr_node->next;
			//printf("%d\n", curr_node->cpu_burst);
			process_num--; //decrease process_num for while loop
		}
		if(afterTail != NULL)
		{
			if(afterTail->arrival_time == curr_time)//use tail to make ready queue
			{
				//printf("QWERTY\n");
				tail = afterTail;
				check = tail;
				check2 = tail->prev;
				afterTail = tail->next; // seg faults here //////////////////////////////////////////////////////////
				
					while(check->cpu_burst < check2->cpu_burst)
					{
						//printf("ASDF\n");
						//swap data and move check and check2 accordingly 
						int temp= check->cpu_burst;
						check->cpu_burst = check2->cpu_burst;
						check2->cpu_burst = temp;
					
						int temp1= check->pid;
						check->pid = check2->pid;
						check2->pid = temp1;
					
						int temp2= check->arrival_time;
						check->arrival_time = check2->arrival_time;
						check2->arrival_time = temp2;
					
						int temp3= check->wait_time;
						check->wait_time = check2->wait_time;
						check2->wait_time = temp3;
						
						int temp4= check->finish_time;
						check->finish_time = check2->finish_time;
						check2->finish_time = temp4;
					
						check = check->prev;
						check2 = check2->prev;
					}//End while
			
			}//End if
		}//End first if
		travel = curr_node;
		while(travel->next != afterTail) // traverse list from head to tail only // infinite loop /////////////////this isn't working!!!! Need to find a way to incoperate last node!!!!!! B/C last node travel->next does equal afterTail ///// Doesn't do anything with only one 
		{
			if(travel == curr_node)
			{
				travel->cpu_burst = travel->cpu_burst - 1;
				
			}	
			else
			{
				travel->wait_time = travel->wait_time + 1; 
				//printf("%d\t%d\n", travel->cpu_burst, travel->wait_time);
			}
			if(travel->next == tail)
			{
				tail->wait_time = tail->wait_time + 1;
			}
			
			travel = travel->next;
		}
		if(travel->next == afterTail && process_num == 1)
		{
			while(travel->cpu_burst !=0)
			{
				travel->cpu_burst = travel->cpu_burst - 1;
				curr_time++;
			}	
			travel->finish_time = curr_time;
			process_num--;
			break;
		}
		if(curr_node==tail)
		{
			curr_node->cpu_burst = curr_node->cpu_burst - 1;
		}
		//travel = head; // reset travel to head
		//printf("\n%d", tail->cpu_burst);///////////////
		//process_num--;///////////////////
		curr_time++;
		//printf("num proc! %d\n", process_num);
	}//end while
	

}//SRTF end
	
void print_list(char *out_name)
{
	struct node *point = head;

	FILE *fileout;
	fileout = fopen(out_name, "w");
	fclose(fileout);
	
	while(point != NULL)
	{
		FILE *file;
		file = fopen(out_name, "a+");
		
		fprintf(file, "%d ", point->pid);
		fprintf(file, "%d ", point->arrival_time);
		fprintf(file, "%d ", point->finish_time);
		fprintf(file, "%d\n", point->wait_time);
		
		head = point->next;
		free(point);
		point=head;
		fclose(file);
	}//end while
	
	free(point);
	
	return;
}//end print_list

int main(int argc, char **argv)
{
	int pid = 0, Prevpid = 0;
	int arrival_time = 0, cpu_burst = 0;
	FILE *input;
	input = fopen(argv[1], "r");
	
	
	while(1==1)
	{
		fscanf(input, "%d %d %d", &pid, &arrival_time, &cpu_burst);
		if(pid == Prevpid)
		{
			break;
		}
		Prevpid = pid;
		create_list(pid, arrival_time, cpu_burst);
	}
	
	
		
	if(strcmp(argv[3], "FCFS")==0)		FCFS();
	
	else if(strcmp(argv[3], "SRTF")==0) 	SRTF();

	print_list(argv[2]);
	fclose(input);
	
	free(head);
	free(current);
	
	return 0;
}
