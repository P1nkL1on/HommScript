#include "memoryholder.h"


using namespace std;
using namespace CastleRoot;
using namespace Mem;


MemoryHolder::test()
{
    m_ints.addValue(15, "value_0");
    m_ints.addValue(25, "value_1");
    m_ints.addValue(35, "value_2");
    m_ints.addValue(45, "value_3");

    m_ints.traceCout();

    m_pointers.addValue(CrPointer(2, MemoryStorageType::Integer), "*value_2*");
    m_pointers.addValue(CrPointer(0, MemoryStorageType::Integer), "*value_0*");
    m_pointers.addValue(CrPointer(0, MemoryStorageType::Pointer), "pointer to pointer *value_2*");

    m_pointers.traceCout();

    const auto v = getValue(2, MemoryStorageType::Integer);
    cout << v.int_data << endl;
}

MemValueType MemoryHolder::getValue(const int index, const MemoryStorageType &type) const
{
    switch (type){
    case MemoryStorageType::Integer : return {type, m_ints.getValueByIndex(index)};
    case MemoryStorageType::Float : return {type, m_floats.getValueByIndex(index)};
    case MemoryStorageType::Bool : return {type, m_strings.getValueByIndex(index)};
    case MemoryStorageType::String : return {type, m_bools.getValueByIndex(index)};
    case MemoryStorageType::Set : return {type, m_sets.getValueByIndex(index)};
    case MemoryStorageType::Pointer : return {type, m_pointers.getValueByIndex(index)};
    case MemoryStorageType::Object : return {type, m_object.getValueByIndex(index)};
    default:
        return {type, 0};
    }
}
