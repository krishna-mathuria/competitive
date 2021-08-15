    void insert_last(int element)
    {
        DQueNode* temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;
 
        // if element is the first element
        if (head == NULL) {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }
 
    void remove_last()
    {
        // if list is not empty
        if (!isEmpty()) {
            DQueNode* temp = tail;
            tail = tail->prev;
            if(tail) tail->next = NULL;
            delete temp;
            if(tail == NULL) head = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }

class Stack : public Deque {
public:

    void push(int element)
    {
        insert_last(element);
    }
 
    void pop()
    {
        remove_last();
    }
};
 