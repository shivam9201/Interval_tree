/*
	@author Shivam Kumar
	INTERVAL TREES cpp code for insertion , deletion and search for any interval
	n in main function denotes number of nodes to be inserted
	Give input as l for left and r for right of the interval
	
*/

#include<bits/stdc++.h>

using namespace std;

struct node {
	int l,r,maxi;
	struct node* right;struct node* left;
	node(int l,int r):r(r),l(l),right(NULL),left(NULL)
	{
		maxi = r;	
	}
};

void insert(node* &root , int l, int r){
	if(root == NULL){
		root = new node(l,r);
		return;
	}
	root->maxi = max(root->maxi,r);
	if(root->l >= l){
		insert(root->left , l,r);
	}
	else insert(root->right,l,r);
}

node* get_inorder_succ(node* root){
	if(root->left == NULL)return NULL;
	root = root->left;
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}

void delete_node(node* &root , int l, int r){
	if(root == NULL)return;
	if(root->l == l && root->r == r){
		node* succ = get_inorder_succ(root);
		if(succ!=NULL){
			root->l = succ->l;
			root->r = succ->r;
			delete_node(root , succ->l,succ->r);
		}
		else {
			delete root;
		}
	}
	else if(root->left <= l){
		delete_node(root->left,l,r);
	}
	else delete_node(node->right,l,r);
	root->maxi = max(root->maxi,max(root->left->maxi,root->right->maxi));
}

pair<int,int> search(node* &root , int l, int r){
	if(root == NULL){
		return make_pair(-1,-1);
	}
	if(!(root->r > l) && !(root->l>r)){
		return make_pair(root->l,root->r);
	}
	else if(root->left->maxi >=l){
		return search(root->left,l,r);
	}
	else return search(root->right,l,r);
}

// void inorder(node* root){
// 	if(root == NULL)return;
// 	inorder(root->left);
// 	cout<<root->l<<" "<<root->r<<" "<<root->maxi<<endl;
// 	inorder(root->right);
// }

int main(){
	int n;
	cin>>n;
	node* root = NULL;
	for(int i = 0;i<n;i++){
		int l,r;
		cin>>l>>r;
		insert(root,l,r);
	}
	//inorder(root);
	return 0;
}
