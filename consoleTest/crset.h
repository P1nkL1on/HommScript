#ifndef CRSET_H
#define CRSET_H

#include "memorystoragetype.h"
#include <QVector>

namespace CastleRoot{
namespace Mem{

class CrSet
{
public:
    CrSet() = default;
    CrSet(const QVector<int> &indices, const MemoryStorageType type);

    MemoryStorageType type() const;
    QVector<int> indices() const;
private:
    const QVector<int> m_indices;
    const MemoryStorageType m_type = MemoryStorageType::Object;
};

}
}

#endif // CRSET_H
