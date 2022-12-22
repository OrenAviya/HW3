//
// Created by alon on 12/18/22.
//

#include "txtfind.h"

// return 1 if str2 is substring of str1;
int substring(char *str1, char *str2, int start1, int start2, int end1 , int end2) {
    if (end1 < start1 || end2 < start2) {
        return 0;
    }

    if(((end1- start1) == (end2 - start2))) {
        int startCopy1 = start1;
        int startCopy2 = start2;
        int isEqual = 1;

        while (startCopy1 < end1 && startCopy2 < end2 && isEqual) {
            if (*(str1 + startCopy1) != *(str2 + startCopy2)) {
                isEqual = 0;
            }
            startCopy2++;
            startCopy1++;
        }
        if (isEqual == 1) {
            return 1;
        }
    }
    if (substring(str1, str2, start1 + 1, start2, end1, end2) ||
        substring(str1, str2, start1, start2, end1 - 1, end2)) {
        return 1;
    }
    return 0;

}
int getword(char* w){
    // char w[WORD] ={0};
    int count = 0;
    char scan = ' ';
    do {
        scanf("%c",&scan);
        *(w + count) = scan;
        count++;
    } while ( scan != ' ' && scan != '\t' && scan != '\n' && count < WORD);
    w[count - 1] = '\0';
    return count;
}
    int main(){
        char arr[WORD];
        getword(arr);
        printf("%s\n",arr);
        getword(arr);
        printf("%s\n",arr);
        return 1;
        }




