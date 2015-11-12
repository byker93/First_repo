#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "hangman.h"

int getWord(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int isWordGuessed(const char secret[], const char lettersGuessed[]) {
	 int char_match = 0;
	 for (int i=0; i<(sizeof(lettersGuessed)/sizeof(char)); i++){
		for (int j=0; j<(sizeof(secret)/sizeof(char)); j++){
			if (secret[j] == lettersGuessed[i]) char_match++;
		}
	 }
	 if (char_match >= (sizeof(secret)/sizeof(char)))
		return 1;
	 else
		return 0;
}

void getGuessedWord(const char secret[], const char lettersGuessed[], char guessedWord[]){

}
