#ifndef BSTMAP
#define BSTMAP 

#include <iostream> 
#include <functional>

template<typename K,typename V>
class BSTMap {
    
private:
    // TODO: Define your Node
    struct Node{
        Node* right;
        Node* left; 
        Node* parent; 
        K key;
        V data;
        std::pair<K,V> nodepr; 

        Node(Node* r, Node* l, Node* p, K k, V v){
            right = r;
            left = l;
            parent = p; 
            key = k;
            data = v; 
            nodepr = std::make_pair(key,data);
        }
    };

    // TODO: specify whatever member data you need.
    Node* root;
    unsigned int sz; 

public:
    typedef K key_type;
    typedef V mapped_type;
    typedef std::pair<K,V> value_type;

    class const_iterator;

    class iterator {
        // TODO: Iterator data. I keep a Node* and a bool that tells me if it is at end.
        Node* loc; 
        bool itrend;
    public:
        friend class const_iterator;
        iterator(Node* l,bool b):loc(l),itrend(b){}
        // TODO: Other constructors as needed.

        bool operator==(const iterator &i) const { /*TODO*/ }
        bool operator!=(const iterator &i) const { return !(*this==i); }
        std::pair<K,V> &operator*() { return loc -> nodepr; }
        iterator &operator++() {
            // TODO
            return *this;
        }
        iterator &operator--() {
            // TODO
            return *this;
        }
        iterator operator++(int) {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }
        iterator operator--(int) {
            iterator tmp(*this);
            --(*this);
            return tmp;
        }
    };

    class const_iterator {
        Node* loc; 
        bool itrend;
    public:
        friend class BSTMap<K,V>;  // You might not need this in your code, but it helped me.
        const_iterator(/*TODO*/)/*:...*/ { /*TODO*/ }
        // TODO: Other constructors as needed.
        const_iterator(const iterator &iter):loc(iter.loc),itrend(iter.itrend){}

        bool operator==(const const_iterator &i) const { /*TODO*/ }
        bool operator!=(const const_iterator &i) const { /*TODO*/ }
        const std::pair<K,V> &operator*() { /*TODO*/ }
        const_iterator &operator++() {
            // TODO
            return *this;
        }
        const_iterator &operator--() {
            // TODO
            return *this;
        }
        const_iterator operator++(int) {
            const_iterator tmp(*this);
            ++(*this);
            return tmp;
        }
        const_iterator operator--(int) {
            const_iterator tmp(*this);
            --(*this);
            return tmp;
        }
    };



    BSTMap() {
       root = nullptr;
       sz = 0; 
    }
    ~BSTMap() {

    }
    BSTMap(const BSTMap<K,V> &that) {
        // TODO
    }

    BSTMap &operator=(const BSTMap<K,V> &that) {
        // TODO
    }

    bool empty() const {return sz == 0;}

    unsigned size() const {return sz;}

    Node* search(Node* nd, const key_type& k){
        if(nd == nullptr || k == nd->key){
            return nd;
        }
        if(k < nd->key){
            return search(nd->left,k);
        } else {
            return search(nd->right,k);
        }
    }

    iterator find(const key_type& k);

    const_iterator find(const key_type& k) const;

    unsigned int count(const key_type& k) const;

    std::pair<iterator,bool> insert(const value_type& val){
        Node* y = nullptr;
        auto x = root;
        auto z = new Node(nullptr,nullptr,nullptr,val.first,val.second);
        while (x != nullptr){
            y = x;
            if(val.first != x->key){
                x = x->left;
            } else {x = x->right;}
        }
        z->parent = y;
        if(y == nullptr){
            root = z;
        } else if(val.first < y->key){
            y->left = z;
        } else{
            y->right = z;
        }

    }

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
        for(auto iter = first; iter!=last; ++iter) {
            insert(*iter);
        }
    }

    void transplant(){}

    iterator erase(const_iterator position){
        if((position->loc) == nullptr){

        }
    }

    unsigned int erase(const key_type& k);

    void clear();

    mapped_type &operator[](const K &key);

    bool operator==(const BSTMap<K,V>& rhs) const;

    bool operator!=(const BSTMap<K,V>& rhs) const{
       return !(this == rhs);
    }

    iterator begin() { return iterator(/*TODO*/); }

    const_iterator begin() const { return const_iterator(/*TODO*/); }

    iterator end() { return iterator(/*TODO*/); }

    const_iterator end() const { return const_iterator(/*TODO*/); }

    const_iterator cbegin() const { return const_iterator(/*TODO*/); }

    const_iterator cend() const { return const_iterator(/*TODO*/); }

};


#endif
