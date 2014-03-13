#include <stdio.h>
#include <stdlib.h>

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
    printf("%s", szCommand);
    if(val > 0) {
      hash_insert(&tbl, val);
    }
  }

  hash_print(tbl); printf("\n");
  
  fclose(pData);
  fclose(pCmds);
  return 0;
}
