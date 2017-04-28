#ifndef BSTREE_H
#define BSTREE_H

struct bstree{
	int value;
	char *key;
	struct bstree *parent;
	struct bstree *right;
	struct bstree *left;
};

struct bstree *bstree_create(char *key, int value);
void bstree_add(struct bstree *tree, char *key, int value);
struct bstree *bstree_lookup(struct bstree *tree, char *key);
struct bstree *bstree_min(struct bstree *tree);

#endif
