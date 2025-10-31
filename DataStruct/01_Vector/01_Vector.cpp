//#pragma warning(disable:6011)
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
    if(v ==NULL) return NULL;

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

/*
有了插入和删除，自然还需要添加一个扩容操作。
扩容前要检查顺序表的合法性。

使用2倍扩容法，即size * 2,扩容后记得更新属性。

*/
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

bool Check(Vector* v,int _checkVal){
    if(v == NULL) return NULL; 
    
    for(int i =0;i < v->count;++i){
        if(v->data[i] == _checkVal) return 1;
    }

    return 0;
}


/*
插入操作，就是在这篇连续存储空间上插入一个元素。
插入前需检查一下插入位置是否可插入（就是这个位置合不合法）
如果合法，就让插入位置后面的元素都向后移动一位，空出插入位置。

记得要从连续存储空间的末尾向前遍历移动元素，如果是从前向后（或者从插入位置）遍历，
则前面的元素会覆盖掉后面的元素，造成元素丢失。

遍历移动完成后就可以插入元素了，同时记得更新count属性。
*/
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

/*
既然可以指定插入，也就可以指定删除。
事前检查一下删除位置是否合法。
然后从删除位置开始遍历即可，将后面的元素向前移动一位，覆盖掉前面的元素。
同时记得更新属性。
*/

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
      std::cout<<Check(v,3)<<std::endl;
}


