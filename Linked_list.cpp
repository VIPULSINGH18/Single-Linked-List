//  code to make a single node of linked list
// we create the multiple objects of class node to create multiple nodes where each object refers to nodes..
//
//#include<iostream>
//using namespace std;
//class Node{
//	public:
//		int data;
//		Node* next;
//	Node(int val){
//		data=val;
//		next=NULL;
//	}
//};







// this code is to create a proper linked list

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	Node(int val){
		data=val;
		next=NULL;
	}	
};
	

class List{
	Node* head;
	Node* tail;
	public:
		
	List(){
		head=tail=NULL;
	}
	
	
	// 	O(1)
	void push_front(int val){ // push front function which takes element from the front of the linked list
		Node* newNode= new Node(val); // creating a new node
		if(head==NULL){
			head=tail=newNode; // first node
			
		}
		else{
			newNode->next= head; // establish the connection betweem node and head of another node
			head=newNode; // transferring head to first node of the linked list
		}
	}
	
	
	
		// 	O(1)
	void push_back(int val){ // push back function which takes the element from back of the linked list
		Node* newNode=new Node(val);
		if(head==NULL){
			head=tail=newNode;
			return ;
		}
		else{
			tail->next=newNode;
			tail=newNode;
		}
	}
	
	
		// 	O(1)
	void pop_front(){ // it deletes the element from the starting position of the linked list 
		if(head==NULL){
			cout<<"Linked list is empty";
			return;
		}
		
		
		else if(head==tail){
			delete head;
			head=tail=NULL;
			return;
		}
		
		else{
			Node* temp=head;
			head = head->next;
			temp->next=NULL;
			delete temp;
			
			
		}
	}
	
	
		// 	O(n)
	void pop_back(){ // it deletes the element from the ending position of the linked list
		if(head==NULL){
			cout<<"Linked list is empty";
			return;
		}
		else if(head==tail){
			delete head;
			head=tail=NULL;
			return;
		}
		else{
			Node* temp=head;
			while(temp->next!=tail){
				temp=temp->next;
				
			}
			temp->next=NULL;
			delete tail;
			tail=temp; 
		}
	}
	
		// 	O(n),  best case= O(1)
	void insert(int val,int pos){ // inserting the elements in linked list at desired position...
		if(pos<0){
			cout<<"Invalid position";
			return;
		}
		
		else if(pos==0){
			push_front(val);
			return;
		}
		
		else{
		
		Node* temp=head;
		for(int i=0;i<pos-1;i++){
		
			temp=temp->next;
			if(temp==NULL){  // this function is written because if position become greater than length of linked list then
							// return invalid position...
				cout<<"Invalid position";
			}
		}
		
		Node* newNode = new Node(val);
		newNode->next= temp->next;
		temp->next=newNode;
		
	}
}

	    // 	O(n), best case= O(1)
		int search(int key){ // this function return that idx where key value is present in the linked list...
			
			Node* temp=head;
			int idx=0;
			
			while(temp!=NULL){
				if(temp->data==key){
					return idx;
				}
				temp=temp->next;
				idx++;
				
			}
			return -1;
			
		}
	
	
	
	
	
		// 	O(n)
	void PrintLL(){ // code to print the element of linked list...
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	
};


 

int main(){
	List ll;
	ll.push_front(1);
	ll.push_front(2);
	ll.push_front(3);
	ll.push_back(4);
	ll.push_back(5);
	ll.push_back(6);
	ll.pop_front();
	ll.pop_back();
	ll.insert(4,3);
	ll.PrintLL();
	int result=ll.search(3);
	cout<<result;
	return 0;
	
	
}








