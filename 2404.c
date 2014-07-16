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
/**. The node existence in treee. */
int isChild(Node_t* root, Node_t* node) {
  if (!root)
    return 0;
  if (root == node) 
    return 1;

  // Recursively traverse the tree to see if 
  // the node matches the nodes in the tree.
  return isChild(root->left, node) || 
         isChild(root->right, node);
}

Node_t* leastCommonAncestor(Node_t* root, Node_t* node1, Node_t* node2) {
  // Both node1 and node2 belongs to left side.
  if (isChild(root->left, node1) && 
      isChild(root->left, node2))
    return leastCommonAncestor(root->left, node1, node2);
  // Both node1 and node2 belongs to right side.
  else if(isChild(root->right, node1)&&
          isChild(root->right, node2))
    return leastCommonAncestor(root->right, node1, node2);
  else
    return root;
}

Node_t* leastCommonAncestor2(Node_t* root, Node_t* node1, Node_t* node2) {
  if (!root) {
    return NULL;
  }
  if (root == node1 || root == node2) 
    return root;

  Node_t* left = leastCommonAncestor2(root->left, node1, node2) ;
  Node_t* right = leastCommonAncestor2(root->right, node1, node2);
  if ((left == node1 && right == node2)||(left == node2 && right == node1))
    return root;
  // I do not know why this line is here.
  return left? left : right;
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
/* Pseudo code.
 * @brief Find the in-order successor of a node of a binary search
 * tree. Suppose each node has a link to its parent.
 *
 * If the node is root and has right child. The successor is its right 
 * child's left most child.
 *
 * Otherwise the successor is the first node whose parent's left child is 
 * itself. 
 */
/*
Node_t* inorderSuccessor(Node_t* node) {
  Node_t* par;
  if (node->parent == NULL || node->right != NULL) 
  {
    return leftMostChild(node->right);
  } else {
    while (par = node->parent) {
      if (par->left == node)
        break;
      node = parent;
    }
    return par;
  }
}

Node_t* leftMostChild(Node_t* node) {
  if (!node)
    return NULL;
  // C language passes by value.
  while(node->left)
    node = node->left;
  return node;
}
*/


int main() {
	Node_t* root = NULL;
	insert(5, &root);
	insert(2, &root);
	insert(6, &root);
	insert(4, &root);
	insert(7, &root);
  insert(1, &root);
	in_order(root);
  printf("MAX Depth = %d\nMIN Depth = %d\n", maxdepth(root), mindepth(root));
	Node_t* index = search(2, root);
	printf("index (2) = %d\n", index->val);
  printf("------------------\n");
//	delete(2, &root);
	in_order(root);

  printf("Test isChild.\n");
  int key;
  for (key  = 0; key < 10; key++) {
    Node_t* node = search(key, root);
    if (isChild(root, node)) 
      printf("Node %d exists \n", key);
    else 
      printf("Node %d does not exist\n", key);
  }
  printf("Test leastCommonAncestor\n");
  Node_t* node1 = search(1, root);
  Node_t* node2 = search(4, root);
  Node_t* node3 = leastCommonAncestor2(root, node1, node2);
  printf("Ancestor for Node 1 and Node 4 is Node %d\n",
  node3->val);
  node2 = search(7, root);
  node3 = leastCommonAncestor2(root, node1, node2);

  printf("Ancestor for Node 1 and Node 7 is Node %d\n",
  node3->val);
  
  
  return 0;
}



