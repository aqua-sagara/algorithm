#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *right;
	char key;
	struct node *left;
	int deletion;
};
typedef struct node * NodePointer;

void treeinitialize(void);
NodePointer makenode(char c);
void treeinsert_r(char c, NodePointer p);
void preorder(NodePointer node);
void inorder(NodePointer node);
void postorder(NodePointer node);
void treedelete(char c);

NodePointer head, tail;

int main(){
	char c;

	treeinitialize();

	printf("INPUT DATA:  ");
	while (1){
		c = getchar();
		if (c == '\n'){
			break;
		}
		treeinsert_r(c, head);
	}

	/* トラバース */
	printf("inorder:  ");
	inorder(head->right);
	printf("\n");
	printf("DELETE: ");
	c = getchar();
	treedelete(c);


	return 0;
}

void treeinitialize(void){
	head = makenode(-1);
	tail = makenode(-1);
	head->right = tail;
	head->left = tail;
}

/*
* ノードを作成し、そのノードへのポインタを返す。
*/
NodePointer makenode(char c){
	NodePointer x;

	x = malloc(sizeof(struct node));
	x->key = c;
	x->right = tail;
	x->left = tail;

	return x;
}

void treeinsert_r(char c, NodePointer p){
	p->deletion = 0;
	if (p->key>c){
		if (p->left == tail){
			p->left = makenode(c);
		}
		if (p->left != tail){
			treeinsert_r(c, p->left);
		}
	}
	if (p->key<c){
		if (p->right == tail){
			p->right = makenode(c);
		}
		if (p->right != tail){
			treeinsert_r(c, p->right);
		}

	}



}
void treedelete(char c){
	NodePointer node;
	int i = 0;
	if (i ==0){
		node = head->right;
	}i++;

	inorder(node->left);
	if (node->key == c){
		node->deletion = 1;
	}
	inorder(node->right);

	
}

void preorder(NodePointer node){
	if (node != tail){
		printf("%c ", node->key);
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(NodePointer node){
	if (node != tail){
		inorder(node->left);
		if (node->deletion = 0);
		printf("%c ", node->key);
		inorder(node->right);
	}
}

void postorder(NodePointer node){
	if (node != tail){
		postorder(node->left);
		postorder(node->right);
		printf("%c ", node->key);
	}
}
