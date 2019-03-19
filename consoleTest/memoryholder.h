#ifndef MEMORYHOLDER_H
#define MEMORYHOLDER_H

#include "memoryarray.h"
#include "crvaluetypes.h"

namespace CastleRoot{
namespace Mem{

class MemoryHolder
{
public:
    MemoryHolder() = default;
    test();
private:
    MemoryArray<int> m_ints;
    MemoryArray<float> m_floats;
    MemoryArray<QString> m_strings;
    MemoryArray<bool> m_bools;

    MemoryArray<CrSet> m_sets;
    MemoryArray<CrPointer> m_pointers;
    MemoryArray<CrObject> m_object;

    MemValueType getValue(const CrPointer &pointer) const;
    MemValueType getValue(const int index, const MemoryStorageType &type) const;
    MemValueType getValueToPointer0(const CrPointer &pointer) const;
};


}


}


#endif // MEMORYHOLDER_H
