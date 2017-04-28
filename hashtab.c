#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MUL 50
#define HASH_SIZE 500

unsigned int hashtab_hash(char *key){
    unsigned int h = 0;
    char *p;

    for (p = key; *p != '\0'; p++){
        h = h * HASH_MUL + (unsigned int)*p;
    }
    return h%HASH_SIZE;
}

void hashtab_init(struct table **hashtab){
    int i;

    for (i = 0; i < HASH_SIZE; i++){
        hashtab[i] = NULL;
    }
}

void hashtab_add(struct table **hashtab, char *key, int value){
    struct table *node;

    int index = hashtab_hash(key);
    node = malloc(sizeof(*node));
    if (node != NULL){
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}

struct table *hashtab_lookup(struct table **hashtab, char *key){
    int index;
    struct table *node;

    index = hashtab_hash(key);
    for (node = hashtab[index]; node != NULL; node = node->next){
        if (strcmp(node->key, key) == 0)
            return node;
     }
     return NULL;
}


void hashtab_delete(struct table **hashtab, char *key)
{
    int index;
    struct table *p, *prev = NULL;

    index = hashtab_hash(key);
    for (p = hashtab[index]; p != NULL; p = p->next){
        if (strcmp(p->key, key) == 0){
            if (prev == NULL)
                hashtab[index] = p->next;
            else prev->next = p->next;
            free(p);
            return;
         }
         prev = p;
      }
}
























