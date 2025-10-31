#include "Vector.h"

template<typename T>
T* smart_relloc(T* old_ptr, size_t old_count, size_t new_count){
    static_assert(std::is_trivially_copyable_v<T>,
        "Type must be trivially copyable for realloc");

    T* new_ptr = static_cast<T*>(std::realloc(old_ptr, new_count * sizeof(T)));
    if (!new_ptr) {
        // 回退：重新分配并手动拷贝
        new_ptr = static_cast<T*>(std::malloc(new_count * sizeof(T)));
        if (!new_ptr) return nullptr;

        std::memcpy(new_ptr, old_ptr, old_count * sizeof(T));
        std::free(old_ptr);
    }
    return new_ptr;
}

bool Vector::Expand_Old(){
    int* ptr = new int[this->_size*2];
    if (ptr == NULL) return 0;

    //for(int i =0;i < this->_count;i++) ptr[i] = this->_data[i];
    std::copy(_data,_data + _count,ptr);//效果同上

    delete[] this->_data;
    this->_data = ptr;
    this->_size *= 2;
    return 1;
}

bool Vector::Expand_New(){
    
    int* ptr = smart_relloc(_data,_count,_size * 2);
    if(ptr ==NULL) return 0;
    this->_data = ptr;
    this->_size *= 2;
    return 1;
}

int Vector::Insert(int _pos, int _val){
    if (_pos < 0 || _pos > this->_size) return 0;
    
    if (this->_count == this->_size && !Expand_New())  return 0;
    

    for (int i = this->_count - 1;i >= _pos;i--) {
        this->_data[i + 1] = this->_data[i];
    }
    this->_data[_pos] = _val;
    this->_count++;
    return 1;
}

bool Vector::Delete(int _pos){
    if(_pos < 0 || _pos > this->_count) return 0;

    for(int i = _pos;i < this->_count - 1;i++){
        this->_data[i] = this->_data[i + 1];
    }
    this->_count --;
    return 1;
}

void Vector::PrintVector(){
    for (int i = 0; i < this->_size; i++) std::cout << i << " ";

    std::cout << std::endl;

    for (int i = 0; i < this->_count; i++) std::cout << this->_data[i] << " ";
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
}
