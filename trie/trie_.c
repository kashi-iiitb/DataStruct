#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
struct trieNode{
	struct trieNode* next[ALPHABET_SIZE];
	bool endOfWord;
};

struct trieNode* getNode(){
	struct trieNode* temp = (struct trieNode*)malloc(sizeof(struct trieNode));
	if(!temp){
		perror("error: getNode()");
		exit(1);
	}
	for(int i=0; i<ALPHABET_SIZE; i++)
		temp->next[i] = NULL;
	temp->endOfWord = false;
	return temp;
}

void insert(struct trieNode* root, char* str){
	printf("inside %s\n",__FUNCTION__);
//	if(root==NULL)
//		root=getNode();
	char *cur = str;
	while(*cur!=NULL){
		printf("inside while processing %c\n",*cur);
		if(root->next[*cur-'a']==NULL){
			root->next[*cur-'a']=getNode();
			
		}
		
		root=root->next[*cur-'a'];
		cur++;
	}
	if(root->endOfWord!=true)
		root->endOfWord = true;
}

bool find(struct trieNode* root, char *str){
	char *instr = str;
	struct trieNode* cur = root;
	while((*instr) && (cur->next[*instr-'a']!=NULL)) {
		cur = cur->next[*instr-'a'];
		instr++;
	}
	if(cur!=NULL)
		return cur->endOfWord;

}
void main(){
	struct trieNode* root = getNode();
	insert(root, "kashi");
	insert(root, "hello");
	insert(root, "sneha");
	if(find(root,"mallik")==true)
		printf("string found\n");
	else
		printf("string not found\n");

}
