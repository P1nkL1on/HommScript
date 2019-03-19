#include "crobject.h"

using namespace std;
using namespace CastleRoot;
using namespace Mem;

int CrObject::findIndexByName(const QString &name) const
{
    return m_names.indexOf(name);
}


CrPointer CrObject::findValueByName(const QString &name) const
{
    const int ind = findIndexByName(name);
    if (ind < 1)
        return CrPointer(-1, MemoryStorageType::Object);
    return m_v[ind];
}

void CrObject::addValue(const CrPointer &pointer, const QString &name)
{
    m_v << pointer;
    m_names << name;
}

void CrObject::removeValueByName(const QString &name)
{
    const int ind = findIndexByName(name);
    if (ind < 1)
        return;
    m_v.removeAt(ind);
    m_names.removeAt(ind);
}

int CrObject::legth() const
{
    return m_v.length();
}

QVector<CrPointer> CrObject::v() const
{
    return m_v;
}

QVector<QString> CrObject::names() const
{
    return m_names;
}

ostream &operator<<(ostream &out, const CrObject &p)
{
    out << "object { ";
    const auto v = p.v();
    const auto names = p.names();
    for (int i = 0; i < p.legth(); out << (i < p.legth() - 1? ", " : " }"), ++i)
        out << names[i].toLocal8Bit().constData() << "=" << v[i];
    return out;
}
