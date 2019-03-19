#ifndef MEMORYARRAY_H
#define MEMORYARRAY_H

#include <iostream>
#include <QVector>
#include <QString>

namespace CastleRoot{
namespace Mem{


template <typename T>
class MemoryArray
{
private:
    QVector<T> v;
    QVector<QString> names;
public:
    MemoryArray() = default;

    int findIndexByName(const QString &name) const;
    T findValueByName(const QString &name) const;

    void addValue(const T &val, const QString &name);
    void addValue(const T &val);
};


// =================================================
// =realisation=realisation=realisation=realisation=
// =================================================

template <typedef T>
int MemoryArray<T>::findIndexByName(const QString &name) const
{
    return names.indexOf(name);
}

template <typedef T>
T MemoryArray::findValueByName(const QString &name) const
{
    const int ind = names.indexOf(name);
    if (ind < 0)
        return T(0);
    return v[ind];
}

template <typedef T>
void MemoryArray::addValue(const T &val, const QString &name){
    v << val;
    names << name;
}

template <typedef T>
void MemoryArray::addValue(const T &val){
    addValue(val, QString("unnamed variable %1").arg(v.length()));
}

}
}
#endif // MEMORYARRAY_H
