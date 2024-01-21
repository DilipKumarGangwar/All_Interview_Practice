#include <iostream>

template <typename T>
class Unique_ptr {
    T *res;

public:
    explicit Unique_ptr<T>(T *myRes = nullptr) : res(myRes) {}

    ~Unique_ptr() {
        std::cout << "Destructor called" << std::endl;
        delete res;
    }

    T &operator*() {
        return *res;
    }

    T *operator->() {
        return res;
    }

    T *get() {
        return res;
    }

    Unique_ptr<T>(Unique_ptr<T> &&other) {
        res = other.res;
        other.res = nullptr;
    }

    Unique_ptr<T> &operator=(Unique_ptr<T> &&other) {
        if (this != &other) {
            if (res)
                delete res;
            res = other.res;
            other.res = nullptr;
            std::cout << "Move assignment called" << std::endl;
        }
        return *this;
    }

    void reset(T *newRes = nullptr) {
        if (res != nullptr)
            delete res;
        res = newRes;
    }
};

template <typename T>
class Unique_ptr<T[]> {
    T *res;

public:
    explicit Unique_ptr<T[]>(T *myRes = nullptr) : res(myRes) {}

    ~Unique_ptr() {
        std::cout << "Array Destructor called" << std::endl;
        delete[] res;
    }

    T &operator[](size_t index) {
        return res[index];
    }

    T *get() {
        return res;
    }

    Unique_ptr<T[]>(Unique_ptr<T[]> &&other) {
        res = other.res;
        other.res = nullptr;
    }

    Unique_ptr<T[]> &operator=(Unique_ptr<T[]> &&other) {
        if (this != &other) {
            if (res)
                delete[] res;
            res = other.res;
            other.res = nullptr;
            std::cout << "Array Move assignment called" << std::endl;
        }
        return *this;
    }

    void reset(T *newRes = nullptr) {
        if (res != nullptr)
            delete[] res;
        res = newRes;
    }
};

int main() {
    Unique_ptr<int> p1(new int(42));
    std::cout << *p1 << std::endl;

    Unique_ptr<int[]> p2(new int[5]);
    p2[0] = 1;
    p2[1] = 2;
    p2[2] = 3;

    std::cout << p2[0] << " " << p2[1] << " " << p2[2] << std::endl;

    return 0;
}
