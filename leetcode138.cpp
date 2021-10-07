class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* root=head;
        while(root!=NULL){
            Node* temp = new Node(root->val);
            temp->next = root->next;
            root->next = temp;
            root = root->next->next;
        }
        root = head;
        while(root!=NULL){
            if(root->next!=NULL)
                root->next->random = root->random ? root->random->next : root->random;
            root = root->next ?  root->next->next : root->next;
        }
        Node* original = head, * copy = head->next;
        Node *temp = copy;
        root=head;
        while(original && copy){
            original->next = original->next ? original->next->next : original->next;
            original = original->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            copy = copy->next;
        }
        return temp;
    }
};