#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:
        // miembros públicos
        T elem;
        BSNode<T>* left;
        BSNode<T>* right;

        //metodos
        BSNode(T elem, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr){
            this->elem =elem;
            this->left = left;
            this->right = right;
        }
        friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &bsn){
            for(int i = 0; i < bsn.size(); i++){
				out << bsn.elem << ", ";
			}
			return out;
        }
    
};

#endif
