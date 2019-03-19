#include "crset.h"
using namespace CastleRoot;
using namespace Mem;

CrSet::CrSet(const QVector<int> &indices, const MemoryStorageType type):
    m_indices(indices),
    m_type(type)
{

}

MemoryStorageType CrSet::type() const
{
    return m_type;
}

QVector<int> CrSet::indices() const
{
    return m_indices;
}

