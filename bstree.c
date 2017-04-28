#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"



struct bstree *bstree_create(char *key, int value){
	struct bstree *temp = malloc(sizeof(struct bstree));
	if (temp == NULL) return NULL;
	temp->key = key;
	temp->value = value;
	temp->parent = NULL;
	temp->right = NULL;
	temp->left = NULL;

return temp;
}

void bstree_add(struct bstree *tree, char *key, int value){
	if(tree){
		if (value > tree->value){
			if (tree->right == NULL){
				struct bstree *right = bstree_create(key, value);
				right->parent = tree;
				tree->right = right;
				}
			else bstree_add(tree->right, key, value);
			}
		else if (value < tree->value){
			if (tree->left == NULL){
				struct bstree *left = bstree_create(key, value);
				left->parent = tree;
				tree->left = left;
				}
			else bstree_add(tree->left, key, value);
			}
	}
}

struct bstree *bstree_lookup(struct bstree *tree, char *key){
	if (tree){
		if (tree->key == key)
			return tree;

		
		if (tree->left != NULL){
		struct bstree *temp = bstree_lookup(tree->left, key);
		if (temp != NULL)
			return temp;}


		if (tree->right != NULL){
		bstree_lookup(tree->right, key);
			}
		}
	}


struct bstree *bstree_min(struct bstree *tree){
	if (tree->left != NULL) {
	struct bstree *tmp = bstree_min(tree->left);
	return tmp;
	}
	
return tree;

}

struct bstree *bstree_max(struct bstree *tree){
	if (tree->right != NULL){
	struct bstree *tmp = bstree_max(tree->right);
	return tmp;
	}
return tree;


}
