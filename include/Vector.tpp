template<typename T>
void Vector<T>::resizing() {
    capacity *= 2;

    T* temp = ptr;

    ptr = (T*)malloc(capacity * sizeof(T));

    if (ptr == nullptr)
        throw std::bad_alloc();

    for (int i = 0; i < size; i++) {
        new(&ptr[i]) T(temp[i]);
        temp[i].~T();
    }

    free(temp);
}

template<typename T>
Vector<T>::Vector() {
    capacity = 1;
    size = 0;

    ptr = (T*)malloc(capacity * sizeof(T));

    if (ptr == nullptr)
        throw std::bad_alloc();
}

template<typename T>
Vector<T>::~Vector() {
    for (int i = 0; i < size; i++)
        ptr[i].~T();

    free(ptr);
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v) {
    capacity = 1;
    size = 0;

    ptr = (T*)malloc(capacity * sizeof(T));

    if (ptr == nullptr)
        throw std::bad_alloc();

    for (int i = 0; i < v.Size(); i++)
        push_back(v[i]);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {

    if (this == &v)
        return *this;

    for (int i = 0; i < size; i++)
        ptr[i].~T();

    free(ptr);

    capacity = 1;
    size = 0;

    ptr = (T*)malloc(capacity * sizeof(T));

    if (ptr == nullptr)
        throw std::bad_alloc();

    for (int i = 0; i < v.Size(); i++)
        push_back(v[i]);

    return *this;
}

template<typename T>
void Vector<T>::push_back(const T& x) {

    if (size == capacity)
        resizing();

    new(&ptr[size]) T(x);
    size++;
}

template<typename T>
void Vector<T>::pop_back() {

    if (size == 0)
        throw std::underflow_error("Vector is empty.");

    ptr[size - 1].~T();
    size--;
}

template<typename T>
int Vector<T>::Size() const {
    return size;
}

template<typename T>
bool Vector<T>::isempty() const {
    return size == 0;
}

template<typename T>
T& Vector<T>::operator[](int idx) {

    if (idx < 0 || idx >= size)
        throw std::out_of_range("Index out of range.");

    return ptr[idx];
}

template<typename T>
const T& Vector<T>::operator[](int idx) const {

    if (idx < 0 || idx >= size)
        throw std::out_of_range("Index out of range.");

    return ptr[idx];
}