class DynamicArray {
public:
    int* arr;
    int m;
    int length;
    DynamicArray(int capacity) {
        if (capacity <= 0) {
            throw std::invalid_argument("cap must be greater than 0");
        }
        m = capacity;
        length = 0;
        arr = new int[m];
    }

    int get(int i) {
        if (i < 0 || i > length) 
        {
            return false;
        }
        return arr[i];
    }

    void set(int i, int n) {
        if (i < 0 || i >= length) 
        {
            throw std::out_of_range("Array is empty");
        }
        arr[i] = n;
    }

    void pushback(int n) {
        if (length == m) {
            resize();
        }
        arr[length] = n;
        length++;
    }

    int popback() {
        length--;
        return arr[length];
        
    }

    void resize() {
        m*=2;
        int* newarr = new int[m];
        for (int i = 0; i < length; i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return m;
    }
};
