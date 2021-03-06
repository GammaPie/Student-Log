

#include "pch.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <ostream>
using namespace std;

//////////////////////////////////////////Student Structure//////////////////////////////////////////////////////////////////
struct student {
	char id[8];
	char name[30];
	float gpa;
	int credit_hours;
	
}student1, student2, student3;

int compare(student x, student y) {
	int i = 0;
	while (i < 8) {
		if (x.id[i] == y.id[i]) {
			i++;
		}
		else {
			return 0;
		}
	}
	return 1;
	
};

//////////////////////////////////////////Linked List and Node Setup////////////////////////////////////////////////////////
//node structure
class List {

private:
	typedef struct node {
		student data;
		node* next;
		
	}*nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:	//manipulators
	List() {
		head = NULL;
		curr = NULL;
		temp = NULL;
	};

	void AddNode(student data) {
		nodePtr n = new node;
		n->next = NULL;
		n->data = data;

		if (head != NULL) {
			curr = head;
			while (curr->next != NULL) {
				curr = curr->next; 
			}
			curr->next = n;
		}
		else {
			head = n;
		}
	}
	void DeleteNode(student data) {
		nodePtr delPtr = NULL;
		temp = head;
		curr = head;
		while (curr != NULL && compare(curr->data,data) == 0) {
			temp = curr;
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "The student was not in the list\n";
			delete delPtr;
		}
		else {
			delPtr = curr;
			curr = curr->next;
			temp->next = curr;
			delete delPtr;
			cout << "The student was deleted!\n";

		}
	
	
	}
	void PrintList() {
		curr = head;
		while (curr != NULL) {
			cout << "ID: " <<curr->data.id << "		Name: " <<curr->data.name <<  
				"	   GPA: " << curr->data.gpa << "	  Credit Hours: " << curr->data.credit_hours << endl;
			curr = curr->next;
		}
	}

	void Search(student data) {
		curr = head;
		while (curr != NULL && compare(curr->data, data) == 0) {
			temp = curr;
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "The student was not in the list\n";
		}
		else {
			cout << "The student was found and is displayed below!\n";
			cout << "ID: " << curr->data.id << "		Name: " << curr->data.name <<
				"	   GPA: " << curr->data.gpa << "	  Credit Hours: " << curr->data.credit_hours << endl;
		}
	}
	
};


//////////////////////////////////////////////Main/////////////////////////////////////////////////////////////////////////
int main()
{	
	List students;


	//student1 specification
	student student1 = { "abc1234", "Dennis", 3.9, 24};
	students.AddNode(student1);

	//student2 specification
	student student2 = { "def1234", "Bruce", 3.4, 20};
	students.AddNode(student2);

	//student3 specification
	student student3 = { "ghi1234", "Davik", 3.1, 12};
	students.AddNode(student3);

	students.PrintList();
	students.DeleteNode(student2);
	students.Search(student2);
	students.Search(student3);

}
