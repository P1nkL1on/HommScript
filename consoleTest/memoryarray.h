#ifndef MEMORYARRAY_H
#define MEMORYARRAY_H

#include <iostream>
#include <QVector>
#include <QString>
#include <QDebug>

namespace CastleRoot{
namespace Mem{


template <typename T>
class MemoryArray
{
private:
    QVector<T*> v;
    QVector<QString> names;
public:
    MemoryArray() = default;

    int findIndexByName(const QString &name) const;
    T * findValueByName(const QString &name) const;
    T * getValueByIndex(const int index) const;

    void addValue(const T &val, const QString &name);
    void addValue(const T &val);

    void setValue(const int index, const T &newVal);

    void removeValueByName(const QString &name);
    void traceCout() const;
    int  length() const;
};


// =================================================
// =realisation=realisation=realisation=realisation=
// =================================================

template <typename T>
int MemoryArray<T>::findIndexByName(const QString &name) const
{
    return names.indexOf(name);
}

template <typename T>
T * MemoryArray<T>::findValueByName(const QString &name) const
{
    const int ind = names.indexOf(name);
    if (ind < 0)
        return T(0);
    return v[ind];
}

template<typename T>
T * MemoryArray<T>::getValueByIndex(const int index) const
{
    if (index < 0 || index >= v.length())
        throw std::out_of_range("Out of range exception! Found ub MemoryArray::getValueByIndex!");
    return v[index];
}

template <typename T>
void MemoryArray<T>::addValue(const T &val, const QString &name){
    v << new T(val);
    names << name;
}

template <typename T>
void MemoryArray<T>::addValue(const T &val){
    addValue(val, QString("unnamed variable %1").arg(v.length()));
}

template<typename T>
void MemoryArray<T>::setValue(const int index, const T &newVal)
{
    if (index < 0 || index >= v.length())
        throw std::out_of_range("Memory array out of range at setValue method");

    v[index] = newVal;
}

template<typename T>
void MemoryArray<T>::removeValueByName(const QString &name)
{
    const int ind = findIndexByName(name);
    if (ind < 0)
        return;
    v.removeAt(ind);
    names.removeAt(ind);
}

template<typename T>
void MemoryArray<T>::traceCout() const
{
    std::cout << "Mem array: (" << v.length() << ")" << std::endl;
    for (int i = 0; i < v.length(); ++i)
        std::cout << "  " << names[i].toLocal8Bit().constData() << " = " << *v[i] << std::endl;
}

template<typename T>
int MemoryArray<T>::length() const
{
    return v.length();
}

}
}
#endif // MEMORYARRAY_H
