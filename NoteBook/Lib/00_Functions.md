## Smart_Relloc

这是在C++上实现的一个类relloc函数。

```c++
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
```

