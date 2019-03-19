#ifndef CROBJECT_H
#define CROBJECT_H

#include "crpointer.h"
#include <QVector>
#include <QString>

namespace CastleRoot{
namespace Mem{

class CrObject
{
public:
    CrObject() = default;
    int findIndexByName(const QString &name) const;
    CrPointer findValueByName(const QString &name) const;
    void addValue(const CrPointer &pointer, const QString &name);
    void removeValueByName(const QString &name);
    int legth() const;
    QVector<CrPointer> v() const;
    QVector<QString> names() const;

private:
    QVector<CrPointer> m_v;
    QVector<QString> m_names;
};

}
}

std::ostream& operator<<(std::ostream& out, const CastleRoot::Mem::CrObject& p);
#endif // CROBJECT_H
