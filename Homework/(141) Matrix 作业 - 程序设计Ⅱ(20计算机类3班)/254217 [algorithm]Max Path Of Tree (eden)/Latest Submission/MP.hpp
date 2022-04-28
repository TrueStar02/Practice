namespace MP{};
struct TreeNode
{   int val;// the weight of this node.
    int id; // the id of this node.
    TreeNode *left, *right; //the pointers to left-child and right-child of this node.
    TreeNode(int x, int i):val(x),id(i),left(NULL),right(NULL){}
};
 class MaxPath {
private:
    int max;
    int cur;
    void traverse(TreeNode * tn);
public:
    MaxPath() : max(0) {}
    int findMaxPath(TreeNode *root)
    {   max=0;
        cur=0;
        traverse(root);
        return max;
    }
};
void MaxPath::traverse(TreeNode * tn)
{   cur+=tn->val;
    if(cur>max)
        max=cur;
    if(tn->left!=NULL)
        traverse(tn->left);
    if(tn->right!=NULL)
        traverse(tn->right);
    cur-=tn->val;

}
