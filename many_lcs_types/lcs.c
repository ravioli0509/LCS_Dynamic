#include "lcs.h"
#include "lps.h"
#include "lts.h"
#include "main.h"

/*
Includes all the needed functions for LCS
Includes all prompt functios for LCPS and LCTS (not much of differences)
Includes condition integers that will lead to different results and answer statements based on command arguments. 
*/


int FindMaxFromTable(int a, int b) {
  // finding max from table
  return (a > b)? a : b;
}

void LCS(char s1[], char s2[], int m, int n, int cond) {
  // usual LCS algorithm from the previous assignments 
  // Added condition integers to print out different answers for different cases 
  // example for LPS --> LCS(---, ---, ---, ---, 1) so in if cond == 1, the answer statement for LPS prints out
  // this condition is also differentiated by whether if it outputs into file
  int L[m + 1][n + 1];
  int s1_num, s2_num, len_of_LCS;
  int lcs_calls = 0;
  for(s1_num = 0; s1_num <= m ; s1_num++) {

    for(s2_num = 0; s2_num <= n; s2_num++) {
      int g = s1_num - 1;
      int h = s2_num - 1;
      if(s1_num == 0 || s2_num == 0) 
      {

        L[s1_num][s2_num] = 0;

      } else if(s1[g] == s2[h]) {

        L[s1_num][s2_num] = L[g][h] + 1;

      } else {

        L[s1_num][s2_num] = FindMaxFromTable(L[g][s2_num], L[s1_num][h]);
      }
    }
    lcs_calls = lcs_calls + 1;
  }

  s1_num = m;
  s2_num = n;
  len_of_LCS = L[s1_num][s2_num];
  char LCS[len_of_LCS+1];
  LCS[len_of_LCS] = '\0';

  while(s1_num > 0 && s2_num > 0) {

    if(s1[s1_num - 1] == s2[s2_num - 1]) {

      LCS[len_of_LCS - 1] = s1[s1_num - 1];

      len_of_LCS = len_of_LCS - 1;
      s1_num = s1_num - 1;
      s2_num = s2_num - 1;

    } else if(L[s1_num - 1][s2_num] > L[s1_num][s2_num - 1]) {

      s1_num = s1_num - 1;

    } else {

      s2_num = s2_num - 1;

    }
  }

  // condition situtaion applies here
  if (cond == 1){
    printf("LCS (length = %d) for the seqeuence(s) is:\n", L[m][n]);
    printf("%s\n", LCS);
  }
  if (cond == 2){
    printf("LPS (length = %d) for the seqeuence(s) is:\n", L[m][n]);
    printf("%s\n", LCS);
  }  
  if (cond == 3){
    printf("LTS (length = %d) for the seqeuence(s) is:\n", 2*L[m][n]);
    printf("%s%s\n",LCS,LCS);
  }  
  if (cond == 4){
    LCPS(LCS, L[m][n]);
  }
  if (cond == 5){
    printf("LCPS (length = %d) for the seqeuence(s) is:\n", L[m][n]);
    printf("%s\n", LCS);
  }  
  if (cond == 6){
    LCTS(LCS, L[m][n]);
  }
  if (cond == 7){
    printf("LCTS (length = %d) for the seqeuence(s) is:\n", L[m][n]);
    printf("%s\n", LCS);
  } 
  if (cond == 8){
    printf("LPS (length = %d) for the seqeuence(s) is:\n", L[m][n]);
    printf("%s\n", LCS);
    FILE  *fptr;
    fptr = fopen(file,"a");
    if(fptr != NULL){     
        fprintf(fptr,"LPS: %s\n",LCS);
        fclose(fptr);
        printf("Successfully appended data to file.\n");
    }
  }
  if (cond == 9){
    printf("LTS (length = %d) for the seqeuence(s) is:\n", 2*L[m][n]);
    printf("%s%s\n",LCS,LCS);
    FILE  *fptr;
    fptr = fopen(file,"a");
    if(fptr != NULL){
        fprintf(fptr,"LTS: %s%s\n",LCS,LCS);
        fclose(fptr);
        printf("\nSuccessfully appended data to file.\n");
    }
  }

  if (cond == 10){
    printf("LCS (length = %d) for the seqeuence(s) is:\n", L[m][n]);
    printf("%s\n", LCS);
    FILE  *fptr;
    fptr = fopen(file,"a");
    if(fptr != NULL){
        fprintf(fptr,"LCS: %s\n",LCS);
        fclose(fptr);
        printf("\nSuccessfully appended data to file.\n");
    }
  }
  if (cond == 11){
    LCPSForOutput(LCS, L[m][n]);
  }
  if (cond == 12){
    printf("LCPS (length = %d) for the seqeuence(s) is:\n", L[m][n]);
    printf("%s\n", LCS);
    FILE  *fptr;
    fptr = fopen(file,"a");
    if(fptr != NULL){
        fprintf(fptr,"LCPS: %s\n",LCS);
        fclose(fptr);
        printf("\nSuccessfully appended data to file.\n");
    }
  }

  if (cond == 13){
    LCTSForOutput(LCS, L[m][n]);
  }
  if (cond == 14){
    printf("LCTS (length = %d) for the seqeuence(s) is:\n", L[m][n]);
    printf("%s\n", LCS);
    FILE  *fptr;
    fptr = fopen(file,"a");
    if(fptr != NULL){
        fprintf(fptr,"LCTS: %s\n",LCS);
        fclose(fptr);
        printf("\nSuccessfully appended data to file.\n");
    }
  }
}

