#ifndef BSTMAP
#define BSTMAP 

#include <iostream> 
#include <stdlib.h>

template<typename K,typename V>
class BSTMap {
    
private:
    // TODO: Define your Node
    struct Node{
        Node* right;
        Node* left; 
        Node* parent; 
        std::pair<K,V> nodepr; 

        Node(Node* r, Node* l, Node* p, K k, V v){
            right = r;
            left = l;
            parent = p; 
            nodepr = std::make_pair(k,v);
        }
    };
    // TODO: specify whatever member data you need.
    unsigned sz; 
    Node* root;
    
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
        Node* Successor(Node* x){
         if (x->right != nullptr){
            return BSTMap<K,V>::minNode(x->right);
         } 
          Node* y = x->parent;
          while (y != nullptr && x == y->right){
                x = y;
                y = y->parent;
            }
            return y;
        }

        bool operator==(const iterator &i) const { 
            return (loc->nodepr == i.loc->nodepr && itrend == i.itrend); 
        }

        bool operator!=(const iterator &i) const { return !(*this==i); }
        std::pair<K,V> &operator*() { return loc -> nodepr; }
        iterator &operator++() {
            loc = Successor(loc);
            if(loc == nullptr){
                itrend = true;
            }
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


        Node* Successor(Node* x){
         if (x->right != nullptr){
            return BSTMap<K,V>::minNode(x->right);
         } 
          Node* y = x->parent;
          while (y != nullptr && x == y->right){
                x = y;
                y = y->parent;
            }
            return y;
        }


        bool operator==(const const_iterator &i) const { /*TODO*/ }
        bool operator!=(const const_iterator &i) const { return !(*this==i); }
        const std::pair<K,V> &operator*() { /*TODO*/ }
        const_iterator &operator++() {
            loc = Successor(loc);
            if(loc == nullptr){
                itrend = true;
            }
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

    static Node* maxNode(Node* x){
        while (x->right != nullptr){
            x = x->right;
        } return x;
    }

    static Node* minNode(Node* x){
        while (x->left != nullptr){
            x = x->left;
        } return x;
    }

    BSTMap(){
       root = nullptr;
       sz = 0; 
    }
    ~BSTMap(){

    }
    BSTMap(const BSTMap<K,V> &that) {
        // TODO
    }

    BSTMap &operator=(const BSTMap<K,V> &that) {
        // TODO
    }

    bool empty() const {return sz == 0;}

    unsigned size() const {return sz;}

    Node* getroot(){
        return root;
    }

    Node* fancy_find(Node* nd, const key_type& k) const{
        if(nd == nullptr || k == nd->nodepr.first){
            return nd;
        }if(k < nd->nodepr.first){
            return fancy_find(nd->left,k);
        } else if (k > nd->nodepr.first){
            return fancy_find(nd->right,k);
        }
    }

    iterator find(const key_type& k){
        auto fndr = fancy_find(root,k);
        if(fndr == nullptr){
            return end();
        }
        else {
            return iterator(fancy_find(root,k),false);
        }
    }

    const_iterator find(const key_type& k) const{
        return const_iterator(fancy_find(root,k),false);
    }

    unsigned int count(const key_type& k) const{
        auto fndr = fancy_find(root,k);
        if(fndr == nullptr){
            return 0;
        } else {
            return 1;
        }
    }

    std::pair<iterator,bool> insert(const value_type& val){
        if(count(val.first) == 1){
            return std::make_pair(find(val.first),false);
        }

        Node* z = new Node(nullptr,nullptr,nullptr,val.first,val.second);
        Node* y = nullptr;
        Node* x = root;
        
        ++sz;
        while (x != nullptr){
            y = x;
            if(z->nodepr.first < x->nodepr.first){
                x = x->left;
            } else {x = x->right;}
        }
        z->parent = y;
        if(y == nullptr){
            root = z;
        } else if(z->nodepr.first < y->nodepr.first){
            y->left = z;
        } else{
            y->right = z;
        }

        return std::make_pair(iterator(z,false),true);

    }

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
        for(auto iter = first; iter!=last; ++iter) {
            insert(*iter);
        }
    }

    void transplant(Node* u, Node* v){
        if(u->parent == nullptr){
            root = v;
        } else if (u == u->parent->left){
            u->parent->left = v;
        } else u->parent->right = v;
        if (v != nullptr){
            v->parent = u->parent;
        }
    }

    iterator erase(const_iterator position){
        auto z = position.loc;
        if(z == nullptr){
            transplant(z,z->right);
        } else if(z->right == nullptr){
            transplant(z,z->left);
        } else {
            auto y = minNode(z->right);
            if(y->parent != z){
                transplant(y,y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z,y);
            y->left = z->left;
            y->left->parent = y;
        }
    }

    unsigned int erase(const key_type& k){
        if(count(k) == 0){
            return 0;
        }else{
        std::cout << "\nbefore find\n";
        auto z = fancy_find(root,k);
        std::cout << "after find\n";
        if(z == nullptr){
            transplant(z,z->right);
        }else if(z->right == nullptr){
            std::cout << "z's right\n";
            transplant(z,z->left);
            std::cout << "transplant happened";
        }else {
            std::cout << "z's left\n";
            Node* y = minNode(z->right);
            std::cout << "y created I guess\n";
            if(y->parent != z){
                std::cout << "before transplant\n";
                transplant(y,y->right);
                std::cout << "after transplant\n";
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z,y);
            y->left = z->left;
            y->left->parent = y;
        }
        }
    }

    void clear();

    mapped_type &operator[](const K &key){
        return (*find(key)).second;
    }

    bool operator==(const BSTMap<K,V>& rhs) const;

    bool operator!=(const BSTMap<K,V>& rhs) const{
       return !(this == rhs);
    }

    iterator begin() {return iterator(minNode(root),false);}

    const_iterator begin() const { return const_iterator(minNode(root),false); }

    iterator end() { return iterator(maxNode(root),true); }

    const_iterator end() const { return const_iterator(maxNode(root),true); }

    const_iterator cbegin() const { return const_iterator(minNode(root),false); }

    const_iterator cend() const { return const_iterator(maxNode(root),true); }

};


#endif
