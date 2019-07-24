#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#define size (26)

struct TrieNode{

struct TrieNode  *children[size];
bool end;


};
struct TrieNode *getNode(void)
{
                //printf("1\n");

 struct TrieNode *parent =NULL;
 parent=(struct TrieNode *)malloc(sizeof (struct TrieNode));
 if(parent)
 {
                 //printf("2\n");

     parent->end=false;
     for (int i=0;i<size;i++)
     {
         parent->children[i]=NULL;
     }
 }
    return parent;
}



void insert(struct TrieNode *root, char *key)
{
    struct TrieNode* temp=root;
            //printf("4\n");

    while(*key!='\0')
    {
        if(temp->children[*key -'a']==NULL)
            temp->children[*key-'a']= getNode();
        temp=temp->children[*key-'a'];
        key++;
        //printf("5\n");
    }
    temp->end=true;
}



void print_remaining(struct TrieNode* root,char* str,char* copy,int level=0)
{
	//printf("6\n");
	if(root->end)
		{
			printf("%s",copy);
			str[level]='\0';
			puts(str);
			//printf("\n");
			//return;
		}
		
	int i;	
	for(int i=0;i<size;i++)
		{
			//printf("7\n");
			if(root->children[i])
			{
				str[level]= i+'a'; 
				print_remaining(root->children[i],str,copy,level+1);
			}
		}
}


void word_complete(struct TrieNode* root,char *word)
{	
	int c=0;
	struct TrieNode* temp=root;
	char* copy=word;
	int j=0;
	while(*word)
	{
		for (int i=0;i<size;i++)
		{
			
			if(temp->children[i])
			{
				
				if(temp->children[i] == temp->children[*word-'a'])
				{
					++word;
					temp=temp->children[i];
					break;
				}
			}
			else
			{
				
				if(i==25)
				{
					c=1;
					++word;
					break;
					//printf("asdfghjkl\n");
				}
			}
			
		}
		
			
	}
	
	if(c==1)
	{
		printf("Word doesn't exists\n");
	}
	else
	{
		char str[30];
		print_remaining(temp,str,copy);
	
	}
	
}




int main()
{
struct TrieNode*root=getNode();
            //printf("3\n");

    //insert(root,"yash");

//passing the file    
char ch,file_name[20]={"dict1.txt"};
FILE *fp;
fp=fopen(file_name,"r");

if(fp==NULL)
{
	printf("ERROR IN READING THE FILE\n");
	exit(EXIT_FAILURE);
}

char str[30];
/*while(fgets(str,30,fp) != NULL)
{
	insert(root,str);
	printf("%s",str);
}*/
while(!feof(fp))
{
	fscanf(fp,"%s",str);
	insert(root,str);
	//printf("%s",str);
}
fclose(fp); 

printf("Enter here\n");
char word[30];
scanf("%s",word);
word_complete(root,word);
    //word=(char*)malloc(sizeof(char));
   
return 0;
}










