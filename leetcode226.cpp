TreeNode* invertTree(TreeNode* root) {
    
    if(nullptr == root) return root;
    
    queue<TreeNode*> myQueue;   // our queue to do BFS
    myQueue.push(root);         // push very first item - root

    while(!myQueue.empty()){    // run until there are nodes in the queue 
        
        TreeNode *node = myQueue.front();  // get element from queue
        myQueue.pop();                     // remove element from queue
                 
        if(node->left != nullptr){         // add left kid to the queue if it exists
            myQueue.push(node->left);
        }
        
        if(node->right != nullptr){        // add right kid 
            myQueue.push(node->right);
        }
        
        // invert left and right pointers      
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;

    }

    return root;
}