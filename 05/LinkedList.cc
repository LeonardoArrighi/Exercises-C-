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
#include <algorithm>

enum class method {push_back, push_front};

template <class T>
class List 
{
    public:

    //default ctor
    List() noexcept = default;

    //copy ctor
    List(const List& l) noexcept;

    //move ctor
    List(List&& l) noexcept = default;

    //copy assignment
    List& operator=(const List& l);

    //move assignment
    List& operator=(List&& l) = default;
    
    //default destructor
    ~List() = default;
  
    template<class V>
    void insert(V&& v, const method m);

//   // return the size of the list
//   std::size_t size() const;

    void clear() noexcept
    {
        head.reset();
    }

    template <class V>
    friend std::ostream& operator<<(std::ostream&, const List<V>&); 


    private:
    
    struct node
    {
        // pointer to the next node
        std::unique_ptr<node> next;

        //value stored of type T
        T value;
        
        //copy ctor
        node( const T& v, node* n) : next{n}, value{v} {};

        //move ctor
        node(T&& v, node* n) : next{n}, value{std::move(v)} {};

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

    // append the newly created node at the end of the list
    template <class V>
    void push_back(V&& v);

    // insert the newly created node in front of the list
    template <class V>
    void push_front(V&& v);
    
    //service function, returns a pointe to the last node
    node* last();
};

template <class T>
List<T>::List(const List& l) noexcept
{
    head = std::make_unique<node>(l.head);
}

// template <class T>
// List<T>& List<T>::operator=(const List& l)
// {
//      cannot copy unique_ptr
//     return *this;
// }

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l)
{
    auto tmp = l.head.get();
    while(tmp->next)
    {
        os << tmp->value << " ";
        tmp = tmp->next.get();
    }
    return os;
} 


template <class T>
template <class V>
void List<T>::push_back(V&& v)
{
    node* least = last();

    least->next = std::make_unique<node>(std::forward<V>(v), nullptr);
}


template <class T>
typename List<T>::node* List<T>::last()
{   
    auto tmp = head.get();

    while(tmp->next) 
        tmp = tmp->next.get();

    return tmp;
}

template <class T>
template <class V>
void List<T>::push_front(V&& v)
{
    head = std::make_unique<node>(std::forward<V>(v), head.release());
}

template <class T>
template <class V>
void List<T>::insert(V&& v, const method m)
{
    if(!head)
    {
        head = std::make_unique<node>(std::forward<V>(v),nullptr);
    }
    switch (m)
    {
    case method::push_back:
        push_back(std::forward<V>(v));
        break;
    case method::push_front :
        push_front(std::forward<V>(v));
        break;
    default:
        std::cerr << "Nope" << std::endl;
        break;
    };
}





int main()
{
    List<int> l{};
    List<int> m{};

    l.insert(1, method::push_back);
    l.insert(2, method::push_front);
    l.insert(3, method::push_back);
    l.insert(4, method::push_back);
    l.insert(5, method::push_front);
    std::cout << l << std::endl;

    l.clear();
    l.insert(2, method::push_back);
    std::cout << l << std::endl;

    return 0;
}