#include <iostream>


typedef struct Vector {
    int size,count; //大小，存储元素的数量
    int* data;// 连续存储区
} Vector;


/*
初始化，先开辟数据结构的内存空间，再开辟内部成员的内存空间。
*/
Vector* Init_Vector(int _size){
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->size = _size;
    v->count = 0;
    v->data = (int*)malloc(sizeof(int) * _size);
    return v;
}

void PrintVector(Vector* v) {
    for (int i = 0; i < v->size; i++) std::cout << i << " ";

    std::cout << std::endl;

    for (int i = 0; i < v->count; i++) std::cout << v->data[i] << " ";
    std::cout << std::endl;
    std::cout <<"--------------------" << std::endl;
}


int Expand(Vector* v) {
    if (v == NULL) return 0;

    std::cout << "触发扩容操作!" << std::endl;

    int* ptr = (int*)realloc(v->data, sizeof(int) * 2 * v->size);

    if (ptr == NULL) return 0;

    v->data = ptr;
    v->size *= 2;
    PrintVector(v);
    return 1;
}




bool Insert(Vector* v, int _pos, int _val) {
    if (_pos < 0 || _pos > v->size) return 0;
    
    if (v->count == v->size && !Expand(v))  return 0;


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

/*
有创建就有摧毁，销毁这个数据结构时，由内向外进行销毁。
*/
void Clear(Vector* v){
    if(v == NULL) return ;
    delete v->data;
    delete v;
    return ;
}



int main(){
    Vector* v = Init_Vector(2);
      for(int i = 0;i< 10;i++) Insert(v,i,i);
  
      PrintVector(v);

      Delete(v,2);

      PrintVector(v);
}


