// In informatica, una lista concatenata (o linked list) è una struttura dati dinamica, 
// tra quelle fondamentali usate nella programmazione. Consiste di una sequenza di nodi,
//  ognuno contenente campi di dati arbitrari ed uno o due riferimenti ("link") che 
//  puntano al nodo successivo e/o precedente. Una lista concatenata è un tipo di dato 
//  auto-referente, in quanto contiene un puntatore ad un altro dato dello stesso tipo. Le 
//  liste concatenate permettono l'inserzione e la rimozione di nodi in ogni punto della 
//  lista in tempo costante, ma non permettono l'accesso casuale, solo quello sequenziale. 
//  Esistono diversi tipi di liste concatenate: liste concatenate semplici, liste concatenate 
//  doppie e liste circolari.


#include <iostream>
#include <memory>
#include <utility>

enum class Insertion_method {push_back, push_front};

template <class T>
class List 
{
    public:

    //default ctor
    List() = default;

    //copy ctor
    List(const List& l);

    //move ctor
    List(List&& l)=default;

    //copy assignment
    List& operator=(const List& l);

    //move assignment
    List& operator=(List&& l) = default;
    
    //default destructor
    ~List() = default;
  

//   // insert a new node with the value v according to the method m
//   // this method should be used to fill the list
//   void insert(const value_type& v, const Insertion_method m);

//   // return the size of the list
//   std::size_t size() const;

//   // delete all the nodes of the list
//   void reset();

 






    private:
    
    struct node
    {
        // pointer to the next node
        std::unique_ptr<node> next;

        //value stored of type T
        T value;
        
        //copy ctor
        node(node* n, const T& v) : next{n}, value{v} {};

        //move ctor
        node(node* n, T&& v) : next{n}, value{std::move(v)} {};

        //ctor which construct the unique_pointer of the next node 
        explicit node(const std::unique_ptr<node>& n) : value{n->value}
        {
            if(n->next) next = std::make_unique<node>(n->next);
        }

        //default destructor
        ~node() = default;
    };

    //first node
    std::unique_ptr<node> head;

    //size of the List
    std::size_t size;


    // append the newly created node at the end of the list
    template <class OT>
    void push_back(const OT& v);

    // insert the newly created node in front of the list
    template <class OT>
    void push_front(const OT& v);
    
    //service function, returns a pointe to the last node
    node* end();
};

template <class T>
List<T>::List(const List& l)
{
    head = std::make_unique<node>(l.head);
}

template <class T>
List<T>& List<T>::operator=(const List& l)
{
    return *this;
}



template <class T>
template <class OT>
void List<T>::push_back(const OT& v)
{
    node* last = end();

    last->next = std::make_unique<node>(v, nullptr);
}


template <class T>
typename List<T>::node* List<T>::end()
{   
    auto tmp = head.get();

    while(tmp->next) tmp = tmp->next.get();

    return tmp;
}

template <class T>
template <class OT>
void List<T>::push_front(const OT& v)
{
    head = std::make_unique<node>(v, head.release());
}








int main()
{
    return 0;
}