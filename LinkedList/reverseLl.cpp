ListNode ReverseList(ListNode* node){
    if(node==NULL) return NULL;
    if(node-<next==NULL) return node;
    ListNode* node1=ReverseList(node->next);
    node->next->next;=node;
    node->next=NULL;
    return node1;
}
