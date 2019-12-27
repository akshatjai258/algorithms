#include <assert.h>
#include <cstring>
#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 5;
const int GROWTH_FACTOR = 2;
const int LOAD_FACTOR = 0.8;

template <class T>
class dynamic_array {
    T *array;
    int capacity = INITIAL_CAPACITY;
    int _size;

public:
    dynamic_array() {
        array = new T[capacity];
        _size = 0;
    }

    ~dynamic_array() {
        delete[] array;
    }

    void deleteAt(int pos) {
        assert(0 <= pos && pos < _size);
        _size--;
        for (int i = pos; i < _size; i++) {
            array[i] = array[i + 1];
        }
    }

    void insertAt(int element, int pos) {
        assert(0 <= pos && pos <= _size);
        if((float)_size/(float)capacity == LOAD_FACTOR) {
            resize();
        }
        for(int i = _size; i > pos; i--) {
            array[i] = array[i-1];
        }
        _size++;
        array[pos] = element;
    }

    void append(T element) {
        insertAt(element, _size);
    }

    int size() {
        return _size;
    }

    // doubles capacity if it has to and deletes reference to current array.
    void resize() {
        capacity *= GROWTH_FACTOR;
        T *temp = new T[capacity];
        copy(array, array + _size, temp);
        delete [] array;
        array = temp;
    }

    T get(int pos) {
        return array[pos];
    }

    void pretty_print() {
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
    
    dynArr.deleteAt(5);
    

    cout << dynArr.size() << endl;
    
    return 0;
}
