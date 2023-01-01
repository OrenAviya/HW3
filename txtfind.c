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

//getting the next word from the buffer, starting from 'index'
int getword(char* buffer , int *index , char* w){
    int count = 0;
    char c = buffer[*index];

//    while (c == ' ' || c == '\t' || c == '\n'){
//        (*index)++;
//        c = *(buffer + (*index));
//    }

    do {
        c = buffer[*index];
        w[count] = c;
        (*index)++;
        count++;
    } while ( c != ' ' && c != '\t' && c != '\n' && count < WORD);
    w[count -1] = '\0';
    return count;
}

int getLine(char *buffer , int * index, char *line){
 int count = 0;
    char c = ' ';
    do {
        c = *( buffer + (*index) );
        *(line + count) = c;
        (*index)++;
        count++;
    } while (  c != '\n' && count < LINE);
    line[count] = '\0';
    return count;
}

// return 1 if its able
int similar (char * s, char* t, int n){
    int len_s = (int) strlen(s);
    if(n == 0 || ( len_s == strlen(t) ) ){
        if(strcmp(s,t) == 0 ){
            return 1;
        }
        return 0;
    }

    char copy [len_s];
    // lop for removing each char in s at the time and return recursive call without it.
    for(int position = 0; position < len_s; position++){
        strcpy(copy , s);
        // remove the char in position index in copy
        for(int i = position + 1; i < len_s; i++){
            copy[i - 1]  = copy[i];
        }
        copy[len_s - 1] = '\0';
        //recursive call with the new string (copy , t, n-1)
        if(similar(copy,t,n-1) == 1){
            return 1;
        }
    }
    return 0;
}
int isWordInLine(char * line, char* word){

    if( substring(line,word,0,0, (int)strlen(line), (int)strlen(word)) == 1){
        return 1;
    }
return 0;
}

int main(){
    char keyword[WORD] = "";
    char flagArr [2] = "";
    char buffer[MAX_FILE_LENGTH];
    int index = 0;
    int endIndex = 0;
    int scan = '0';

    // Read from the standard input stream until the end of file
    while ((scan = getchar()) != EOF)
    {
        printf("%c",(char)scan);
        buffer[endIndex] = (char)scan;
        endIndex++;
    }
    unsigned long length = strlen(buffer);
    //getting the first word from the buffer
    getword(buffer , &index , keyword);
    printf("keyword: %s\n", keyword );
    //getting a' or 'b', to chose what to print (in string format)
    getword(buffer , &index , flagArr);
    char flag = flagArr[0];
    printf("flag: %c\n",flag);

    while (index < length) {
        //printing all the lines in the text with the key-word.
        if (flag == 'a') {
            char line [LINE] = "";
            getLine(buffer, &index, line);
            if (isWordInLine(line, keyword)) {
                printf("%s", line);
            }

            //printing all the word in the text that similar to the key word or have only one letter extra than the key word.
        } else {
            char word [WORD] = "";
            getword(buffer, &index, word);
            if( similar(word , keyword , 1) ){
                printf("%s\n" , word);
            }

        }
    }
}








