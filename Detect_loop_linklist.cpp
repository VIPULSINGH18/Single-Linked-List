// this code us ised to detect the loop inside the link list

#include<iostream>
using namespace std;
class Detect{
	public:
		bool detect(Node* head){
			
			Node* slow=head;
			Node* fast=head;
			
			while(fast!=NULL && fast->next!=NULL){
				
				slow=slow->next;
				fast=fast->next->next;
				
				if(slow==fast){
					return true;
					
				}
				
			}
			return false;
			
		}
};




// this code is used to detect whether the is cycle or not and to print that node from where loop started,and to delete the 


#include<iostream>
using namespace std;
class Print{
	public:
		Node* print(Node* head){
			Node* slow= head;
			Node* fast= head;
			bool is_loop;
			while(fast!=NULL && fast->next!=NULL){
				slow=slow->next;
				fast=fast->next->next;
				if(slow==fast){
					is_loop=true;
					break;
				}
				
				
		}
		if(!=is_loop){
			return NULL;
		}
		
		
		// this part will display starting node of the cycle or loop ...
		slow=head;
		
		while(slow!=fast){
			slow=slow->next;
			fast=fast->next;
			if(slow==fast){
				return slow; 
			}
			
		}
		
		
		
		
		// this part will delete that cycle..
		
		slow=head;
		Node* prev;
		while(slow!=fast){
			slow=slow->next;
			prev=fast;
			fast=fast->next;
			if(slow==fast){
				return slow;
			}
		}
		prev->next=NULL;
		tail=prev;
		return slow;
		
		
	
}
};



