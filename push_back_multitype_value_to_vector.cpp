#include <algorithm>
#include <iostream>

class any
{
private:
    struct base {
        virtual ~base() {}
        virtual base* clone() const = 0;
    };
    template <typename T>
    struct data: base {
        data(T const& value): value_(value) {}
        base* clone() const { return new data<T>(*this); }
        T value_;
    };
    base* ptr_;
public:
    template <typename T> any(T const& value): ptr_(new data<T>(value)) {}
    any(any const& other): ptr_(other.ptr_->clone()) {}
    any& operator= (any const& other) {
        any(other).swap(*this);
        return *this;
    }
    ~any() { delete this->ptr_; }
    void swap(any& other) { std::swap(this->ptr_, other.ptr_); }

    template <typename T>
    T& get() {
        return dynamic_cast<data<T>&>(*this->ptr_).value_;
    }
};

int main()
{
    any a0(17);
    any a1(3.14);
    try { a0.get<double>(); } catch (...) {}
    a0 = a1;
    std::cout << a0.get<double>() << "\n";
}
