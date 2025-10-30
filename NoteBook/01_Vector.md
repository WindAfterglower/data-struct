# 结构定义

顺序表，最简单数据结构之一，由一片连续的存储空间和size与count组成。

![image-20251030225031028](./assets/image-20251030225031028.png)

`Size`:这个表的大小。

`Count`：这个表内元素的数量。



```c++
typedef struct Vector {
    int size,count; //大小，存储元素的数量
    int* data;// 连续存储区
} Vector;
```



# 结构操作

## 初始化

初始化的时候，我们首先需要开辟这个数据结构的内存空间，然后再开辟内部成员的内存空间。

```c++
Vector* Init_Vector(int _size){
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->size = _size;
    v->count = 0;
    v->data = (int*)malloc(sizeof(int) * _size);
    return v;
}
```

## 销毁

有创建就有摧毁，销毁这个数据结构时，由内向外进行销毁。

```c++
void Clear(Vector* v){
    if(v == NULL) return ;
    delete v->data;
    delete v;
    return ;
}
```

