#include<iostream>
using namespace std;
class Merge{
	public:
		Node* merge(Node* h1, Node* h2){
			if(h1==NULL || h2==NULL){
			 	return h1==NULL ? h2:h1;
			}
			
			if(h1->val<=h2->val){
				h1->next=merge(h1->next,h2);
				return h1;
				
			}
			else{
				merge(h1,h2->next);
				return h2;
			}
		}
};
