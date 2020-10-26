#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* fin = fopen("letters.txt", "r");

  // Read A
  char** L0 = calloc(4, sizeof(char*));
  for(int i = 0; i < 4; i++) {
    L0[i] = calloc(7, sizeof(char));
  }
  for(int i = 0; i < 4;i++) {
    for(int j = 0; j < 7; j++) {
      L0[i][j] = fgetc(fin);
    }
    while(fgetc(fin) != '\n') { }
  }

  // Read N
  char** L1 = calloc(4, sizeof(char*));
  for(int i = 0; i < 4; i++) {
    L1[i] = calloc(7, sizeof(char));
  }
  for(int i = 0; i < 4;i++) {
    for(int j = 0; j < 7; j++) {
      L1[i][j] = fgetc(fin);
    }
    while(fgetc(fin) != '\n') { }
  }

  // Read V
  char** L2= calloc(4, sizeof(char*));
  for(int i = 0; i < 4; i++) {
    L2[i] = calloc(7, sizeof(char));
  }
  for(int i = 0; i < 4;i++) {
    for(int j = 0; j < 7; j++) {
      L2[i][j] = fgetc(fin);
    }
    while(fgetc(fin) != '\n') { }
  }

  // Read Y
  char** L3 = calloc(4, sizeof(char*));
  for(int i = 0; i < 4; i++) {
    L3[i] = calloc(7, sizeof(char));
  }
  for(int i = 0; i < 4;i++) {
    for(int j = 0; j < 7; j++) {
      L3[i][j] = fgetc(fin);
    }
    while(fgetc(fin) != '\n') { }
  }

  // Print N
  for(int i = 0; i < 4;i++) {
    for(int j = 0; j < 7; j++) {
      printf("%c", L1[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Print A
  for(int i = 0; i < 4;i++)
  {
    for(int j = 0; j < 7; j++) {
      printf("%c", L0[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Print V
  for(int i = 0; i < 4;i++)
  {
    for(int j = 0; j < 7; j++) {
      printf("%c", L2[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // Print Y
  for(int i = 0; i < 4;i++)
  {
    for(int j = 0; j < 7; j++) {
      printf("%c", L3[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 4; i++) {
    free(L0[i]);
  }
  free(L0);

  for (int i = 0; i < 4; i++) {
    free(L1[i]);
  }
  free(L1);

  for (int i = 0; i < 4; i++) {
    free(L2[i]);
  }
  free(L2);

  for (int i = 0; i < 4; i++) {
    free(L3[i]);
  }
  free(L3);

  fclose(fin);

  return 0;
}
