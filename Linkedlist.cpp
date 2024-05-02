#include <iostream>
using namespace std;

class Node{
	public:
		char id;
		Node *next;
		
		Node(){
			next = NULL;
		}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
		LinkedList(){
			head = tail = NULL;
		}
		
		void inserttohead(char data){
			
			Node *node = new Node();
			node->id = data;
			
			Node *tmp = head;
			head = node;
			node->next = tmp;
		}
		
		void inserttotail(char data){
			
			Node *node = new Node();
			node->id = data;
			
			tail->next = node;
			tail = node;
		}
		
		void printall(){
			if(head!=NULL){
				Node *tmp = head;
				do{
					cout << tmp->id << "->";
					tmp = tmp->next;
				}while(tmp!=NULL);
			}
		}
		void addAfter(int target, int inputValue){ 
			Node *tmp = head; 
			while (tmp != NULL){ 
				if (tmp->id == target){ 
					Node *newNode = new Node();
					newNode->id = inputValue; 
					newNode->next = tmp->next;
					tmp->next = newNode;
					break; 
				} 
			tmp = tmp->next; 
			}
		}
		void addBefore(int target, int inputValue){
		if(target==head->id){
			inserttohead(inputValue);
		}
		else{
		Node *tmp= head;
		while(tmp->next!=NULL){
			if(tmp->next->id==target){
				Node *newNode=new Node();
				newNode->id =inputValue;
				newNode->next=tmp->next;
				tmp->next=newNode;
				break;
			}
			tmp=tmp->next;
		}	
		}
		
		}
		
		void DeleteFromHead(){
			Node *tmp = head;
			
			if (head == tail){//jika hanya ada satu elemen
				head = tail = NULL;
			}else{//jika elemen lebih dari satu
				head = head->next;
			}
			delete tmp;
		}
		void DeleteFromTail(){
		 Node *tmp = head;
		    if (head == tail) {
				head = tail = NULL;
				delete tmp;
		    } 
			else {
				while(tmp->next != NULL){
					if(tmp->next==tail){
						tail=tmp;
						tmp->next=NULL;
						break;
					}
				tmp=tmp->next;
				}
				delete tmp->next;      
		    }
			
		}
};


int main(int argc, char** argv) {
	
	LinkedList *link1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->id = 'Y';
	
	link1->head = node1;
	link1->tail = node1;
	
	cout << link1->head->id << endl;
	cout << node1 << endl;
	
	Node *node2 = new Node();
	node2->id = 'U';
	
	link1->tail->next = node2;
	link1->tail = node2;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	Node *nodeX = new Node();
	nodeX->id = 'A';
	
	Node *tmp = link1->head;
	link1->head = nodeX;
	nodeX->next = tmp;
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	link1->inserttohead('A');
	link1->inserttotail('C');
	
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;
	
	link1->printall();
	cout << endl;
	
	link1->addAfter('A','B');
	link1->addBefore('X','U');
	
	link1->printall();
	cout << endl;
	
	link1->DeleteFromHead();
	link1->DeleteFromTail();
	
	link1->printall();
	cout << endl;
	
	return 0;
}
