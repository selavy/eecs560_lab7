#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LINEAR
#include "hash_linear.h"
#else
#include "hash_quad.h"
#endif


#define STR_MAX 256

int main(int argc, char **argv) {
  FILE * pData;
  FILE * pCmds;
  char szCommand[STR_MAX];
  hash_tbl * tbl;

  if(argc < 3) {
    fprintf(stderr, "Usage: %s [DATA FILE] [CMD FILE]\n", argv[0]);
    exit (1);
  }

  pData = fopen(argv[1], "r");
  pCmds = fopen(argv[2], "r");
  if(!pData || !pCmds) {
    perror("fopen");
    fclose(pData);
    fclose(pCmds);
    exit (1);
  }

  tbl = hash_init();

  while(fgets(szCommand, STR_MAX, pData)) {
    int val = atoi(szCommand);
    if(val > 0) {
      hash_insert(tbl, val);
    }
  }

  fclose(pData);  

  while(fgets(szCommand, STR_MAX, pCmds)) {
    char * tok = strtok(szCommand, " ");
    if(*tok == 'i') {
      int val;
      tok = strtok(NULL, " ");
      val = atoi(tok);
      if(val > 0) {
	printf("INSERTING %d\n", val);
	if(-1 == hash_insert(tbl, val) ) perror("hash_insert");
      }
    } else if(*tok == 'd') {
      int val;
      tok = strtok(NULL, " ");
      val = atoi(tok);
      if(val > 0) {
	printf("REMOVING %d\n", val);
	if(-1 == hash_remove(tbl, val) ) perror("hash_remove");
      }
    } else if(*tok == 'p') {
      printf("TABLE: ");
      hash_print(tbl);
      printf("\n");
    }
  }

  fclose(pCmds);

  hash_print(tbl); printf("\n");


  return 0;
}
