//Austin Markwell
//CECS 230
// Binary Tree

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

//Begin main
int main()
{
//arrays	
	vector<int> notTree;
	int sortedTree [100] = {};
	int list[100];
	
	for (int s = 0; s<100; s++)
	{
		list[s]=s+1;
	}
//set sortedTree values to 0
	
//read txt file in
	ifstream in("tree_nodes.txt",ios::in); 
    int k;  
        
    while (in >> k) 
		{ 
        notTree.push_back(k); 
        }
	in.close(); 


//Binary tree magic
	for(int x=0; x <= notTree.size(); x++)
	{
		int placehold = 1;
		
		int check = 0;
		while(check != 1)
		{
			if(sortedTree[placehold]== 0)
			{
				sortedTree[placehold] = notTree[x];
				int placehold = 1;
				check = 1;
			}
			
			else 
			{	
				if(notTree[x] < sortedTree[placehold])
				{
					placehold = 2*placehold;
				}//end nested if
				
				else if(notTree[x] > sortedTree[placehold])
				{	
					placehold=2*placehold+1;
				}//end nested else if
				
				else //values are equal
				{
					int placehold = 1;
					check = 1; 
				}//end nested else 
				
			}//end else 
			
		}//end while loop
		
	}//end for loop
	
	cout<<"Array position:\t\t"<<"Tree:\n";
//print out sorted tree
	for(int q = 1; q <= 99; q++)
	{
		cout<<list[q-1]<<"\t\t\t";
		cout<<sortedTree[q]<<"\n";
	}

	return 0;
}//End main
