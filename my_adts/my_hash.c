#include "my_hash.h"

/*
 * ensure the hash table size of prime
 * if the H_SIZE is large, keys distribution not equitable 
*/
INDEX hash(char *key, unsigned int H_SIZE)
{
    unsigned int hash_val = 0;
    while (*key != '\0') hash_val += *key++;
    return (hash_val % H_SIZE);
}

/*
 * 27 charactors, 729 is 27^2
 * if input is ramdome, keys distribution is equivable
 * but, English is not ramdome, different combinations are only 2851
 * it is not good if the hash table size is large
*/
INDEX hash(char *key, unsigned int H_SIZE)
{
    return ((key[0] + 27*key[1] + 729*key[2]) % H_SIZE);
}


/*
 * k1 + 27k2 + 27^2 * k3 + 27^3 * K4
 * use 32 instead of 27 for fast multiplication
 * exponent calculation by Horner's rule
 * expect to distribute well
 * disadvantage: if the characters long, take too long time for calculation
 * optimal: select left part of the string, e.g., for addr. select part of street, city, zip code intead of all.
*/
INDEX hash(char *key, unsigned int H_SIZE)
{
    unsigned int hash_val = 0;
    while (*key != '\0') hash_val = (hash_val << 5) + *key++;
    return (hash_val % H_SIZE);
}

/*
 * collision resolve
 * open hashing - seperate chaining
 * load factor = ratio of number of element to table size
 * factor = 1 is best.
 * best practice: let tale size as prime to esure a good distribution.
 */
typedef int element_type;
struct list_node;
typedef struct list_node *node_ptr;
struct list_node
{
    element_type element;
    node_ptr next;
};
typedef node_ptr LIST;
typedef node_ptr position;

struct hash_tbl
{
    unsigned int table_size;
    LIST *the_lists;
};
typedef struct hash_tbl *HASH_TABLE;

HASH_TABLE initialize_table(unsigned int table_size)
{
    HASH_TABLE H;
    int i;
    H = (HASH_TABLE)malloc(sizeof(struct hash_tbl));
    H->table_size = next_prime(table_size);
    H->the_lists = (LIST*)malloc(sizeof(LIST)*H->table_size);
    for (i = 0; i < H->table_size; i++)
    {
        H->the_lists[i] = (LIST)malloc(sizeof(struct list_node));
        H->the_lists[i]->next = NULL;
    }
    return H;
}

position find(element_type key, HASH_TABLE H)
{
    position p;
    LIST L;
    L = H->the_lists[hash(key, H->table_size)];
    p = L->next;
    while (p != NULL && p->element != key) p = p->next;
    return p;
}

void insert(element_type key, HASH_TABLE H)
{
    position pos, new_cell;
    LIST L;
    pos = find(key, H);
    if (pos != NULL) return;
    new_cell = (position)malloc(sizeof(struct list_node));
    L = H->the_lists[hash(key, H->table_size)];
    new_cell->next = L->next;
    new_cell->element = key;
    L->next = new_cell;
}

/*
 * collision resolve
 * close hashing - open addressing
 * load factor should be below 0.5
 */
enum kind_of_entry {legitimate, empty, deteted};

struct hash_entry
{
	element_type element;
	enum kind_of_entry info;
}	

typedef INDEX position;
typedef struct hash_entry cell;

struct hash_tbl
{
	unsigned int table_size;
	cell *the_cells;
}

typedef struct hash_tbl *HASH_TABLE;

HASH_TABLE initialize_table(unsigned int table_size)
{
	int i;
	HASH_TABLE H;
	H = (HASH_TABLE)malloc(sizeof(struct hash_tbl));
	H->table_size = next_prime(table_size);
	H->the_cells = (cell*)malloc(sizeof(cell) * H->table_size);
	for (i = 0; i < H->table_size; i++)
	{
		H->the_cells[i].info = empty;
	}
	return H;
}	

position find(element_type key, HASH_TABLE H)
{
	position i, current_pos;
	i = 0;
	current_pos = hash(key, H->table_size);
	while (H->the_cells[current_pos].element != key &&
		   H->the_cells[current_pos].info != empty)
	{
		current_pos += 2*(++i) - 1;
		if (current_pos >= H->table_size) current_pos -= table_size;
	}
	return current_pos;
}

void insert(element_type key, HASH_TABLE H)
{
	position pos;
	pos = find(key, H);
	if (H->the_cells[pos].info != legitimate)
	{
		H->the_cells[pos].info = legitimate;
		H->the_cells[pos].element = key;
	}
}


/*
 * reflashing
*/
HASH_TABLE rehash(HASH_TABLE H)
{
	unsigned int i, old_size;
	cell *old_cells;
	old_cells = H->the_cells;
	old_size = H->table_size;
	H = initialize_table(2*old_size);
	for (i = 0; i < old_size; i++)
	{
		if (old_cells[i].info == legitimate)
		{
			insert(old_cells[i].element, H);
		}
	}
	free (old_cells);
	return H;
}

/*
* use cases of hash
* 1. compiler
* 2. graph theory problem
* 3. games, recording moves of each position
* 4. spelling checker
* 5. puzzle problem
*/






