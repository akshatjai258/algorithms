#include <iostream>

using namespace std;
#define INITIAL_CAPACITY 5

template <class T>
class dynamic_array {
    T *array;
    int MIN_CAPACITY = INITIAL_CAPACITY;
    int GROWTH_FACTOR = 2;
    int size;
    
public:
    // constructor init
    dynamic_array() {
        array = new T[MIN_CAPACITY];
        size = 0;
    }
    
    // append @ the end
    void append(T element) {
        if(size == MIN_CAPACITY) {
            resize();
        }
        array[size] = element;
        size++;
        
    }
    
    void deleteAt(int pos) {
        if((pos > size) || (pos < 0)) {
            cout << "Invalid index";
            return;
        }

        for(int i = pos; i <= size; i++) {
            array[i] = array[i+1];
        }
        size--;
    }
    
    void insertAt(int element, int pos) {
        if((pos > size) || (pos < 0)) {
            cout << "Invalid index";
            return;
        }
        
        if(size == MIN_CAPACITY) {
            resize();
        }
        
        size++;

        for(int i = size - 1; i >= pos; i--) {
            if(i == pos) {
                array[i] = element;
            } else {
                array[i] = array[i-1];
            }
        }
    }
    
    void printArray() {
        for(int i = 0; i < length(); i++) {
            cout << array[i];
        }
    }
    
    // returns size of array
    int length() {
        return size;
    }
    
    // doubles capacity if it has to and deletes reference to current array.
    void resize() {
        MIN_CAPACITY *= GROWTH_FACTOR;
        T *temp = new T[MIN_CAPACITY];
        copy(temp);
        delete [] array;
        array = temp;
        
    }
    
    // copies original array into temp
    void copy(T temp[]) {
        for(int i = 0; i < size; i++) {
            temp[i] = array[i];
        }
    }
    
    // returns element in x position.
    T get(int pos) {
        return array[pos];
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
    
    dynArr.deleteAt(6);
    

    cout << dynArr.length() << endl;
    
    return 0;
}
