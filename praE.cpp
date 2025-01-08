#include<iostream>
#include "HashTable.h"

int main()
{
	HashTable<int> tabla_hash = HashTable<int>(3);
	std::cout << "-HASH TABLE 1 created, capacity: " << tabla_hash.capacity() << std::endl;
	
	std::cout << "\n\n-INSERTS:" << std::endl; 
	std::string s_key = "aaa";
	int val = 0;
	try
	{
		tabla_hash.insert(s_key, val);
		std::cout << "  Key " << s_key << " -> " << val << " inserted" << std::endl;
	} catch(std::runtime_error &e)
	{
		std::cout << "	Wrong insertion of aaa, 0" << std::endl;
	}
	s_key = "aba";
	val = 1;
 	try
	{
		tabla_hash.insert(s_key, val);
		std::cout << "  Key " << s_key << " -> " << val << " inserted" << std::endl;
	} catch(std::runtime_error &e)
	{
                std::cout << "	Wrong insertion of aba, 0" << std::endl;
	}
	s_key = "aab";
        val = 2;
        try
	{
		tabla_hash.insert(s_key, val);
		std::cout << "  Key " << s_key << " -> " << val << " inserted" << std::endl;
	} catch(std::runtime_error &e)
	{
                std::cout << "	Wrong insertion of aab, 0" << std::endl;
	}
	
	std::cout << "\n\n-PRINT HASH 1:" << std::endl;
	std::cout << " *Tabla Hash 1: " << std::endl;
	std::cout << tabla_hash;
	std::cout << " *Number of reg 1: " << tabla_hash.entries() << std::endl;

	HashTable<int> tabla_hash2 = HashTable<int>(3);
	std::cout << "-HASH TABLE 2 created, capacity: " << tabla_hash2.capacity() << std::endl;
	std::cout << "\n\n-INSERTS:" << std::endl;
	s_key = "baa";
	val = 3;
	try
	{
		tabla_hash2.insert(s_key, val);
		std::cout << "  Key " << s_key << " -> " << val << " inserted" << std::endl;
	} catch(std::runtime_error &e)
	{
	        std::cout << "  Wrong insertion of baa, 0" << std::endl;
	}
	s_key = "bab";
        val = 4;
        try
        {
                tabla_hash2.insert(s_key, val);
		std::cout << "  Key " << s_key << " -> " << val << " inserted" << std::endl;
	} catch(std::runtime_error &e)
	{
	        std::cout << "  Wrong insertion of baa, 0" << std::endl;
	}
	
        s_key = "aaa";
	val = 5;
	try
	{
	        tabla_hash2.insert(s_key, val);
	        std::cout << "  Key " << s_key << " -> " << val << " inserted" << std::endl;
	} catch(std::runtime_error &e)
	{
	       std::cout << "  Wrong insertion of baa, 0" << std::endl;
	}

	std::cout << "\n\n-PRINT HASH 2:" << std::endl;
        std::cout << " *Tabla Hash 2: " << std::endl;
        std::cout << tabla_hash2;
        std::cout << " *Number of reg: " << tabla_hash2.entries() << std::endl;

	HashTable<int> th_suma = tabla_hash + tabla_hash2;

	std::cout << "\n\n-PRINT HASH SUM:" << std::endl;
        std::cout << " *Tabla Hash Suma: " << std::endl;
        std::cout << th_suma;
        std::cout << " *Number of reg: " << th_suma.entries() << std::endl;

	return 0;
}