#include "lts.h"
#include "lcs.h"

/*For LTS algorithm
1st time -- s1 = {1} s2 = {234567891}  LCS_length LCS 
2nd time -- s1 = {12} s2 = {34567891}
3rd time -- s1 = {123} s2 = {4567891}
4th time -- s1 = {1234} s2 = {567891}
5th time -- s1 = {12345} s2 = {67891} LCS_length from splitAinHalf function
6th time -- s1 = {123456} s2 = {7891}
7th time -- s1 = {1234567} s2 = {891}
8th time -- s1 = {12345678} s2 = {91}
9th time -- s1 = {123456789} s2 = {1}
 * 
 * 
 * 
 * EnterFor__() --> usual user input 
 * if a function name has Output in it, then it leads to writing output to file
 * 
 * Most of the functions are duplicates 
*/

void EnterForLTS(){
    // enetering one sequence for lts
    int len;
    printf("Enter a sequence for LTS: ");
    char tand[10001];
    fgets(tand,10001,stdin);
    len = strlen(tand);
    LTS(tand, len);
}

void EnterForLTSOutput(){
  // same as above but leads to write into text file
    int len;
    printf("Enter a sequence for LTS: ");
    char tand[10001];
    fgets(tand,10001,stdin);
    len = strlen(tand);
    LTSOutputResult(tand, len);
}

void LTS(char tand[], int len){
  //LTS algorithm explained above
  int lts;
  int update_length = 0;
  int temp = 0;
  for(int j = 1; j < len; j++){
    int a = j;
    int b = len - j;
    lts = returnLCSLength(&tand[0], &tand[j], a, b);
    if (lts > update_length){
      update_length = lts;
      temp = j;
    }
  }  
  char s1[10001];
  char s2[10001];
  for (int i = 0; i < temp; i++){
    s1[i] = tand[i];
  }
  for (int i = 0; i < len - temp; i++){
    s2[i] = tand[i];
  }
  int c = strlen(s1);
  int d = strlen(s2);
  LCS(s1, s2, c, d, 3);
}

void LCTS(char tand[], int len){
  // did the hazel's algorithm for LCTS
  int lts;
  int update_length = 0;
  int temp = 0;
  for(int j = 1; j < len; j++){
    int a = j;
    int b = len - j;
    lts = returnLCSLength(&tand[0], &tand[j], a, b);
    if (lts > update_length){
      update_length = lts;
      temp = j;
    }
  }  
  char s1[10001];
  char s2[10001];
  for (int i = 0; i < temp; i++){
    s1[i] = tand[i];
  }
  for (int i = 0; i < len - temp; i++){
    s2[i] = tand[i];
  }
  int c = strlen(s1);
  int d = strlen(s2);
  LCS(s1, s2, c, d, 7);
}

void LCTSForOutput(char tand[], int len){
  // did the hazel's algorithm for LCTS
  int lts;
  int update_length = 0;
  int temp = 0;
  for(int j = 1; j < len; j++){
    int a = j;
    int b = len - j;
    lts = returnLCSLength(&tand[0], &tand[j], a, b);
    if (lts > update_length){
      update_length = lts;
      temp = j;
    }
  }  
  char s1[10001];
  char s2[10001];
  for (int i = 0; i < temp; i++){
    s1[i] = tand[i];
  }
  for (int i = 0; i < len - temp; i++){
    s2[i] = tand[i];
  }
  int c = strlen(s1);
  int d = strlen(s2);
  LCS(s1, s2, c, d, 14);
}

void LTSOutputResult(char tand[], int len){
  // duplicate function but leads to writing into the text file.
  int lts;
  int update_length = 0;
  int temp = 0;
  for(int j = 1; j < len; j++){
    int a = j;
    int b = len - j;
    lts = returnLCSLength(&tand[0], &tand[j], a, b);
    if (lts > update_length){
      update_length = lts;
      temp = j;
    }
  }  
  char s1[10001];
  char s2[10001];
  for (int i = 0; i < temp; i++){
    s1[i] = tand[i];
  }
  for (int i = 0; i < len - temp; i++){
    s2[i] = tand[i];
  }
  int c = strlen(s1);
  int d = strlen(s2);
  LCS(s1, s2, c, d, 9);
}