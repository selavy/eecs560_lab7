#include "hash_linear.h"

static int hash(int val) {
  return val % TBL_SZ;
}

hash_tbl * hash_init() {
  hash_tbl * tbl = malloc(sizeof(*tbl));
  if(!tbl) return NULL;
  memset(&(tbl->tbl), 0, sizeof(int) * TBL_SZ);
  return tbl;
}

int hash_insert(hash_tbl * tbl, int val) {
  int loc, counter = 0;
  for(loc = hash(val); (tbl->tbl[loc] > EMPTY) && (counter < TBL_SZ); ++counter, loc = (loc + 1) % TBL_SZ);

  if(counter >= TBL_SZ) return -1;
  else {
    tbl->tbl[loc] = val;
    return 0;
  }
}

int hash_remove(hash_tbl * tbl, int val) {
  int loc, counter = 0;
  for(loc = hash(val); (tbl->tbl[loc] != val) && (tbl->tbl[loc] != EMPTY) && (counter < TBL_SZ); ++counter, loc = (loc + 1) % TBL_SZ);

  if(counter >= TBL_SZ) return -1;
  else {
    tbl->tbl[loc] = REMOVED;
  }
  return 0;
}

void hash_print(hash_tbl * tbl) {
  int i;
  for(i = 0; i < TBL_SZ; ++i)
    printf("%d ", tbl->tbl[i]);
}

void hash_finalize(hash_tbl ** tbl) {
  if(*tbl) free(*tbl);
  *tbl = NULL;
}
