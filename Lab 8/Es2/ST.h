#ifndef LAB_8_ST_H
#define LAB_8_ST_H

typedef struct st *ST;

ST STinit(int maxN);
void STfree(ST st);
int STsize(ST st);
int STinsert(ST st, char *str1, char *str2);
char *STsearchByIndiceNome(ST st, int i);
char *STsearchByIndiceRete(ST st, int i);
int STgetindex(ST st, char *name);
void STsort(ST st,int *v);

#endif //LAB_8_ST_H
