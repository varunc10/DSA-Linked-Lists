struct Node{
    int val;
    Node* next, *prev;
    Node(){
        val = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
    Node(int x, Node* node1){
        val = x;
        next = node1;
        prev = NULL;
    }
    Node(int x, Node* node1, Node* node2){
        val = x;
        next = node1;
        prev = node2;
    }
};
class MyLinkedList {
public:
    Node* head;
    int len = 0;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(len <= index){
            return -1;
        }
        int n = index;
        Node* curr = head;
        while(n--){
            curr = curr -> next;
        }
        return curr -> val;
    }
    
    void addAtHead(int val) {
        if(len == 0){
            Node* curr = new Node(val);
            head = curr;
            len++; 
        }
        else{
            Node* curr = new Node(val);
            curr -> next = head;
            head -> prev = curr;
            head = curr;
            len++;
        }
    }
    
    void addAtTail(int val) {
        int n = len;
        if(len == 0){
            Node* node = new Node(val);
            head = node;
            len++;
        }
        else{
            Node* curr = head;
            while(n > 1){
                curr = curr -> next;
                n--;
            }
            Node* node = new Node(val);
            curr -> next = node;
            node -> prev = curr;
            len++;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(len < index){
            return;
        }
        int n = index;
        if(len == 0){
            Node* node = new Node(val);
            head = node;
            len++;
        }
        else if(n == 0){
            Node* curr = head;
            Node* node = new Node(val);
            node -> next = curr;
            curr -> prev = node;
            head = node;
            len++;
        }
        else{
            Node* curr = head;
            while(n > 1){
                curr = curr -> next;
                n--;
            }
            Node* node = new Node(val);
            node -> next = curr -> next;
            if(curr -> next){
                curr -> next -> prev = node;
            }
            node -> prev = curr;
            curr -> next = node;
            len++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(len <= index){
            return;
        }
        int n = index;
        Node* curr = head;
        while(n--){
            curr = curr -> next;
        }
        if(curr -> next){
            curr -> next -> prev = curr -> prev;
        }
        if(curr -> prev){
            curr -> prev -> next = curr -> next;
        }
        else if(!curr -> prev){
            head = curr -> next;
        }
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */