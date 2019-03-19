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


    template <typename T>
    inline T getValue(const CrPointer &pointer) const;

    template <typename T>
    inline T getValue(const int index, const MemoryStorageType &type) const;
};


}


}

// realiation of templates
// =======================
template<typename T>
T CastleRoot::Mem::MemoryHolder::getValue(const int index, const CastleRoot::Mem::MemoryStorageType &type) const
{
    using namespace CastleRoot::Mem;
    switch (type){
    case MemoryStorageType::Integer : return m_ints.getValueByIndex(index);
    case MemoryStorageType::Float : return m_floats.getValueByIndex(index);
    case MemoryStorageType::Bool : return m_strings.getValueByIndex(index);
    case MemoryStorageType::String : return m_bools.getValueByIndex(index);
    case MemoryStorageType::Set : return m_sets.getValueByIndex(index);
    case MemoryStorageType::Pointer : return m_pointers.getValueByIndex(index);
    case MemoryStorageType::Object : return m_object.getValueByIndex(index);
    default:
        return T(0);
    }
}
template<typename T>
T CastleRoot::Mem::MemoryHolder::getValue(const CrPointer &pointer) const
{
    return getValue<T>(pointer.index(), pointer.type());
}

#endif // MEMORYHOLDER_H
