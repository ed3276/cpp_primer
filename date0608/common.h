#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

template <typename T> bool compare(const T &t1, const T &t2)
{
    if (t1 < t2) return -1;
    if (t2 < t1) return 1;
    return 0;
}

extern template bool compare(const int&, const int&);//ģ��ʵ��������
//template bool compare(const int&, const int&);//ģ��ʵ��������
#endif // COMMON_H_INCLUDED
