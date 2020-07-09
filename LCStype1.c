/**
* This is assignment 1, finding the LCS of two sequences. 
* Algorithm in function LCS and finding max was referenced on https://www.dyclassroom.com/dynamic-programming/longest-common-subsequence
* Henceforth I credit this website for the use of dynamic programming in fucntion LCS.
* Insights were shared with Rubin, Rachel, and Hyunseo as collaborators.
* student ID: 1553439 CCID: nawalage
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int FindMaxFromTable(int a, int b);
void LCS(char s1[], char s2[], int m, int n);

int FindMaxFromTable(int a, int b) {
  return (a > b)? a : b;
}

void LCS(char s1[], char s2[], int m, int n) {

  int L[m + 1][n + 1];
  int s1_num, s2_num, len_of_LCS;
  int lcs_calls = 0;
 for(s1_num = 0; s1_num <= m ; s1_num++) {

    for(s2_num = 0; s2_num <= n; s2_num++) {
      int g = s1_num - 1;
      int h = s2_num - 1;
      if(s1_num == 0 || s2_num == 0) // #1
      {

        L[s1_num][s2_num] = 0;

      } else if(s1[g] == s2[h]) { // #2

        L[s1_num][s2_num] = L[g][h] + 1;

      } else { // #3

        L[s1_num][s2_num] = FindMaxFromTable(L[g][s2_num], L[s1_num][h]);
      }
    }
    lcs_calls = lcs_calls + 1;
  }

  
  s1_num = m;
  s2_num = n;
  len_of_LCS = L[s1_num][s2_num];
  char LCS[len_of_LCS+1];
  LCS[len_of_LCS] = '\0'; // we set null character at the end of string, to show the end of array

  while(s1_num > 0 && s2_num > 0) {

    if(s1[s1_num - 1] == s2[s2_num - 1]) { // #4

      LCS[len_of_LCS - 1] = s1[s1_num - 1];

      len_of_LCS = len_of_LCS - 1;
      s1_num = s1_num - 1;
      s2_num = s2_num - 1;

    } else if(L[s1_num - 1][s2_num] > L[s1_num][s2_num - 1]) { // #5

      s1_num = s1_num - 1;

    } else {

      s2_num = s2_num - 1;

    }
  }
  if (L[m][n]-1 == 0 ){ //#6
    printf("# an LCS (length = %d) is:\n", L[m][n]-1);
    printf("\nTotal LCS calls is 0, because of existing empty sequence(s)!\n");
  } else {
    printf("# an LCS (length = %d) is:\n", L[m][n]-1);
    printf("%s\n", LCS);
    printf("Total LCS calls: %d\n", lcs_calls);
  }

}

int main(void) {
    /**
    * In the main function, where prompts validations are set, I've used a technique to find if the sequence has a non digit, which is uding isdigit()
    * I also added a simple true or false for both errors in error_s1 and error_s2. 
    * If theres any error in a sequence, error_s1(or s2) counter becomes 1, which the error means true. As long as error_s1 or error_s2 is one, 
    * the while loop never breaks (num == 0). As the program continues in the while loop, it will eventually go back from the start with error_s1 and 
    * error_s2 being back to 0. 
    * 
    * If both error_s1 and error_s2 are still 0 at the end of while loop. A if statement is there to change num to 1, so that way the while loop breaks 
    * and proceeds into the lcs.
    */
    char s1[1001], s2[1001];
    int a = 0, b = 0;
    s1[a] = '\0'; // we set null character at the end of string, to show the end of array
    s2[b] = '\0'; // same as above
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
    printf("\n# Two input sequences (length = %d, %d) are:\n", m-1, n-1);
    printf("%s", s1);
    printf("%s\n", s2);   
    LCS(s1, s2, m, n);

  return 0;
}