// ------ From here its the prompt functions for LCS, LCTS, LCPS, and duplicates that leads to output into fie

void EnterForLCS(){
  char s1[1002], s2[1002];
      int a = 0, b = 0;
      s1[a] = '\0'; 
      s2[b] = '\0'; 
      int n=0, m=0, i=0, j=0, num=0;
      while (num == 0){
        int error_s1 = 0;
        int error_s2 = 0;
        printf("To Compute LCS enter two sequences\n");

        printf("Enter the first sequence: ");
        fgets(s1,1002, stdin);        
        for (i = 0; i < strlen(s1)-1; i++){
            if (isdigit(s1[i]) == 0){ //use of isdigit
                error_s1 = 1;
                break;
            }else{
                error_s1 = 0;
            }
        }
        if (error_s1 == 1){ // prints error message if error = 1
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }    
        
        printf("Enter the second sequence: ");
        fgets(s2,1002,stdin);   

        for (j = 0; j < strlen(s2)-1; j++){
            if (isdigit(s2[j]) == 0){
                error_s2 = 1;
                break;
            }else{
                error_s2 = 0;
            }
        }
        if (error_s2 == 1){
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }  

        if (error_s1 == 0 && error_s2 == 0){ //breaks out of while loop if error = 0
            num = 1;
        }else{
            num = 0;
            continue;
        }      
      }
      m = strlen(s1);
      n = strlen(s2);
      LCS(s1, s2, m, n, 1);
}

void EnterForLCSOutput(){
  char s1[1002], s2[1002];
      int a = 0, b = 0;
      s1[a] = '\0'; 
      s2[b] = '\0'; 
      int n=0, m=0, i=0, j=0, num=0;
      while (num == 0){
        int error_s1 = 0;
        int error_s2 = 0;
        printf("To Compute LCS enter two sequences\n");

        printf("Enter the first sequence: ");
        fgets(s1,1002, stdin);        
        for (i = 0; i < strlen(s1)-1; i++){
            if (isdigit(s1[i]) == 0){ //use of isdigit
                error_s1 = 1;
                break;
            }else{
                error_s1 = 0;
            }
        }
        if (error_s1 == 1){ // prints error message if error = 1
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }    
        
        printf("Enter the second sequence: ");
        fgets(s2,1002,stdin);   

        for (j = 0; j < strlen(s2)-1; j++){
            if (isdigit(s2[j]) == 0){
                error_s2 = 1;
                break;
            }else{
                error_s2 = 0;
            }
        }
        if (error_s2 == 1){
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }  

        if (error_s1 == 0 && error_s2 == 0){ //breaks out of while loop if error = 0
            num = 1;
        }else{
            num = 0;
            continue;
        }      
      }
      m = strlen(s1);
      n = strlen(s2);
      LCS(s1, s2, m, n, 10);
}

int returnLCSLength(char s1[], char s2[], int m, int n) {
  int L[m + 1][n + 1];
  int s1_num, s2_num, len_of_LCS;
  int lcs_calls = 0;
  for(s1_num = 0; s1_num <= m ; s1_num++) {

    for(s2_num = 0; s2_num <= n; s2_num++) {
      int g = s1_num - 1;
      int h = s2_num - 1;
      if(s1_num == 0 || s2_num == 0) 
      {

        L[s1_num][s2_num] = 0;

      } else if(s1[g] == s2[h]) {

        L[s1_num][s2_num] = L[g][h] + 1;

      } else {

        L[s1_num][s2_num] = FindMaxFromTable(L[g][s2_num], L[s1_num][h]);
      }
    }
    lcs_calls = lcs_calls + 1;
  }

  s1_num = m;
  s2_num = n;
  len_of_LCS = L[s1_num][s2_num];
  char LCS[len_of_LCS+1];
  LCS[len_of_LCS] = '\0';

  while(s1_num > 0 && s2_num > 0) {

    if(s1[s1_num - 1] == s2[s2_num - 1]) {

      LCS[len_of_LCS - 1] = s1[s1_num - 1];

      len_of_LCS = len_of_LCS - 1;
      s1_num = s1_num - 1;
      s2_num = s2_num - 1;

    } else if(L[s1_num - 1][s2_num] > L[s1_num][s2_num - 1]) {

      s1_num = s1_num - 1;

    } else {

      s2_num = s2_num - 1;

    }
  }

  return L[m][n]-1;
}

