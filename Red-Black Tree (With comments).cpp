#include <iostream>
using namespace std;
struct node{				//node structure
	int info;
	node* left;				//left pointer
	node* right;			//right pointer
	node* p;				//parent
	bool red;				//boolean to determine whether node is black(red=false) or red(red=true)
};

node* root=new node;
node* lastnode=new node;	//to find last attached node
node* temp=new node;
node* newnode(int key){		//creation of new node with value key
	node* p=new node;
	p->info=key;
	p->left=NULL;
	p->right=NULL;
	p->red=true;
	p->p=NULL;

	return p;
}
void rotleft(node* x){		//left rotation of node x

	cout<<"\nrotleft\n";
	node* y=new node;
	// cout<<"\nRL1\n";

	y=x->right;
	if(y!=NULL && y->left)
	{
		x->right=y->left;
		// cout<<"\nRL2\n";
		if(y->left->p!=NULL)
			y->left->p=x;
	}
	else{
		// cout<<"\nELSE RL2\n";

		x->right=NULL;
	}
	if(y!=NULL)
		y->p=x->p;
	// cout<<"\nRL3\n";
	if (x->p==NULL)
	{
		root=y;
	}
	else if(x->p->left && x==x->p->left)
	{
		// cout<<"\nRL4\n";
		x->p->left=y;
	}
	else if(x->p->right && x==x->p->right){
		// cout<<"\nRL5\n";
		x->p->right=y;
	}
	y->left=x;
	x->p=y;
	y=x;
	// cout<<"\nRL6\n";
}
void rotright(node* y){		//right rotation of node x
	// if(y==root )
	// 	cout<<"\nroot\n";
	cout<<"\nrotright\n";
	node* x=new node;
	cout<<"\nRR1\n";
	x=y->left;
	if(x!=NULL){
		y->left=x->right;
		cout<<"\nRR2\n";
		if(x->right)
			x->right->p=y;
		x->p=y->p;
	}
	if (y->p==NULL)
	{
		cout<<"\nRR3\n";
		root=x;
	}
	else if (y->p!=NULL && y->p->left && y==y->p->left)
	{
		cout<<"\nRR4\n";
		y->p->left=x;
	}
	else if (y->p!=NULL && y->p->right && y==y->p->right){
		cout<<"\nRR5\n";
		y->p->right=x;
	}
	// else
		// cout<<"\nelse RR6\n";
	x->right=y;
	cout<<"\nx:"<<x->info;
	// if(x->right)
	// 	cout<<"\nx->right:"<<x->right->info;
	cout<<"\ny:"<<y->info;
	y->p=x;
	if(y->p)
	cout<<"\ny->p:"<<y->p->info;
}
node* treemin(node* root){	//to find leftmost node from a root
	while (root->left){
		if(root->left->info!=-1)
			root=root->left;
		else
			break;
	}
	cout<<"\nTM1\n";
	return root;
}
node* treesuc(node* x){		//to find successor of node x according to inorder traversal
	if(x->right){
		return treemin(x);
	}
	node* y=new node;
	y=x->p;
	while(y && x==y->right){
		x=y;
		if(y->p!=NULL)
			y=y->p;
	}
	cout<<"\nTS1\n";
	return y;
}
void delfix(node* x){		//to fix/balance rb tree after deletion of a node
	cout<<"\nD1";
	node* w=new node;
	cout<<"\nx->info:"<<x->info<<endl;
	cout<<"\nroot->info:"<<root->info<<endl;
	while(x!=root && x->red==false){
		cout<<"\n IN WHILE \n";
		if(x==x->p->left){
			cout<<"\nD2\n";
			w=x->p->right;
			if(w!=NULL){
				if(w->red==true){
					cout<<"\nD3\n";
					w->red=false;
					x->p->red=true;
					rotleft(x->p);
					w=x->p->right;
				}
				if((w->left==NULL || w->left->red==false )&& (w->right==NULL || w->right->red==false)){
					cout<<"\nD4\n";
					w->red=true;
					x=x->p;
				}
				else if( w->right && w->right->red==false){
					cout<<"\nD5\n";
					w->left->red=false;
					w->red=true;
					rotright(w);
					if(x->p)
						w=x->p->right;
				}
				else{
					w->red=x->p->red;
					x->p->red=false;
					if(w->right)
						w->right->red=false;
					rotleft(x->p);
					x=root;
				}
			}
		}
		else{
			cout<<"\nD6\n";
			if(x==x->p->right){
				w=x->p->left;
				cout<<"\nw:"<<w->info;
				if(w!=NULL){
					cout<<"\nD7A\n";
					if(w->red==true){
						cout<<"\nD7B\n";
						w->red=false;
						x->p->red=true;
						rotright(x->p);
						w=x->p->left;
					}
					if((w->left==NULL || w->left->red==false )&& (w->right==NULL || w->right->red==false)){
						cout<<"\nD8\n";
						w->red=true;
						x=x->p;
					}
					else if(w->left!=NULL && w->left->red==false){
						cout<<"\nD9\n";
						w->right->red=false;
						w->red=true;
						rotleft(w);
						if(x->p)
							w=x->p->left;

					}
					else{
						w->red=x->p->red;
						x->p->red=false;
						w->left->red=false;
						rotright(x->p);
						x=root;
						cout<<"\nD10\n";
					}
					cout<<"\nD7C\n";

				}

			}
		}
	}
	x->red=false;
	cout<<"\nOUTSIDE WHILE";
}
node* del(node* z){			//to delete node from rb tree
	if(root==NULL){
		cout<<"\nPlease create tree first";
		return NULL;
	}
	cout<<"\nTest D1\n";
	node* y=new node;
	node* x=new node;
	cout<<"\n D z:"<<z->info;
	if((z->left==NULL || z->left->info==-1) || (z->right==NULL || z->right->info==-1)){
		cout<<"\nTest D1A\n";
		y=z;
	}
	else
		y=treesuc(z);		//to find successor of node to be deleted

	cout<<"\nOUTSIDE treesuc y:"<<y->info;
	if(y->left && y->left->info!=-1){
		cout<<"\nTest D2\n";
		x=y->left;
	}
	else{
		cout<<"\nTest D3\n";
		x=y->right;
	}

	if(x==NULL){		//creation of double black node and it is assigned value -1
		cout<<"\nTest D4\n";
		x=newnode(-1);
		x->red=false;
	}


	x->p=y->p;

	if(y->p==NULL){
		cout<<"\nTest D5\n";
		root=x;
	}
	else if(y==y->p->left){
		cout<<"\nTest D6\n";
		y->p->left=x;
	}
	else{
		cout<<"\nTest D7\n";
		y->p->right=x;
	}

	if(y!=z){
		cout<<"\nTest D8\n";
		z->info=y->info;
	}

	if (y->red==false)
	{
		cout<<"\nSend to delfix\n";
		if(x->info!=-1)
			delfix(x);
	}
	// if(y->p){
	// 	cout<<"\nTest D9\n";
	// 	if(y==y->p->right){
	// 		cout<<"\nTest D10\n";
	// 		y->p->right=NULL;
	// 	}
	// 	else  if(y==y->p->left){
	// 		cout<<"\nTest D11\n";
	// 		y->p->left=NULL;
	// 	}
	// }
	return y;
}
void colfix(node* x){		//to fix/balance rb tree after insertion of a node
	node* temp=new node;
	cout<<"\nx:"<<x->info;
	cout<<"\ncolfix\n";
	while(x->p!=NULL && x->p->red==true){
		if(x->p==(x->p->p->left)){
			cout<<"\nTest1\n";
			temp=x->p->p->right;
			if(temp!=NULL && temp->red==true){
				cout<<"\nTest3\n";
				x->p->red=false;
				temp->red=false;
				if(x->p->p!=NULL){
					x->p->p->red=true;
					x=x->p->p;
				}
			}
			else if(x==x->p->right){
				cout<<"\nTest4\n";
				cout<<"\nx:"<<x->info;
				cout<<"\nx->p:"<<x->p->info;
				if(x->p->p)
					cout<<"\nx->p->p:"<<x->p->p->info;

				x=x->p;
				rotleft(x);
				cout<<"\nAfter LR x:"<<x->info;
				cout<<"\nAfter LR x->p:"<<x->p->info;
				if(x->p->p)
					cout<<"\nAfter LR x->p->p:"<<x->p->p->info;
				x->p->red=false;
				if(x->p->p)
					x->p->p->red=true;
				rotright(x->p->p);
				cout<<"\nAfter RR x:"<<x->info;
				cout<<"\nAfter RR x->p:"<<x->p->info;
				if(x->p->p)
					cout<<"\nAfter RR x->p->p:"<<x->p->p->info;

			}
			else if(x==x->p->left){
				cout<<"\n yeah Test6\n";

				x->p->red=false;

				x->p->p->red=true;
				// temp=x->p->p;
				rotright(x->p->p);
			}
		}
		else{
			cout<<"\nTest2\n";
			temp=x->p->p->left;
			cout<<"\nx:"<<x->info;
			cout<<"\ntemp:"<<x->info;
			if( temp!=NULL && temp->red==true ){
				cout<<"\nTest5\n";
				x->p->red=false;
				temp->red=false;
				if(x->p->p!=NULL){
					x->p->p->red=true;
					x=x->p->p;
				}
				cout<<"\nTest5 exit\n";
			}
			else if(x==x->p->left){
				cout<<"\nTest6\n";
				// temp=x->p;
				x=x->p;
				cout<<"\nx:"<<x->info;
				cout<<"\nx->p:"<<x->p->info;
				// cout<<"\nx->p->p:"<<x->p->p->info;

				rotright(x);

				cout<<"\nOUT OF RR\n";
				// cout<<"\nx->right->p:"<<x->right->p->p->info;

				if(x->p){
					cout<<"\nx->p:"<<x->p->info;
					x->p->red=false;
					if(x->p->p)
						x->p->p->red=true;
				}
				cout<<"\nx:"<<x->info;
				// temp=x->right;
				// temp=x->p->p;
				if(x->p->p)
					rotleft(x->p->p);
			}
			else if(x==x->p->right){
				cout<<"\n yeah Test6\n";

				x->p->red=false;

				x->p->p->red=true;
				// temp=x->p->p;
				rotleft(x->p->p);
			}
		}
	}
	cout<<"\nTest15\n";
	root->red=false;
	cout<<"\nx:"<<x->info;
	if(x->p){
		cout<<"\nx->p:"<<x->info;
		if(x->p->right)
			cout<<"\nx->p->right:"<<x->p->right->info;
		if(x->p->left)
			cout<<"\nx->p->right:"<<x->p->left->info;

	}
	// cout<<"\nTest16\n";
}
void add(node *t2,int x){	//to insert a node in rb tree
	if(root==NULL)
	{
		root=newnode(x);
		root->red=false;
		return;
	}
	else
	{
		if(t2->info>x)
		{
			if(t2->left!=NULL)
				add(t2->left,x);
			else{
				t2->left=newnode(x);
				t2->left->p=t2;
				lastnode=t2->left;
				// cout<<"\nt2->val:"<<t2->info;
				if(t2->left->p->p!=NULL){

					cout<<"\nt2->left->p->p->info\n"<<t2->left->p->p->info;
					cout<<"\nt2->left->p->info\n"<<t2->left->p->info;
					colfix(t2->left);
				}
			}
		}
		else if(t2->info<x)
		{
			if(t2->right!=NULL)
				add(t2->right,x);
			else{
				t2->right=newnode(x);
				t2->right->p=t2;
				lastnode=t2->right;
				if(t2->right->p->p!=NULL){
					cout<<"\nSending to colfix t2->right\n";
					colfix(t2->right);
				}
				// cout<<"\nt2->val:"<<t2->info;

			}
		}
	}
}
void inorder(node* temp){	//inorder traversal of rb tree
	if(root==NULL){
		cout<<"\n Create tree first";
		return;
	}
	else if(root->info==-1){
		cout<<"\n Create tree first";
		return;
	}

	if(temp==NULL)
		return;

	inorder(temp->left);
	if(temp==root)
		cout<<"\nroot: "<<temp->info;
	else if(temp->info==-1)
		return;

	else
		cout<<"\n"<<temp->info;

	if(temp->red )
		cout<<" color:red";
	else
		cout<<" color:black";
	inorder(temp->right);
}

