#include "utility.h"

void generatesequence(){
    // generates two sequences by inputing size
    int one, two;
    printf("Enter the size of the first sequence: ");
    scanf("%d",&one); 
    printf("Enter the size of the second sequence: ");
    scanf("%d",&two);
       
    srand((unsigned) time(NULL));
    //dynamically creating two arrays using malloc
    int *arrayOne = malloc(one * sizeof(int));
    int *arrayTwo = malloc(two * sizeof(int));
    if (arrayOne == NULL){
        printf("Fail");
    }
    if (arrayTwo == NULL){
        printf("Fail");
    }
    //two for loops to populate arrays with random numbers
    for (int j = 0; j < one; j++){
        arrayOne[j] = give_random();
    }
    for (int j = 0; j < two; j++){
        arrayTwo[j] = give_random();
    }
    //printing the arrays out
    for (int i = 0; i < one; i++){
        printf("%d", arrayOne[i]);
    }
    printf("\n");
    for (int i = 0; i < two; i++){
        printf("%d", arrayTwo[i]);
    }
    printf("\n");
}

void generatesequenceandfile(char fileName[]){
    // same as above but eventually writes it into file
    int one, two;
    printf("Enter the size of the first sequence: ");
    scanf("%d",&one); 
    printf("Enter the size of the second sequence: ");
    scanf("%d",&two);
       
    srand((unsigned) time(NULL));
    //dynamically creating two arrays using malloc
    int *arrayOne = malloc(one * sizeof(int));
    int *arrayTwo = malloc(two * sizeof(int));
    if (arrayOne == NULL){
        printf("Fail");
    }
    if (arrayTwo == NULL){
        printf("Fail");
    }
    //two for loops to populate arrays with random numbers
    for (int j = 0; j < one; j++){
        arrayOne[j] = give_random();
    }
    for (int j = 0; j < two; j++){
        arrayTwo[j] = give_random();
    }
    //printing the arrays out
    for (int i = 0; i < one; i++){
        printf("%d", arrayOne[i]);
    }
    printf("\n");
    for (int i = 0; i < two; i++){
        printf("%d", arrayTwo[i]);
    }

    FILE  *fptr;
    fptr = fopen(fileName,"w");
    if(fptr != NULL){
        for (int j = 0; j < one; j++){
            fprintf(fptr,"%d",arrayOne[j]);
        }
        fprintf(fptr, "\n");
        for (int j = 0; j < two; j++){
            fprintf(fptr,"%d",arrayTwo[j]);
        }
        fprintf(fptr, "\n");
        fclose(fptr);
    }
    printf("\nSuccessfully appended data to file.\n");
}

int give_random(){
    // random integer function
    int r = rand()%10;
    return r;
}
