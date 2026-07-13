template<typename T>
Node<T>::Node(T val) : value(val), next(NULL) {}

template<typename T>
Node<T>::~Node(){}

template<typename T>
Linkedlist<T>::Linkedlist(){
    head = NULL;
    tail = NULL;
    count = 0;
}

template<typename T>
void Linkedlist<T>::push(T& val){
    Node<T>* temp = (Node<T>*)malloc(sizeof(Node<T>));
    new(temp) Node<T>(val);

    if(head == NULL){
        head = temp;
        tail = temp;
        count++;
        return;
    }

    tail->next = temp;
    tail = temp;
    count++;
}

template<typename T>
void Linkedlist<T>::pop(){

    if(head == NULL){
        throw std::underflow_error("underflow");
    }

    if(head == tail){
        head->~Node<T>();
        free(head);
        head = NULL;
        tail = NULL;
        count--;
        return;
    }

    Node<T>* temp = head;

    while(temp->next != tail){
        temp = temp->next;
    }

    Node<T>* last = tail;

    temp->next = NULL;
    tail = temp;

    last->~Node<T>();
    free(last);

    count--;
}

template<typename T>
void Linkedlist<T>::delete_any(T& val){

    Node<T>* ptr = head;
    Node<T>* prev = NULL;

    while(ptr != NULL && ptr->value != val){
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL){
        return;
    }

    if(prev == NULL){

        head = head->next;

        if(ptr == tail)
            tail = NULL;

        ptr->~Node<T>();
        free(ptr);
        count--;
        return;
    }

    prev->next = ptr->next;

    if(ptr == tail)
        tail = prev;

    ptr->~Node<T>();
    free(ptr);

    count--;
}

template<typename T>
Node<T>* Linkedlist<T>::begin() const
{
    return head;
}

template<typename T>
Node<T>* Linkedlist<T>::end() const
{
    return NULL;
}

template<typename T>
int Linkedlist<T>::Size(){
    return count;
}

template<typename T>
bool Linkedlist<T>::isempty(){
    return count == 0;
}

template<typename T>
T& Linkedlist<T>::operator[](int idx){

    if(idx >= count){
        throw std::out_of_range("out of bound");
    }

    Node<T>* temp = head;

    while(idx--){
        temp = temp->next;
    }

    return temp->value;
}

template<typename T>
Linkedlist<T>::Linkedlist(const Linkedlist& ls){

    head = NULL;
    tail = NULL;
    count = 0;

    Node<T>* ptr = ls.head;

    while(ptr != NULL){
        push(ptr->value);
        ptr = ptr->next;
    }
}

template<typename T>
Linkedlist<T>& Linkedlist<T>::operator=(const Linkedlist& ls){

    if(this == &ls)
        return *this;

    Node<T>* temp = head;

    while(temp != NULL){

        Node<T>* nxt = temp->next;

        temp->~Node<T>();
        free(temp);

        temp = nxt;
    }

    head = NULL;
    tail = NULL;
    count = 0;

    Node<T>* ptr = ls.head;

    while(ptr != NULL){

        push(ptr->value);

        ptr = ptr->next;
    }

    return *this;
}

template<typename T>
Linkedlist<T>::~Linkedlist(){

    while(head != NULL){

        Node<T>* temp = head;

        head = head->next;

        temp->~Node<T>();

        free(temp);
    }
}