void EnterForLCPS(){
  char s1[1002], s2[1002];
      int a = 0, b = 0;
      s1[a] = '\0'; 
      s2[b] = '\0'; 
      int n=0, m=0, i=0, j=0, num=0;
      while (num == 0){
        int error_s1 = 0;
        int error_s2 = 0;
        printf("To Compute LCPS enter two sequences\n");

        printf("Enter the first sequence: ");
        fgets(s1,1002, stdin);        
        for (i = 0; i < strlen(s1)-1; i++){
            if (isdigit(s1[i]) == 0){ //use of isdigit
                error_s1 = 1;
                break;
            }else{
                error_s1 = 0;
            }
        }
        if (error_s1 == 1){ // prints error message if error = 1
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }    
        
        printf("Enter the second sequence: ");
        fgets(s2,1002,stdin);   

        for (j = 0; j < strlen(s2)-1; j++){
            if (isdigit(s2[j]) == 0){
                error_s2 = 1;
                break;
            }else{
                error_s2 = 0;
            }
        }
        if (error_s2 == 1){
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }  

        if (error_s1 == 0 && error_s2 == 0){ //breaks out of while loop if error = 0
            num = 1;
        }else{
            num = 0;
            continue;
        }      
      }
      m = strlen(s1);
      n = strlen(s2);
      LCS(s1, s2, m, n, 4);
}

void EnterForLCPSOutput(){
  char s1[1002], s2[1002];
      int a = 0, b = 0;
      s1[a] = '\0'; 
      s2[b] = '\0'; 
      int n=0, m=0, i=0, j=0, num=0;
      while (num == 0){
        int error_s1 = 0;
        int error_s2 = 0;
        printf("To Compute LCPS enter two sequences\n");

        printf("Enter the first sequence: ");
        fgets(s1,1002, stdin);        
        for (i = 0; i < strlen(s1)-1; i++){
            if (isdigit(s1[i]) == 0){ //use of isdigit
                error_s1 = 1;
                break;
            }else{
                error_s1 = 0;
            }
        }
        if (error_s1 == 1){ // prints error message if error = 1
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }    
        
        printf("Enter the second sequence: ");
        fgets(s2,1002,stdin);   

        for (j = 0; j < strlen(s2)-1; j++){
            if (isdigit(s2[j]) == 0){
                error_s2 = 1;
                break;
            }else{
                error_s2 = 0;
            }
        }
        if (error_s2 == 1){
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }  

        if (error_s1 == 0 && error_s2 == 0){ //breaks out of while loop if error = 0
            num = 1;
        }else{
            num = 0;
            continue;
        }      
      }
      m = strlen(s1);
      n = strlen(s2);
      LCS(s1, s2, m, n, 11);
}

void EnterForLCTS(){
  char s1[1002], s2[1002];
      int a = 0, b = 0;
      s1[a] = '\0'; 
      s2[b] = '\0'; 
      int n=0, m=0, i=0, j=0, num=0;
      while (num == 0){
        int error_s1 = 0;
        int error_s2 = 0;
        printf("To Compute LCTS enter two sequences\n");

        printf("Enter the first sequence: ");
        fgets(s1,1002, stdin);        
        for (i = 0; i < strlen(s1)-1; i++){
            if (isdigit(s1[i]) == 0){ //use of isdigit
                error_s1 = 1;
                break;
            }else{
                error_s1 = 0;
            }
        }
        if (error_s1 == 1){ // prints error message if error = 1
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }    
        
        printf("Enter the second sequence: ");
        fgets(s2,1002,stdin);   

        for (j = 0; j < strlen(s2)-1; j++){
            if (isdigit(s2[j]) == 0){
                error_s2 = 1;
                break;
            }else{
                error_s2 = 0;
            }
        }
        if (error_s2 == 1){
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }  

        if (error_s1 == 0 && error_s2 == 0){ //breaks out of while loop if error = 0
            num = 1;
        }else{
            num = 0;
            continue;
        }      
      }
      m = strlen(s1);
      n = strlen(s2);
      LCS(s1, s2, m, n, 6);
}

void EnterForLCTSOutput(){
  char s1[1002], s2[1002];
      int a = 0, b = 0;
      s1[a] = '\0'; 
      s2[b] = '\0'; 
      int n=0, m=0, i=0, j=0, num=0;
      while (num == 0){
        int error_s1 = 0;
        int error_s2 = 0;
        printf("To Compute LCTS enter two sequences\n");

        printf("Enter the first sequence: ");
        fgets(s1,1002, stdin);        
        for (i = 0; i < strlen(s1)-1; i++){
            if (isdigit(s1[i]) == 0){ //use of isdigit
                error_s1 = 1;
                break;
            }else{
                error_s1 = 0;
            }
        }
        if (error_s1 == 1){ // prints error message if error = 1
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }    
        
        printf("Enter the second sequence: ");
        fgets(s2,1002,stdin);   

        for (j = 0; j < strlen(s2)-1; j++){
            if (isdigit(s2[j]) == 0){
                error_s2 = 1;
                break;
            }else{
                error_s2 = 0;
            }
        }
        if (error_s2 == 1){
            printf("\nError! Non-digit character detected!\n\n");
            continue;
        }  

        if (error_s1 == 0 && error_s2 == 0){ //breaks out of while loop if error = 0
            num = 1;
        }else{
            num = 0;
            continue;
        }      
      }
      m = strlen(s1);
      n = strlen(s2);
      LCS(s1, s2, m, n, 13);
}
