char **array;
array= malloc(10*sizeof(char *));
for (int i=0; i<10; i++) {
    array[i]= malloc(10);
}
free(array);        // nope. You should do:

for (int i=0; i<10; i++) {
    free(array[i]);
}
free(array);
