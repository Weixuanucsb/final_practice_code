#include <iostream>
#include "tddFuncs.h"
#include "linkedlist.h"

using namespace std;


//Precondition: list is a pointer to a valid linked list with nodes containing values in increasing order.
//Postcondition: a new node with data being the value parameter has been inserted to the list.
void insertNode(LinkedList* list, int value){
	//if list is empty to begin with, just insert a new node and change pointers
	if(list->head == NULL){
		Node* n = new Node{value, 0};
		list->head = n;
		list->tail = n;
		return;

	}
	//here I have a tmp pointer that I use to iterate through a list and a prev pointer that will point to a node preceding tmp. This will be needed for reconnecting nodes.
	Node* prev = NULL;
	Node* tmp = list->head;
	//iterate through the list and find the first element that is larger that value.
	while(tmp && tmp->data < value){
		prev = tmp;
		tmp = tmp->next;
	}
	//tmp is either NULL or pointing to the first element that is larger than value
	
	//if tmp is NULL, means that value is larger than the current largest element in the list. Insert one to the back.
	if(tmp == NULL){
		Node* n = new Node{value, 0};
		prev->next = n;
		list->tail = prev;
		return;
	}

	//it is possible that tmp is still pointing to the first element - all elements in the list were larger than value
	if(tmp == list->head){
		Node* n = new Node{value, tmp};
		list->head = n;
		return;
	}

	//if we are here, this means that tmp points to the first element that is larger than value. (inserting to the middle)
	Node* n = new Node{value, tmp};
	prev->next = n;
		

}
//a function to visualize a linked list. Used to show the effect of inserting a value.
void printLinkedList(Node* head){
	if(head){
		cout << head->data << "->";
		printLinkedList(head->next);
	}
	else{
		cout << "NULL\n";
	}

}


int main(){


	//creating a linked list 10->20->40->NULL
	Node n3{40,0};
	Node n2{20, &n3};
	Node n1{10,&n2};
	LinkedList list1{&n1,&n3};

	//creating a list 80->95->100->NULL
	Node n6{100,0};
        Node n5{90, &n6};
        Node n4{80,&n5};
        LinkedList list2{&n4,&n6};

	//creating a list 14->16->18->NULL
        Node n7{18,0};
        Node n8{16, &n7};
        Node n9{14,&n8};
        LinkedList list3{&n9,&n7};

	//creating an empty list
	LinkedList list4{0,0};

	cout << "list1 before insert: ";
	printLinkedList(list1.head);
	cout << "list2 before insert: ";
        printLinkedList(list2.head);
	cout << "list3 before insert: ";
        printLinkedList(list3.head);
        cout << "list4 before insert: ";
        printLinkedList(list4.head);

	//change this value to test on different input
	int val = 34;

	cout << "\n\ninserting: " << val << "\n\n";

	insertNode(&list1,val);
	insertNode(&list2,val);
	insertNode(&list3,val);
	insertNode(&list4,val);

	cout << "list1 after insert of " <<  val << ": ";
        printLinkedList(list1.head);
        cout << "list2 after insert of " <<  val << ": ";
	printLinkedList(list2.head);
	cout << "list3 after insert of " <<  val << ": ";
        printLinkedList(list3.head);
	cout << "list4 after insert of " <<  val << ": ";
        printLinkedList(list4.head);








	return 0;


}





