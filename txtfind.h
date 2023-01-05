//
// Created by alon on 12/18/22.
//

#ifndef HW3_TXTFIND_H
#define HW3_TXTFIND_H

#define LINE 256
#define WORD 30
#define MAX_FILE_LENGTH 64000
int substring(char *str1, char *str2, int start1, int start2, int end1 , int end2);
int getword(char* buffer , int *index , char* w);
int similar (char * s, char* t, int n);
int getLine(char *buffer , int * index, char *line);
int isWordInLine(char * line, char* word);
#include <string.h>
#include <stdio.h>
#endif //HW3_TXTFIND_H
