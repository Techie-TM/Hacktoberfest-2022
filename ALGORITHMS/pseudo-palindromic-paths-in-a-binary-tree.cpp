class Solution {
public:
    void solution(map<int,int> c,int *p,TreeNode* root){
        if(!root->left&&!root->right){
            c[root->val]+=1;
            int z=0;
            for(auto x:c){
                if (x.second%2!=0)z+=1;
            }
            if(z>1)
            return;
            else{
                *p=*p+1;
                return;
            }
        }
        c[root->val]+=1;
        if(root->left)
        solution(c,p,root->left);
        if(root->right)
        solution(c,p,root->right);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> c;
        int p=0;
        solution(c,&p,root);
        return p;
    }
};
// Alternate way (Less Memory)
class Solution {
public:
    map<int,int> c;
    void solution(int *p,TreeNode* root){
        if(!root)return;
        c[root->val]+=1;
        if(!root->left&&!root->right){
            int z=0;
            for(int i=0;i<=9;i++){
                if(c[i]%2!=0)z+=1;
            }
            if(z<=1){
                *p=*p+1;
            }
        }
        solution(p,root->left);
        solution(p,root->right);
        c[root->val]-=1;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int p=0;
        solution(&p,root);
        return p;
    }
};
