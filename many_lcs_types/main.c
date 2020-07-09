#include "main.h"

/*
ccid : nawalage 

 *the main includes main.h 
 -g for generating sequences 
 -o for outputing it to file
 -c for lcs
 -p for lps
 -t for lts
 -cp for lcps 
 -ct for lcts 

 NOTE: I'm in the A3 section so I have used Hazel's algorithm.

 for outputting it to text file. I have used Enter___Output() 
 * 
 * table of content:
 * functions that doesn't output to file goes to 
 * LCS -> EnterForLCS() (EnterForLCSOutput() for file output with user input)
 * LPS -> EnterForLPS() (EnterForLPSOutput() for file output with user input)
 * LTS -> EnterForLTS() (EnterForLTSOutput() for file output with user input)
 * LCPS -> EnterForLCPS() (EnterForLCPSOutput() for file output with user input)
 * LCTS -> EnterForLCTS() (EnterForLCTSOutput() for file output with user input)
 * 
 * functions that does include output to file goes to 
 * LCS -> (with condition 10 on the end)
 * LPS -> LPSOutputResult()
 * LTS -> LTSOutputResult()
 * LCPS -> LCPSOutputResult() 
 * LCTS -> LCTSOutputResult()
 *
 * for functions that reads input from text file
 * LCS -> (condition 1 or 10) 
 * LPS -> LPS()
 * LTS -> LTS()
 * LCPS -> LCS(condition 4) {condition 11 for -i and -o}
 * LCTS -> LCS(condition 6) {condition 13 for -i and -o}
 *  
 *file reading and outputing referenced from: 
 https://www.programiz.com/c-programming/c-file-input-output
 https://codeforwin.org/2018/02/c-program-append-data-file.html
*/
int main(int agrc, char *argv[]){
  if (agrc <= 1){
    printf("Error, need more arguments\n");
  }
  if(agrc > 1){
    // for arguments with 2 counts ./output -g/-p/-c, etc
    if(agrc == 2){
      if(strcmp(argv[1], "-g") == 0){
        
        printf("Generating sequences\n");
        generatesequence();
      }
      else if(strcmp(argv[1], "-p") == 0){
        EnterForLPS();
      }   
      else if(strcmp(argv[1], "-c") == 0){
        EnterForLCS();
      }
      else if(strcmp(argv[1], "-t") == 0){
        EnterForLTS();
      }
      else if(strcmp(argv[1], "-cp") == 0){
        EnterForLCPS();
      }
      else if(strcmp(argv[1], "-ct") == 0){
        EnterForLCTS();
      }else{
        printf("Invalid arguments\n");
      }
    }

    // for arguments with 3 counts ./output -p -c (other combinations included)
    else if(agrc == 3){
      if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-p") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-p") == 0))){
        EnterForLCS();
        EnterForLPS();
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-t") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-t") == 0))){
        EnterForLCS();
        EnterForLTS();
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-t") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-p") == 0))){
        EnterForLPS();
        EnterForLTS();
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-ct") == 0))){
        EnterForLCS();
        EnterForLCTS();
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-cp") == 0))){
        EnterForLCS();
        EnterForLCPS();
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-p") == 0) || (strcmp(argv[2], "-cp") == 0))){
        EnterForLPS();
        EnterForLCPS();
      }
      else if(((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-cp") == 0))){
        EnterForLTS();
        EnterForLCPS();
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-p") == 0) || (strcmp(argv[2], "-ct") == 0))){
        EnterForLPS();
        EnterForLCTS();
      }
      else if(((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-ct") == 0))){
        EnterForLTS();
        EnterForLCTS();
      }
      else if(((strcmp(argv[1], "-ct") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-cp") == 0) || (strcmp(argv[2], "-ct") == 0))){
        EnterForLCPS();
        EnterForLCTS();
      }else{
        printf("Invalid arguments\n");
      }
    }

    // for arguments with 4 counts ./output -g -o input.txt or ./output -c -o output.txt (other combinations included)
    // and includes file reading (eg. ./output -c -i input.txt ) 
    else if(agrc == 4){
      if(strcmp(argv[1], "-g") == 0){
        if (strcmp(argv[2], "-o") == 0){
          printf("Generating sequences\n");
          generatesequenceandfile(argv[3]);
        }
      }
      else if((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "-o") == 0)){
        file = argv[3];
        EnterForLCSOutput();
      }
      else if((strcmp(argv[1], "-p") == 0) && (strcmp(argv[2], "-o") == 0)){
        file = argv[3];
        EnterForLPSOutput();
      }
      else if((strcmp(argv[1], "-t") == 0) && (strcmp(argv[2], "-o") == 0)){
        file = argv[3];
        EnterForLTSOutput();
      }
      else if((strcmp(argv[1], "-cp") == 0) && (strcmp(argv[2], "-o") == 0)){
        file = argv[3];
        EnterForLCPSOutput();
      }
      else if((strcmp(argv[1], "-ct") == 0) && (strcmp(argv[2], "-o") == 0)){
        file = argv[3];
        EnterForLCTSOutput();
      }
      else if((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "-i") == 0)){
        FILE * fptr;
        input = argv[3];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence: %s", s1);
          printf("Enter Second the Sequence: %s", s2);
          LCS(s1, s2, m, n, 1);
        }
      }
      else if((strcmp(argv[1], "-p") == 0) && (strcmp(argv[2], "-i") == 0)){
        FILE * fptr;
        input = argv[3];
        fptr = fopen(input, "r");
        int n = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
          }
          n = strlen(s1)-1;
          printf("Enter the Sequence: %s", s1);
          LPS(s1, n);
        }
      }
      else if((strcmp(argv[1], "-t") == 0) && (strcmp(argv[2], "-i") == 0)){
        FILE * fptr;
        input = argv[3];
        fptr = fopen(input, "r");
        int n = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
          }
          n = strlen(s1)-1;
          printf("Enter the Sequence: %s", s1);
          LTS(s1, n);
        }
      }
      else if((strcmp(argv[1], "-cp") == 0) && (strcmp(argv[2], "-i") == 0)){
        FILE * fptr;
        input = argv[3];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence: %s", s1);
          printf("Enter Second the Sequence: %s", s2);
          LCS(s1, s2, m, n, 4);
        }
      }
      else if((strcmp(argv[1], "-ct") == 0) && (strcmp(argv[2], "-i") == 0)){ 
        FILE * fptr;
        input = argv[3];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence: %s", s1);
          printf("Enter Second the Sequence: %s", s2);
          LCS(s1, s2, m, n, 6);
        } 
      }else{
        printf("Invalid arguments\n");
      }
    }

    // for arguments with 5 counts ./output -c -p -o output.txt (other combinations included)
    // and includes file reading (eg. ./output -c -p -i input.txt ) 
    else if(agrc == 5){
      if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-p") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-p") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLCSOutput();
        EnterForLPSOutput();
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-t") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-t") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLCSOutput();
        EnterForLTSOutput();
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-t") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-p") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLPSOutput();
        EnterForLTSOutput();
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLCSOutput();
        EnterForLCTSOutput();
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-cp") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLCSOutput();
        EnterForLCPSOutput();
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-p") == 0) || (strcmp(argv[2], "-cp") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLPSOutput();
        EnterForLCPSOutput();
      }
      else if(((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-cp") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLTSOutput();
        EnterForLCPSOutput();
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-p") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLPSOutput();
        EnterForLCTSOutput();
      }
      else if(((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLTSOutput();
        EnterForLCTSOutput();
      }
      else if(((strcmp(argv[1], "-ct") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-cp") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-o") == 0)){
        file = argv[4];
        EnterForLCPSOutput();
        EnterForLCTSOutput();
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-p") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-p") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCS: %s", s1);
          printf("Enter Second the Sequence FOR LCS: %s", s2);
          LCS(s1, s2, m, n, 1);
          printf("Enter the Sequence FOR LPS: %s", s1);
          LPS(s1, n);
        }
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-t") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-t") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCS: %s", s1);
          printf("Enter Second the Sequence FOR LCS: %s", s2);
          LCS(s1, s2, m, n, 1);
          printf("Enter the Sequence FOR LTS: %s", s1);
          LTS(s1, n);
        }
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-t") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-p") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
          }
          n = strlen(s1)-1;
          printf("Enter First the Sequence FOR LPS: %s", s1);
          LPS(s1, n);
          printf("Enter the Sequence FOR LTS: %s", s1);
          LTS(s1, n);
        }
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCS: %s", s1);
          printf("Enter Second the Sequence FOR LCS: %s", s2);
          LCS(s1, s2, m, n, 1);
          printf("Enter First the Sequence FOR LCTS: %s", s1);
          printf("Enter Second the Sequence FOR LCTS: %s", s2);
          LCS(s1, s2, m, n, 6);
        }
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-cp") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCS: %s", s1);
          printf("Enter Second the Sequence FOR LCS: %s", s2);
          LCS(s1, s2, m, n, 1);
          printf("Enter First the Sequence FOR LCPS: %s", s1);
          printf("Enter Second the Sequence FOR LCPS: %s", s2);
          LCS(s1, s2, m, n, 4);
        }
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-p") == 0) || (strcmp(argv[2], "-cp") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LPS: %s", s1);
          LPS(s1, n);
          printf("Enter First the Sequence FOR LCPS: %s", s1);
          printf("Enter Second the Sequence FOR LCPS: %s", s2);
          LCS(s1, s2, m, n, 4);
        }
      }
      else if(((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-cp") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LTS: %s", s1);
          LTS(s1, n);
          printf("Enter First the Sequence FOR LCPS: %s", s1);
          printf("Enter Second the Sequence FOR LCPS: %s", s2);
          LCS(s1, s2, m, n, 4);
        }
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-p") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LPS: %s", s1);
          LPS(s1, n);
          printf("Enter First the Sequence FOR LCTS: %s", s1);
          printf("Enter Second the Sequence FOR LCTS: %s", s2);
          LCS(s1, s2, m, n, 6);
        }
      }
      else if(((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LTS: %s", s1);
          LTS(s1, n);
          printf("Enter First the Sequence FOR LCTS: %s", s1);
          printf("Enter Second the Sequence FOR LCTS: %s", s2);
          LCS(s1, s2, m, n, 6);
        }
      }
      else if(((strcmp(argv[1], "-ct") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-cp") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-i") == 0)){
        FILE * fptr;
        input = argv[4];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCPS: %s", s1);
          printf("Enter Second the Sequence FOR LCPS: %s", s2);
          LCS(s1, s2, m, n, 4);
          printf("Enter First the Sequence FOR LCTS: %s", s1);
          printf("Enter Second the Sequence FOR LCTS: %s", s2);
          LCS(s1, s2, m, n, 6);
        }
      }else{
        printf("Invalid arguments\n");
      }
    }


    // for arguments with 6 counts ./output -c -i input.txt -o output.txt (other combinations included)
    // file reading and file outputing 
    else if(agrc == 6){
      if((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "-i") == 0) && (strcmp(argv[4], "-o") == 0)){
        FILE * fptr;
        input = argv[3];
        file = argv[5];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence: %s", s1);
          printf("Enter Second the Sequence: %s", s2);
          LCS(s1, s2, m, n, 10);
        }
      }
      else if((strcmp(argv[1], "-p") == 0) && (strcmp(argv[2], "-i") == 0) && (strcmp(argv[4], "-o") == 0)){
        FILE * fptr;
        input = argv[3];
        file = argv[5];
        fptr = fopen(input, "r");
        int n = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
          }
          n = strlen(s1)-1;
          printf("Enter the Sequence: %s", s1);
          LPSOutputResult(s1, n);
        }
      }
      else if((strcmp(argv[1], "-t") == 0) && (strcmp(argv[2], "-i") == 0) && (strcmp(argv[4], "-o") == 0)){
        FILE * fptr;
        input = argv[3];
        file = argv[5];
        fptr = fopen(input, "r");
        int n = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
          }
          n = strlen(s1)-1;
          printf("Enter the Sequence: %s", s1);
          LTSOutputResult(s1, n);
        }
      }
      else if((strcmp(argv[1], "-cp") == 0) && (strcmp(argv[2], "-i") == 0) && (strcmp(argv[4], "-o") == 0)){
        FILE * fptr;
        input = argv[3];
        file = argv[5];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence: %s", s1);
          printf("Enter Second the Sequence: %s", s2);
          LCS(s1, s2, m, n, 11);
        }
      }
      else if((strcmp(argv[1], "-ct") == 0) && (strcmp(argv[2], "-i") == 0) && (strcmp(argv[4], "-o") == 0)){ 
        FILE * fptr;
        input = argv[3];
        file = argv[5];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence: %s", s1);
          printf("Enter Second the Sequence: %s", s2);
          LCS(s1, s2, m, n, 13);
        } 
      }else{
        printf("Invalid arguments\n");
      }
    }

    // for arguments with 7 counts ./output -c -p -i input.txt -o output.txt (other combinations included)
    // file reading and file outputing for two sequence sorting
    else if(agrc == 7){
      if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-p") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-p") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0)){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCS: %s", s1);
          printf("Enter Second the Sequence FOR LCS: %s", s2);
          LCS(s1, s2, m, n, 10);
          printf("Enter the Sequence FOR LPS: %s", s1);
          LPSOutputResult(s1, n);
        }
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-t") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-t") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0)){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCS: %s", s1);
          printf("Enter Second the Sequence FOR LCS: %s", s2);
          LCS(s1, s2, m, n, 10);
          printf("Enter the Sequence FOR LTS: %s", s1);
          LTSOutputResult(s1, n);
        }
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-t") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-p") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0)){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
          }
          n = strlen(s1)-1;
          printf("Enter First the Sequence FOR LPS: %s", s1);
          LPSOutputResult(s1, n);
          printf("Enter the Sequence FOR LTS: %s", s1);
          LTSOutputResult(s1, n);
        }
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0) ){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCS: %s", s1);
          printf("Enter Second the Sequence FOR LCS: %s", s2);
          LCS(s1, s2, m, n, 10);
          printf("Enter First the Sequence FOR LCTS: %s", s1);
          printf("Enter Second the Sequence FOR LCTS: %s", s2);
          LCS(s1, s2, m, n, 13);
        }
      }
      else if(((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-c") == 0) || (strcmp(argv[2], "-cp") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0)){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCS: %s", s1);
          printf("Enter Second the Sequence FOR LCS: %s", s2);
          LCS(s1, s2, m, n, 10);
          printf("Enter First the Sequence FOR LCPS: %s", s1);
          printf("Enter Second the Sequence FOR LCPS: %s", s2);
          LCS(s1, s2, m, n, 11);
        }
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-p") == 0) || (strcmp(argv[2], "-cp") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0)){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LPS: %s", s1);
          LPSOutputResult(s1, n);
          printf("Enter First the Sequence FOR LCPS: %s", s1);
          printf("Enter Second the Sequence FOR LCPS: %s", s2);
          LCS(s1, s2, m, n, 11);
        }
      }
      else if(((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-cp") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0)){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LTS: %s", s1);
          LTSOutputResult(s1, n);
          printf("Enter First the Sequence FOR LCPS: %s", s1);
          printf("Enter Second the Sequence FOR LCPS: %s", s2);
          LCS(s1, s2, m, n, 11);
        }
      }
      else if(((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-p") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0)){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LPS: %s", s1);
          LPSOutputResult(s1, n);
          printf("Enter First the Sequence FOR LCTS: %s", s1);
          printf("Enter Second the Sequence FOR LCTS: %s", s2);
          LCS(s1, s2, m, n, 13);
        }
      }
      else if(((strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "-ct") == 0)) && ((strcmp(argv[2], "-t") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0)){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LTS: %s", s1);
          LTSOutputResult(s1, n);
          printf("Enter First the Sequence FOR LCTS: %s", s1);
          printf("Enter Second the Sequence FOR LCTS: %s", s2);
          LCS(s1, s2, m, n, 13);
        }
      }
      else if(((strcmp(argv[1], "-ct") == 0) || (strcmp(argv[1], "-cp") == 0)) && ((strcmp(argv[2], "-cp") == 0) || (strcmp(argv[2], "-ct") == 0)) && (strcmp(argv[3], "-i") == 0) && (strcmp(argv[5], "-o") == 0)){
        FILE * fptr;
        input = argv[4];
        file = argv[6];
        fptr = fopen(input, "r");
        int n = 0, m = 0;
        if (fptr == NULL){
          printf("File doesn't exist\n");
        }else{
          char s1[10001];
          char s2[10001];
          while (!feof(fptr)){
            fgets(s1, 10001, fptr);
            fgets(s2, 10001, fptr);
          }
          m = strlen(s1)-1;
          n = strlen(s2)-1;
          printf("Enter First the Sequence FOR LCPS: %s", s1);
          printf("Enter Second the Sequence FOR LCPS: %s", s2);
          LCS(s1, s2, m, n, 11);
          printf("Enter First the Sequence FOR LCTS: %s", s1);
          printf("Enter Second the Sequence FOR LCTS: %s", s2);
          LCS(s1, s2, m, n, 13);
        }
      }else{
      printf("Invalid arguments\n");
    }
  }
  }
}