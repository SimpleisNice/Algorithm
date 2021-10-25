#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> treeInfo;

typedef struct TreeNode
{
    int level;
    int data;
    struct TreeNode *lNode;
    struct TreeNode *rNode;
} TreeNode;

TreeNode *findNode(TreeNode *treeNode, const int key)
{
    TreeNode *tempTree = treeNode;
    if (tempTree == NULL)
        return NULL;
    if (tempTree->data == key)
        return tempTree;

    TreeNode *lNode = findNode(tempTree->lNode, key);
    if (lNode != NULL)
        return lNode;
    TreeNode *rNode = findNode(tempTree->rNode, key);
    if (rNode != NULL)
        return rNode;
}
void insertNode(TreeNode *treeNode, const int key, const int pos)
{
    TreeNode *tempNode = new TreeNode();
    tempNode->data = key;
    tempNode->level = treeNode->level + 1;
    treeInfo.push_back(make_pair(tempNode->level, tempNode->data));

    if (pos == 0)
        treeNode->rNode = tempNode;
    else
        treeNode->lNode = tempNode;
}
int main(void)
{
    int level;
    cin >> level;

    TreeNode *rootNode = new TreeNode();

    for (int i = 0; i < 3; ++i)
    {
        int tempData;
        cin >> tempData;

        if (tempData == -1)
            continue;

        if (i == 0)
        {
            rootNode->data = tempData;
            rootNode->level = 1;
        }
        else
        {
            insertNode(rootNode, tempData, i / 2);
        }
    }

    TreeNode *tempTree = NULL;
    for (int i = 1; i < level; ++i)
    {
        int tempData;
        cin >> tempData;

        tempTree = findNode(rootNode, tempData);

        for (int j = 1; j < 3; ++j)
        {
            cin >> tempData;
            if (tempData == -1)
                continue;
            insertNode(tempTree, tempData, j / 2);
        }
    }

    int longLength = 0;
    // 각각의 위치는 어떻게 배치할 것인가?
    if (treeInfo.size() >= 2)
    {
        int curLevel = treeInfo[0].first;
        int startIndex = 0;
        sort(treeInfo.begin(), treeInfo.end());
        for (int i = 1; i < treeInfo.size(); ++i)
        {
            if(curLevel != treeInfo[i].first) {
                longLength = max(longLength, treeInfo[i - 1].second - treeInfo[startIndex].second);
                startIndex = i;
                curLevel = treeInfo[i].first;
            }
        }
        longLength = max(longLength, )
    }
    return 0;
}