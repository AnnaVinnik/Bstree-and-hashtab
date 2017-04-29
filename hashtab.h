#ifndef HASHTAB_H
#define HASHTAB_H


struct table{
	char *key;
	int value;
	struct table *next;
};



unsigned int hashtab_hash(char *key);
void hashtab_init(struct table **hashtab);
void hashtab_add (struct table **hashtab, char *key, int value);
struct table *hashtab_lookup(struct table **hashtab, char *key);
void hashtab_delete(struct table **hashtab, char *key);
uint32_t jenkins_one_at_a_time_hash(const uint8_t* key, size_t length);

#endif
