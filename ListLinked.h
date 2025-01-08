#include <ostream>
#include "List.h"
#include "Node.h"


template <typename T>
class ListLinked : public List<T> {

    private:
		Node<T>* first;
		int n;
    public:
		ListLinked();
		~ListLinked();
		T operator[](int pos);

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>* current = list.first;
			while (current != nullptr) {
       			out << current->data;
        		current = current->next;
        		if (current != nullptr) {
           			out << ", ";
    			}
			}
			return out;
		}

		//heredados
		void insert(int pos, T e) override final;
		void append(T e) override final;
		void prepend(T e) override final;
		T remove(int pos) override final;
		T get(int pos) override final;

		int search(T e) override final;
		bool empty() override final;
		int size() override final;

        Node<T>* getFirst() const {
        return first;
    }
         void setFirst(Node<T>* newFirst) {
        first = newFirst;
    }
};


template <typename T>
ListLinked<T>::ListLinked() : first(nullptr), n(0) {}
	


template <typename T>
ListLinked<T>::~ListLinked(){
	do{
		Node<T>* aux = first;
		first = first->next;
		delete aux;
	} while(first != nullptr);
}

template <typename T>
T ListLinked<T>::operator[](int pos){
	if(pos < 0 || pos > size()-1){
		throw std::out_of_range("Posicion incorrecta");
	}
	else{
		Node<T>* current = first;
		int i = 0;
		while(current != nullptr && i < pos){
			current = current->next;
			i++;
		}
		return current->data;	
	}
}


template <typename T>
void ListLinked<T>::insert(int pos, T e){
	if(pos < 0 || pos > size()){
		throw std::out_of_range("Posicion incorrecta");
	}
	else{
		Node<T>* newNode = new Node<T>{e, nullptr};
		if(pos == 0){
			newNode->next = first;
			first = newNode;
		}
		else{
			Node<T>* prev = nullptr;
			Node<T>* aux = first;
			int i = 0;
			while (aux != nullptr && i < pos){
				prev = aux;
				aux = aux->next;
				i++;
			}
			prev->next = newNode;
			newNode->next = aux;
		}
	}
}

template <typename T> 
void ListLinked<T>::append(T e){
	ListLinked::insert(size(), e);
}

template <typename T> 
void ListLinked<T>::prepend(T e){
	ListLinked::insert(0, e);
}


template <typename T>
T ListLinked<T>::remove(int pos){
	if(pos < 0 || pos > size()-1){
		throw std::out_of_range("Posicion incorrecta");
	}
	else{
		Node<T>* prev = nullptr;
		Node<T>* aux = first;
		int i = 0;
		while (aux != nullptr && i < pos){
			prev = aux;
			aux = aux->next;
			i++;
		}
		if(prev != nullptr){
			prev->next = aux->next;
		}
		else{
			first = aux->next;
		}
		T data = aux->data;
		delete aux;
		return data;
	}
}

template <typename T>
T ListLinked<T>::get(int pos){
	if(pos < 0 || pos > size()-1){
		throw std::out_of_range("Posicion incorrecta");
	}
	else{
		Node<T>* aux = first;
		int i = 0;
		while (aux != nullptr && i < pos) {
    		aux = aux->next;
   			i++;
		}
		return aux->data;
	}
}

template <typename T>
int ListLinked<T>::search(T e){
	Node<T>* aux = first;
	int i = 0;
	while(aux != nullptr){
		if(aux->data == e){
			return i;
		}
		aux = aux->next;
		i++;
	}
	return -1;
}


template <typename T>
bool ListLinked<T>::empty(){
	if(first == nullptr){
		return true;
	}
	else{
		return false;
	}
}


template <typename T>
int ListLinked<T>::size(){
	Node<T>* aux = first;
	int i = 0;
	while(aux != nullptr){
		aux = aux->next;
		i++;	
	}
	return i;
}
