#pragma once
#include <iostream>

class Vector{
private:
	int _size, _count;
	int* _data;
	bool Expand_New();
	bool Expand_Old();
public:
	
	Vector(int size):_size(size){
		_data = new int[_size];
		_count = 0;
	}

	Vector(const Vector& newVector):_size(newVector._size),
	_count(newVector._count),_data(newVector._data){
		for(int i =0;i < _count;i++) _data[i] = newVector._data[i];
	}
	int Insert(int _pos, int _val);
	
	bool Delete(int _pos);
	void PrintVector();

	~Vector(){
	delete[] _data;
	std::cout << "É¾³ýÁË!" << std::endl;
	}

};

