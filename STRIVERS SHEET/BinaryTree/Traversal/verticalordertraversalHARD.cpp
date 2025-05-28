class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     queue<pair<TreeNode*,pair<int,int>>> q;
     map<int,vector<pair<int,int>>> mpp;      //col->{row,val}
     q.push({root,{0,0}});
     vector<vector<int>> ans;
     while(!q.empty()){
     auto it=q.front();
     TreeNode* node=it.first;
     int row=it.second.first;
     int col=it.second.second;
     mpp[col].push_back({row,node->val});
     q.pop();
    if(node->left) q.push({node->left,{row+1,col-1}});      //node,row,col
    if(node->right) q.push({node->right,{row+1,col+1}});
     }


    for(auto& [col,vec]:mpp){
      sort(vec.begin(),vec.end());       //3,15
      vector<int> colvals;
     for(auto& [row,val]:vec){
        colvals.push_back(val);           //push 3 then push 15
     }
     ans.push_back(colvals);                              //now push [3,15] to ans
    }

return ans;
    }
};