    while(prev->data != right){
        prev = curr;
        curr = curr->next;
        curr->next = prev;
    }