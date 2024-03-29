#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

using namespace std;

template <typename T> class Blob
{
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T& front();
     T& front() const;
    T& back();
     T& back() const;
     T& operator[](size_type i);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T> Blob<T>::Blob() : data(std::make_shared<std::vector<T >>()) { }
template <typename T> Blob<T>::Blob(std::initializer_list<T> il) :
    data(std::make_shared<std::vector<T>>(il)) { }

template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const
{
    if(i == data->size())
        throw std::out_of_range(msg);
}

template <typename T> T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}
template <typename T> void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T> T& Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}
template <typename T>  T& Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front();
}
template <typename T> T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}
template <typename T>  T& Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> class BlobPtr
{
public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
    T& operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
    }
    BlobPtr& operator++();
    BlobPtr& operator--();
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T> std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret.size())
        throw std::out_of_range(msg);
    return ret;
}
int main()
{
    cout << "Hello world!" << endl;
    /*StrBlob b1 = {"a", "an", "the"};
    b1.push_back("zoo");
    {
        StrBlob b2 = b1;
    }*/
    Blob<int> ia;
    Blob<int> ia1 = {0, 1, 2, 3, 4};
    Blob<std::string> sa;
    Blob<std::string> sa2 = {"a", "ba"};
    Blob<double> prices;
    return 0;
}