node* found=NULL;			//to save found/searched node
node* search(node* temp,int x){		//to search a node in rb tree

	if(root==NULL){
		return NULL;
	}
	else if(root->info==-1){
		return NULL;
	}
	if(temp==NULL)
		return temp;

	// cout<<"\nSearch\n";
	search(temp->left,x);
	if(temp->info==x){
		found=temp;
	}
	search(temp->right,x);
	return found;
}
int main()					// main driver function
{

	root=NULL;
	temp=NULL;
	char ch='y';

	int x=0;
	while(ch=='y'){
		cout<<"\nMenu For RB-tree Actions:\n1.Insertion\n2.Deletion\n3.Search\n\nEnter your Choice:";
		int choice=0;
		cin>>choice;		//input for action
		switch(choice)
		{
			case 1:{
				int n=0;
				cout<<"Enter no. of elements:";
				cin>>n;
				cout<<"\nEnter elemnts:";


				for (int i = 0; i < n; ++i)
				{
					// cin>>a[i];
					cin>>x;
					add(root,x);
				}
				break;
			}
			case 2:{

				cout<<"\nEnter node to be deleted:";
				cin>>x;
				temp=search(root,x);
				if(temp)
					cout<<"\nFound:"<<temp->info;
				node* deleted=NULL;
				if(temp)
					deleted=del(temp);
				if(deleted!=NULL)
				{
					if(deleted!=root){
						cout<<"\nNode deleted:"<<deleted->info;
					}
					else if(deleted==root){
						cout<<"\nRoot Deleted!";
						root=NULL;
					}
					delete deleted;
				}
				break;
			}
			case 3:{
				cout<<"\nEnter node to be searched:";
				cin>>x;
				temp=search(root,x);
				if(temp){
					cout<<"\nFound:"<<temp->info;
					if(temp->red==false)
						cout<<" color:black\n";
					else
						cout<<" color:red\n";
				}
				else
					cout<<"\nNode not found\n";
				break;
			}

			default: cout<<"\nWrong input";
		}
		cout<<"\nStatus after actions:";
		inorder(root);
		cout<<"\nDo wish to continue? (y/n)";
		cin>>ch;
	}
}
