#ifndef _GENERAL_
#define _GENERAL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TBL_SZ 29
#define EMPTY 0
#define REMOVED -1

typedef struct {
  int tbl[TBL_SZ];
} hash_tbl;
  
extern hash_tbl * hash_init();
extern int hash_insert(hash_tbl *, int);
extern int hash_remove(hash_tbl *, int);
extern void hash_print(hash_tbl *);
extern void hash_finalize(hash_tbl**);

#endif
