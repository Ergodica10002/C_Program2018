#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct treenode{
	char value[35];
	struct treenode* left;
	struct treenode* right;
}treenode;
char expression[1000];
treenode* insert(treenode* root){
	if (root == NULL){
		root = (treenode*)malloc(sizeof(treenode));
		root->left = root->right = NULL;
	}
	char c[35];
	scanf("%s", c);
	if (c[0] == '('){
		scanf("%s", c);
		strcpy(root->value, c);
		root->left = insert(root->left);
		root->right = insert(root->right);
		scanf("%s", c);
		return root;
	}
	if (c[0] == ')')
		return root;
	strcpy(root->value, c);
	root->left = root->right = NULL;
	return root;
}
void replace(treenode* root, char* var, char* indicate){
	if (root == NULL)
		return;
	replace(root->left, var, indicate);
	if (strcmp(root->value, var) == 0){
		strcpy(root->value, indicate);
	} 
	replace(root->right, var, indicate);
	return;
}
void printtree(treenode* root){
	if (root == NULL)
		return;
	printtree(root->left);
	printf("%s ", root->value);
	printtree(root->right);
	return;
}
int answer(treenode* root){
	if (root->value[0] == '+'){
		return answer(root->left) + answer(root->right);
	}
	if (root->value[0] == '-'){
		return answer(root->left) - answer(root->right);
	}
	if (root->value[0] == '*'){
		return answer(root->left) * answer(root->right);
	}
	if (root->value[0] == '/'){
		return answer(root->left) / answer(root->right);
	}
	int i = 0, num = 0;
	int nextvalue = root->value[i] - '0';
	while (nextvalue >= 0 && nextvalue <= 9){
		num = num * 10 + nextvalue;
		i++;
		nextvalue = root->value[i] - '0';
	}
	return num;
}
int main(void)
{
	treenode* root = NULL;
	root = insert(root);
//	printtree(root);
//	printf("\n");
	char var[35];
	char op[3];
	char indicate[35];
	while (scanf("%s %s %s", var, op, indicate) != EOF){
	//	printf("var = %s indicate = %s\n", var, indicate);
		replace(root, var, indicate);
	//	printtree(root);
	}
//	printtree(root);
	printf("%d\n", answer(root));	
	return 0;
}

