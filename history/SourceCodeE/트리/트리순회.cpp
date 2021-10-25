#include <iostream>

using namespace std;

typedef struct TreeNode {
	char data;
	struct TreeNode * rightNode;
	struct TreeNode * leftNode;
} TreeNode;

void insertNode(TreeNode * treeNode, const char data, const int pos) {
	TreeNode * newNode = new TreeNode();
	newNode->data = data;

	if (pos == 0)
		treeNode->leftNode = newNode;
	else
		treeNode->rightNode = newNode;

}
TreeNode * findNode(TreeNode * treeNode, const char data) {
	TreeNode * tempTree = treeNode;
	if (tempTree == NULL)
		return NULL;
	if (tempTree->data == data)
		return tempTree;

	TreeNode * lTree = findNode(tempTree->leftNode, data);
	if (lTree != NULL)
		return lTree;

	TreeNode * rTree = findNode(tempTree->rightNode, data);
	if (rTree != NULL)
		return rTree;

	return NULL;
}

void printPreorder(TreeNode * treeNode) {
	TreeNode * tempNode = treeNode;

	cout << tempNode->data;

	if (tempNode->leftNode != NULL)
		printPreorder(tempNode->leftNode);

	if (tempNode->rightNode != NULL)
		printPreorder(tempNode->rightNode);
}
void printInorder(TreeNode * treeNode) {
	TreeNode * tempNode = treeNode;

	if (tempNode->leftNode != NULL)
		printInorder(tempNode->leftNode);

	cout << tempNode->data;

	if (tempNode->rightNode != NULL)
		printInorder(tempNode->rightNode);
}
void printPostorder(TreeNode * treeNode) {
	TreeNode * tempNode = treeNode;

	if (tempNode->leftNode != NULL)
		printPostorder(tempNode->leftNode);

	if (tempNode->rightNode != NULL)
		printPostorder(tempNode->rightNode);

	cout << tempNode->data;
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int level;
	cin >> level;

	TreeNode * rootNode = new TreeNode();
	char tempChar = ' ';
	for (int i = 0; i < 3; ++i) {
		cin >> tempChar;
		if (i == 0) {
			rootNode->data = tempChar;
		}
		else {
			if (tempChar == '.')
				continue;
			insertNode(rootNode, tempChar, i / 2);
		}
	}

	for (int i = 1; i < level; ++i) {
		cin >> tempChar;
		TreeNode * tempTree = findNode(rootNode, tempChar);
		for (int j = 1; j < 3; ++j) {
			cin >> tempChar;
			if (tempChar == '.')
				continue;
			insertNode(tempTree, tempChar, j / 2);
		}
	}

	printPreorder(rootNode); cout << "\n";
	printInorder(rootNode); cout << "\n";
	printPostorder(rootNode);
	return 0;
}