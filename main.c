#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bstree.h"
#include "hashtab.h"
#include <locale.h>
#include <sys/time.h>
#include "inttypes.h"
#define n 50000

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}


int main()
{
uint32_t ex6;
int i, j, w, collis_kp = 0, collis_djb = 0;
unsigned int hash[n], hash_djb[n];
double time_bin, time_hash, t;
char k[n][30] = {}, b;


FILE *f, *f2;
    f = fopen("text.txt", "r");
    f2 = fopen("text2.txt", "a");

    for (i = 0; i < n; i++){
    fscanf(f, "%s", k[i]);
    }

//Заполнение бинарного дерева
    /*t = wtime();
    struct bstree *tree = bstree_create("k[0]", 0);
    
    for (i = 0; i < n; i++)
    bstree_add(tree, k[i], i);
    t = wtime() - t;

//Поиск по бинарному дереву 
    w = getrand(0, n);

    time_bin = wtime();
    struct bstree *temp = bstree_lookup(tree, k[n-1]);
    time_bin = wtime() - time_bin;*/

//Заполнение хеш-таблицы KP

   struct table *hashtab[100];

    hashtab_init(hashtab);

    for (i = 0; i < n; i++)
    hashtab_add(hashtab, k[i], i);


//Поиск по хеш-таблице KP
    w = getrand(0, n - 1);

    time_hash = wtime();
    struct table *temp = hashtab_lookup(hashtab, k[n-1]);
    time_hash = wtime() - time_hash;
fprintf(f2, "Time of lookup KP for %d = %f; \t", n, time_hash);

//Вывод результатов
    /*printf("%s \n", temp->key);
    printf("n: %d time: %.6f \n ", n, time_bin);
    fprintf(f2, "n: %d time: %f \n", n, time_bin);*/


//Хеш таблица DJB
    for (i = 0; i < n; i++){
        hashtab_djb_add(hashtab, k[i], i);
    }

    w = getrand(1, 5000);
t = wtime();
struct table *lookup = hashtab_djb_lookup(hashtab, k[w]);
t = wtime() - t;
fprintf(f2, "DJB for %d = %f \n", n, t);

//Collision KP
for (i = 0; i < n; i++){
    hash[i] = hashtab_hash(k[i]);
}


for (i = 0; i < n; i++){
    for (j = 0; j < i; j ++){
        if (hash[i] == hash[j]){
            collis_kp = collis_kp + 1;
            break;
        }     
    }
}

   fprintf(f2, "Collision in kp: %d; \t", collis_kp); 

//Collision DJB
for (i = 0; i < n; i++){
    hash_djb[i] = hashtab_djb_hash(k[i]);
}


for (i = 0; i < n; i++){
    for (j = 0; j < i; j++){
        if (hash_djb[i] == hash_djb[j]){
            collis_djb = collis_djb + 1;
            break;
        }
    }
}
   fprintf(f2, "in DJB: %d \n", collis_djb); 

fclose (f);
fclose (f2);

   return 0;

}
