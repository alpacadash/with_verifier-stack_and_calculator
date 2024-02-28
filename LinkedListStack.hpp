#ifndef __ICS46_LL_STACK_HPP
#define __ICS46_LL_STACK_HPP

#include <stdexcept>


class StackEmptyException : public std::runtime_error {
   public:
    explicit StackEmptyException(const std::string& err)
        : std::runtime_error(err) {}
};


// This is the LinkedListStack class you will be implementing for this project.
// Remember to see the write-up for more details!
template <typename T>
struct Node{
        T data;
        Node<T> *tail;

        Node<T>(T n) : data(n), tail(nullptr) {}
    };

template <typename T>
class LinkedListStack {
   private:
    // fill in private member data here
    Node<T> *head;
    int stackSize;
   public:
    // constructor
    LinkedListStack();

    // copy constructor (remember, deep copy!)
    LinkedListStack(const LinkedListStack& stackb);

    // assignment operator (remember, deep copy!)
    LinkedListStack& operator=(const LinkedListStack& stackb);
    // You do not need to implement these
    LinkedListStack(LinkedListStack&&) = delete;
    LinkedListStack& operator=(LinkedListStack&&) = delete;
    // destructor
    ~LinkedListStack();

    [[nodiscard]] size_t size() const noexcept;
    [[nodiscard]] bool empty() const noexcept;

    // We have two top() functions.  The first gets called if your
    // LinkedListStack is not a const, while the latter gets called on a const
    // LinkedListStack (the latter might occur via const reference parameter,
    // for instance). Be sure to test both!  It is important when testing to
    // ensure that EVERY funtion gets called and tested!
    [[nodiscard]] T& top();
    [[nodiscard]] const T& top() const;

    void push(const T& elem) noexcept;
    void pop();
};

template <typename T>
LinkedListStack<T>::LinkedListStack() {
    // TODO: Fill in your constructor implementation here.
    head = nullptr;
    stackSize = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack& stackb) {
    // TODO: Fill in your copy constructor implementation here.
    head = nullptr;
    stackSize = stackb.size();
    Node<T>* p = nullptr;
    Node<T>* temp;
    for (size_t i = 0; i < stackb.size(); i++){
        temp = p;
        p = new Node<T>(temp->data);
        if(i == 0){
            head = p;
        }
        else{
            temp->tail = p;
        }
    }
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(
    const LinkedListStack& stackb) {
        if(this != &stackb){
            stackSize = stackb.size();
            Node<T> *temp;
            while(head != nullptr){
                temp = head;
                head = head->tail;
                delete temp;
            }
            if(stackb.head != nullptr){
                head = new Node<T>(stackb.head->data);
                Node<T> *tmpHead = head;

                for(Node<T> *i = stackb.head->tail; i != nullptr; i = i->tail){
                    tmpHead->tail = new Node<T>(i->data);
                    tmpHead = tmpHead->tail;
                }
            }
        }
    // TODO: Fill in your assignment operator implementation here.
    return *this;  // Stub so this function compiles without implementation.
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    // TODO: Fill in your destructor implementation here.
    while(head != nullptr){
        Node<T> *temp = head;
        head = head->tail;
        delete temp;
    }
    delete head;
}

template <typename T>
size_t LinkedListStack<T>::size() const noexcept {
    // TODO: Fill in your size() implementation here.
    return stackSize;  // Stub so this function compiles without an implementation.
}

template <typename T>
bool LinkedListStack<T>::empty() const noexcept {
    // TODO: Fill in your isEmpty() implementation here.
    return (head == nullptr);  // Stub so this function compiles without an implementation.
}

template <typename T>
T& LinkedListStack<T>::top() {
    // TODO: Fill in your top() implementation here.
    // The following is a stub just to get the template project to compile.
    // You should delete it for your implementation.
    auto val = new T;
    if(head == nullptr){
        throw(StackEmptyException("Error"));
    }
    else{

        Node<T> *temp = head;
        while(temp->tail != nullptr){
            temp = temp->tail;
        }
        *val = temp->data;
    }
    return *val;
}

template <typename T>
const T& LinkedListStack<T>::top() const {
    // TODO: Fill in your const top() implementation here.
    // The following is a stub just to get the template project to compile.
    // You should delete it for your implementation.
    if(head == nullptr){
        throw(StackEmptyException("Error"));
    }
    else{
        Node<T> *temp = head;
        while(temp->tail != nullptr){
            temp = temp->tail;
        }
        return temp->data;
    }
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) noexcept {
    // TODO: Fill in your push() implementation here.
    stackSize++;
    if(head == nullptr){
        head = new Node<T>(elem);
    }
    else{
        Node<T> *temp = head;
        while(temp->tail != nullptr){
            temp = temp->tail;
        }
        temp->tail = new Node<T>(elem);
    }
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TODO: Fill in your pop() implementation here.
    stackSize--;
    if(head == nullptr){
        throw(StackEmptyException("Error"));
    }
    else{
        Node<T> *temp = head;
        Node<T> *temp2 = nullptr;
        if(head->tail == nullptr){
            temp = head->tail;
            delete head;
            head = temp;
        }
        else{
            while(temp->tail != nullptr){
            temp2 = temp;
            temp = temp->tail;
        }
        temp2->tail = temp->tail;
        delete temp;
        }
    }
}

#endif
