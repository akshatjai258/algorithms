#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 5;
const int GROWTH_FACTOR = 2;

template <class T>
class dynamic_array {
    T *array;
    int capacity = INITIAL_CAPACITY;
    int _size;
    
public:
    dynamic_array() {
        array = new T[MIN_CAPACITY];
        size = 0;
    }
    
    ~dynamic_array() {
        delete[] array;
    }
    
    void delete_at(int pos) {
        assert(0 <= pos && pos < _size);
        
        size--;
        for(int i = pos; i <= size; i++) {
            array[i] = array[i+1];
        }
    }
    
    void insert_at(int element, int pos) {
        assert(0 <= pos && pos <= _size);
        if(_size == capacity) {
            resize();
        }
        for(int i = _size; i > pos; i--) {
            array[i] = array[i-1];
        }
        _size++;
        array[pos] = element;
    }

    
    void append(T element) {
        insert_at(element, _size);
    }
    
    int size() {
        return _size;
    }
    
    // doubles capacity if it has to and deletes reference to current array.
    void resize() {    void resize() {
        capacity *= GROWTH_FACTOR;
        T *temp = new T[capacity];
        copy(array, array + _size, temp);
        delete [] array;
        array = temp;
    }
    
    T get(int pos) {
        return array[pos];
    }
    
    void print() {
        cout << "[";
        for (int i = 0; i < _size - 1; i++) {
            cout << array[i] << " ";
        }
        if (_size) {
            cout << array[_size - 1];
        }
        cout << "]\n";
    }
};



int main() {
    dynamic_array<int> dynArr;
    dynArr.append(3);
    dynArr.append(4);
    dynArr.append(5);
    dynArr.append(4);
    dynArr.append(33);
    dynArr.append(3);
    
    dynArr.delete_at(6);
    

    cout << dynArr.size() << endl;
    
    return 0;
}
