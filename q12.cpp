#include <iostream>
#include "tddFuncs.h"
#include "linkedlist.h"

using namespace std;


void printList(Node* head);

//This function will be called
void printReverseLinkedList(LinkedList& l){
	//calls a helper function passing in the first element. This is necessary because otherwise we would have to create new linkedlists to call the function recursively on smaller inputs. By using a helper function, we can just pass in a pointer to the next node.
	printList(l.head);


}

//helper function to avoid creating a new list
void printList(Node* head){
	//we have a pointer to an element (I think of it as a pointer to the first one).
	
	//Let's check if it is NULL. If it is, that means that the list is empty, which is the simplest case - I din't have to print anything!
	if(head == NULL){
		return;
	}

	//Next, I want to decide what to do with the call on smaller inputs. If I have a list 1->2->3->4->5, and my 'head' points to 1, I want '5 4 3 2' to be printed before I finally print my element that head points to (1).
	//Now, since I want 5 4 3 2 printed before I print my 1, I will just call the function on a smaller input assuming that it works correctly
	printList(head->next);
	
	//Now that 5 4 3 2 have all been printed, I need to print my own element.
	cout << head->data << " ";

	//done!	

}

int main(){

	Node n5{50,0};
	Node n4{40,&n5};
	Node n3{35,&n4};
	Node n2{20, &n3};
	Node n1{10,&n2};
	LinkedList myList{&n1,&n5};
	
	printReverseLinkedList(myList);


	cout << "\n";

	return 0;


}
