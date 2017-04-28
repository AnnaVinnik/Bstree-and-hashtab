#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include "hashtab.h"
#include <locale.h>
#include <sys/time.h>

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
int i, w, n = 50000;
double time_bin, time_hash, t;
char k[n][30], b;


FILE *f, *f2;
    f = fopen("text.txt", "r");
    f2 = fopen("text2.txt", "a");

    for (i = 0; i < n; i++){
    fscanf(f, "%s", k[i]);
    }

//Заполнение бинарного дерева
    t = wtime();
    struct bstree *tree = bstree_create("k[0]", 0);
    
    for (i = 0; i < n; i++)
    bstree_add(tree, k[i], i);
    t = wtime() - t;

//Поиск по бинарному дереву 
    w = getrand(0, n);

    time_bin = wtime();
    struct bstree *temp = bstree_lookup(tree, k[w]);
    time_bin = wtime() - time_bin;

//Заполнение хеш-таблицы
    struct table *hashtab[n];

    hashtab_init(hashtab);

    for (i = 0; i < n; i++)
    hashtab_add(hashtab, k[i], i);


//Поиск по хеш-таблице
    w = getrand(0, n);

    time_hash = wtime();
    struct table *temp = hashtab_lookup(hashtab, k[w]);
    time_hash = wtime() - time_hash;

//Вывод результатов
printf("%s \n", temp->key);
    printf("n: %d time: %.6f \n ", n, time_hash);
    fprintf(f2, "n: %d time: %f \n", n, time_hash);


fclose (f);
fclose (f2);

return 0;
}
