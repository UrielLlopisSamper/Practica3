#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "ListLinked.h"

template <typename V>
class HashTable : public Dict<V> {
    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;
        int h(std::string key);
    public:
        HashTable(int size);
        ~HashTable();
        int capacity();
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            for (int i = 0; i < th.max; i++) {
                out << "Bucket " << i << ": ";
                Node<TableEntry<V>>* current = th.table[i].getFirst();
                while (current != nullptr) {
                    out << "[" << current->data.key << ": " << current->data.value << "] -> ";
                    current = current->next;
                }
                out << "nullptr\n";
            }
            return out;
        }

        V operator[](std::string key);

        // Heredados
        void insert(std::string key, V value) override final;
        V search(std::string key) override final;
        V remove(std::string key) override final;
        int entries() override final;

        // Sobrecarga del operador +
friend HashTable<V> operator+(HashTable<V>& ht1, HashTable<V>& ht2) {
    // Determinamos la capacidad máxima entre las dos tablas
    int max_size = std::max(ht1.max, ht2.max);

    // Creamos una nueva tabla con la capacidad calculada
    HashTable<V> result(max_size);

    // Insertamos todos los pares clave-valor de la primera tabla
    Node<TableEntry<V>>* current = nullptr;
    for (int i = 0; i < ht1.max; i++) {
        current = ht1.table[i].getFirst();
        while (current != nullptr) {
            try {
                result.insert(current->data.key, current->data.value);
            } catch (std::runtime_error&) {
                // Ignoramos la excepción si la clave ya existe
            }
            current = current->next;
        }
    }
 // Insertamos todos los pares clave-valor de la segunda tabla que no están en la primera
    for (int i = 0; i < ht2.max; i++) {
        current = ht2.table[i].getFirst();
        while (current != nullptr) {
            try {
                result.insert(current->data.key, current->data.value);
            } catch (std::runtime_error&) {
                // Ignoramos la excepción si la clave ya existe
            }
            current = current->next;
        }
    }

    // Devolvemos la tabla combinada
    return result;
}

};

template <typename V>
int HashTable<V>::h(std::string key){
    int suma = 0;
    for(int i = 0; i < key.size(); i++){
        suma += int(key.at(i));
    }
    return suma % max;
}

template <typename V>
HashTable<V>::HashTable(int size): n(0), max(size){
    table = new ListLinked<TableEntry<V>>[max];
}

template <typename V>
HashTable<V>::~HashTable(){
    delete[] table;
}

template <typename V>
int HashTable<V>::capacity(){
    return max;
}

template <typename V>
V HashTable<V>::operator[](std::string key){
    return search(key);
}

template <typename V>
void HashTable<V>::insert(std::string key, V value){
    int index = h(key);
    Node<TableEntry<V>>* current = table[index].getFirst();
    while(current != nullptr){
        if(current->data.key == key){
            throw std::runtime_error("La llave ya existe");
        }
        current = current->next;
    }

    TableEntry<V> nueva(key, value);
    table[index].prepend(nueva);
    n++;
}

template <typename V>
V HashTable<V>::search(std::string key){
    int index = h(key);
    Node<TableEntry<V>>* current = table[index].getFirst();
    
    while(current != nullptr){
        if(current->data.key == key){
            return current->data.value;
        }
        current = current->next;
    }
    throw std::runtime_error("La llave no tiene ningun valor asociado");
}

template <typename V>
V HashTable<V>::remove(std::string key){
    int index = h(key);
    Node<TableEntry<V>>* current = table[index].getFirst();
    Node<TableEntry<V>>* prev = nullptr;
    
    while(current != nullptr){
        if(current->data.key == key){
            if(prev != nullptr){
                prev->next = current->next; // Corrección en la asignación
            }
            else{
                table[index].setFirst(current->next);
            }
            V dato_eliminado = current->data.value;
            delete current;
            n--;
            return dato_eliminado;
        }
        else{
            prev = current;
            current = current->next;
        }
    }
    throw std::runtime_error("La llave no tiene ningun valor asociado");
}

template <typename V>
int HashTable<V>::entries(){
    return n;
}

#endif

