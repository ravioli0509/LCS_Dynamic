#include "lps.h"
#include "lcs.h"
#include "utility.h"


/*
 * EnterFor__() --> usual user input
 * if a function name has Output in it, then it leads to writing output to file
 * 
 * Most of the functions are duplicates 
*/

void LPS(char pali[], int len){
    //does the LPS with reverse sequence
    char c[10001];
    int n = 0;
    for ( int i = 0; i < len; i ++){
        c[i] = pali[len - i - 1];
    }
    n = strlen(c);
    LCS(pali, c, len, n, 2);
}

void LCPS(char pali[], int len){
    // did the hazel's algorithm
    char c[10001];
    int n = 0;
    for ( int i = 0; i < len; i ++){
        c[i] = pali[len - i - 1];
    }
    n = strlen(c);
    LCS(pali, c, len, n, 5);
}

void LCPSForOutput(char pali[], int len){
    // did the hazel's algorithm
    char c[10001];
    int n = 0;
    for ( int i = 0; i < len; i ++){
        c[i] = pali[len - i - 1];
    }
    n = strlen(c);
    LCS(pali, c, len, n, 12);
}

void LPSOutputResult(char pali[], int len){
    // duplicate function, but it outputs to the textfiles.
    char c[10001];
    int n = 0;
    for ( int i = 0; i < len; i ++){
        c[i] = pali[len - i - 1];
    }
    n = strlen(c);
    LCS(pali, c, len, n, 8);
}


void EnterForLPS(){
    // entering 1 sequence for LPS
    int len;
    printf("Enter a sequence for LPS: ");
    char pali[10001];
    fgets(pali,10001,stdin);
    len = strlen(pali);
    LPS(pali, len);
}

void EnterForLPSOutput(){
    // enetering 1 sequence for LPS (leads to writing into the textfile)
    int len;
    printf("Enter a sequence for LPS: ");
    char pali[10001];
    fgets(pali,10001,stdin);
    len = strlen(pali);
    LPSOutputResult(pali, len);

}

