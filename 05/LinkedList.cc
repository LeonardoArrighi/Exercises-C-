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
        node(const std::unique_ptr<node>& n) : value{n->value}
        {
            if(n->next) next = std::make_unique<node>(n->next);
        }

    };

//  public:
//   // insert a new node with the value v according to the method m
//   // this method should be used to fill the list
//   void insert(const value_type& v, const Insertion_method m);

//   // return the size of the list
//   std::size_t size() const;

//   // delete all the nodes of the list
//   void reset();

//   // constructor(s) for List
  
//   // copy semantics
//   // move semantics
  
//   // destructor

//  private:
 
//   // private struct node with the proper value_type
//   struct node {
//     value_type value;
//     std::unique_ptr<node> next;

//     // implement suitable constructor(s) for node
    
//     // copy and move semantics if needed
    
//     // destructor
//   };

//   // append the newly created node at the end of the list
//   void push_back(const value_type& v);

//   // insert the newly created node in front of the list
//   void push_front(const value_type& v);

//   std::unique_ptr<node> head;
//   std::size_t size;
};



// template <class T>
// std::ostream& operator<<(std::ostream& os, const List<T>& l);

// ```

// #### *Hints*:

// - A `std::unique_ptr<T> p` has the following functions
//    - `T* get() const` Returns a pointer to the managed object or `nullptr` if no object is owned.
//    - `T* release()` Releases the ownership of the managed object if any. `get()` returns `nullptr` after the call.
//    - `void reset(T* ptr)` Delete `current_ptr` (if any) and set `current_ptr = ptr`.
//    - To check if a `std::unique_ptr<T> p` is different from `nullptr` you can simply use `if(p)` (there is no need to write `if (p.get())`).

// -  For a class `Foo`

//     ```C++
//     class Foo{
//       Foo(); // default ctor
//       Foo(const Foo& f); // copy ctor
//       Foo(Foo&& f); // move ctor
      
//       Foo& operator=(const Foo& f); // copy assignment
//       Foo& operator=(Foo& f); // move assignment
//     };
//     ```

    

// You are required to use blocks of memory (*heap*) locations which are linked together. Each of these blocks contains one component that may refer to another block. If each block (except the final one) contains a pointer to the next block, so that they form a chain, then the entire collection of linked blocks is called a **linked list**. The blocks of memory locations of a linked list are usually called *nodes*.

// Every node of a linked list, except the final one, contains a pointer to its immediate *successor*, and every node except the first one is pointed to by its immediate *predecessor*. The pointer member of the last node has the value `nullptr`.

// The private member `head` points to the first element of the list. 

// ![linked_list.png](./.aux/list2.png)

int main()
{
    return 0;
}