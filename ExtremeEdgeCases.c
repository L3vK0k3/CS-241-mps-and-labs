#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int* helper(int count, char * temp){
	int* res=calloc(sizeof(int), count);
	int curIndex=0, curLen=0;
	while(*temp){
		if(*temp=='.'){curIndex++; curLen=0;}
		else if(isalpha(*temp)) curLen++;
		res[curIndex]=curLen;
		temp++;
	}
	return res;
}

int numSentences(char* temp){
	int count=1;
	//count is one index for the null byte :)
	while(*temp){if(*temp=='.') count++;temp++;}
	return count;
}
char **camel_caser(char* input){
	int n = strlen(input);
	int count = numSentences(input);
	char ** res = calloc(sizeof(char*), count+1);
	int *state = helper(count, input);
	for(int i=0; i<count; i++){
		res[i]=calloc(sizeof(char), state[i]+1);
	}
	free(state); //memory leak
	char * temp = input;
	int curSentence=0, curLen=0, makeNextCharUpperCase=1, beginningOfSentence=1;
	while(*temp){
		if(*temp=='.'){ 
			curSentence++; 
			curLen=0;
			makeNextCharUpperCase=1; beginningOfSentence=1;
		}
		else if(ispunct(*temp)){
			//do nothing
		}
		else if(isspace(*temp)) makeNextCharUpperCase=1;
		else{
			if(beginningOfSentence || makeNextCharUpperCase==0){
				res[curSentence][curLen++]=tolower(*temp);
			}
			else{
				res[curSentence][curLen++]=toupper(*temp);
			}
			beginningOfSentence=makeNextCharUpperCase=0;
		}
		temp++;
	}
	return res;
}

int main(){
	char* test1= calloc(5000, sizeof(char));
	strcpy(test1,"The Heisenbug is an incredible creature. Facenovel servers get their power from its indeterminism. Code smell can be ignored with INCREDIBLE use of air freshener. God objects are the new religion.");
	char ** res = camel_caser(test1);
	while(*res){
		printf("%s\n", (*res));
		res++;
	}
	free(test1);
	return 1;
}