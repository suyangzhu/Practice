#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* left;
	struct Node* right;
} Node_t;

void insert(int key, Node_t** root) {
	if ((*root) == NULL) {
		(*root) = (Node_t*) malloc (sizeof(Node_t));
		(*root)->val = key;
		(*root)->left = NULL;
		(*root)->right = NULL;
	} else {
		if (key < (*root)->val) 
			insert(key, &(*root)->left);
		else 
			insert(key, &(*root)->right);
	}	
	
}

Node_t* search(int key, Node_t* root) {
	if (root == NULL || root->val == key) 
		return root;
	else if (key < root->val) {
		return search(key, root->left);
	} else 
		return search(key, root->right);
}

void delete(int key, Node_t** root) {
	Node_t *prev;	
	if ((*root) == NULL)
		return;
	else if (key == (*root)->val) {
		if ((*root)->left == NULL) {
			// free root
			prev = *root;
			(*root) = (*root)->right;
			free(prev);
		} else if ((*root)->right == NULL) {
			// free previous root;
			prev = *root;
			(*root) = (*root)->left;
			free(prev);
		} else {
			Node_t* trace = *root;
			Node_t* traceParent;
			while (trace->left) {
				traceParent = trace;
				trace = trace->left;
			}
			prev = trace;
			(*root)->val = trace->val;
			traceParent->right = trace->right;
			free(prev);
		}
	} else if (key < (*root)->val) {
		delete(key, &(*root)->left);
	} else  
		delete (key, &(*root)->right);

}

void pre_order(Node_t* root) {
	if (root == NULL) 
		return;
	printf("%d\n", root->val);
	pre_order(root->left);
	pre_order(root->right);
}

void in_order(Node_t* root) {
	if(root == NULL) 
		return;
	in_order(root->left);
	printf("%d\n", root->val);
	in_order(root->right);
}

void post_order(Node_t* root) {
	if(root == NULL) 
		return;
	post_order(root->left);
	post_order(root->right);
	printf("%d\n", root->val);
}

typedef struct LLNode {
//	LLNode(Node_t* t, struct LLNode* n) : next(n), tree(t) {}
	struct LLNode* next;
	Node_t* node;
} LLNode_t;

typedef struct ListOfLists {
//	ListOfLists() : next(NULL), data(NULL) {}
	struct ListOfLists* next;
	LLNode_t* data;
}ListOfLists_t;

int maxdepth(Node_t* root) {
  if (root == NULL)
    return 0;
  return maxdepth(root->left) > maxdepth(root->right) ? \
  1+maxdepth(root->left) : 1+maxdepth(root->right);
}

int mindepth(Node_t* root) {
  if (root == NULL)
    return 0;
  return maxdepth(root->left) < maxdepth(root->right) ? \
  1+maxdepth(root->left) : 1+maxdepth(root->right);
}


int main() {
	Node_t* root = NULL;
	insert(1, &root);
	insert(2, &root);
	insert(3, &root);
	insert(4, &root);
	insert(2, &root);
	in_order(root);
  printf("MAX Depth = %d\nMIN Depth = %d\n", maxdepth(root), mindepth(root));
	Node_t* index = search(2, root);
	printf("index (2) = %d\n", index->val);
	printf("------------------\n");
	delete(2, &root);
	in_order(root);
  

	return 0;
}



