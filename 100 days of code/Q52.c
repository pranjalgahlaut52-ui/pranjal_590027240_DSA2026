#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Build tree from level order (-1 = NULL)
TreeNode* buildTree(vector<int> &arr) {
    if (arr.size() == 0 || arr[0] == -1)
        return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Find LCA in Binary Tree
TreeNode* LCA(TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->val == p || root->val == q)
        return root;

    TreeNode* left = LCA(root->left, p, q);
    TreeNode* right = LCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int p, q;
    cin >> p >> q;

    TreeNode* root = buildTree(arr);

    TreeNode* ans = LCA(root, p, q);

    cout << ans->val << endl;

    return 0;
}