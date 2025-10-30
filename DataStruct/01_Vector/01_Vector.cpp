#include <iostream>
typedef struct Vector {
    int size,count; //大小，存储元素的数量
    int* data;// 连续存储区
} Vector;





Vector* Init_Vector(int _size){
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->size = _size;
    v->count = 0;
    v->data = (int*)malloc(sizeof(int) * _size);
    return v;
}

bool Insert(Vector* v, int _pos, int _val) {
    if (_pos < 0 || _pos > v->size) return 0;

    for (int i = v->count - 1;i >= _pos;i--) {
        v->data[i + 1] = v->data[i];
    }
    v->data[_pos] = _val;
    v->count++;
    return 1;
}



bool Delete(Vector* v,int _pos){
     if(_pos < 0 || _pos > v->size) return 0; 

     for(int i= _pos;i < v->count - 1;i++){
        v->data[i] = v->data[i + 1];
     }
     v->count--;
     return 1;
}

void Clear(Vector* v){
    if(v == NULL) return ;
    delete v->data;
    delete v;
    return ;
}

void PrintVector(Vector* v){
    for (int i = 0;i < v->size;i++) std::cout << i << " ";

    std::cout << std::endl;

    for (int i = 0;i < v->count;i++) std::cout << v->data[i] << " ";
    
    std::cout << std::endl;
}

int main(){
    Vector* v = Init_Vector(5);
      for(int i = 0;i< v->size;i++) Insert(v,i,i);
  
      PrintVector(v);

      Delete(v,2);

      PrintVector(v);
}


