#include "memoryholder.h"


using namespace std;
using namespace CastleRoot;
using namespace Mem;


MemoryHolder::test()
{
    m_floats.addValue(15, "value_0");
    m_floats.addValue(25, "value_1");
    m_floats.addValue(35, "value_2");
    m_floats.addValue(45, "value_3");

    m_floats.traceCout();

    m_pointers.addValue(CrPointer(2, MemoryStorageType::Float), "*value_2*");
    m_pointers.addValue(CrPointer(0, MemoryStorageType::Integer), "*value_0*");
    m_pointers.addValue(CrPointer(0, MemoryStorageType::Pointer), "pointer to pointer *value_2*");

    m_pointers.traceCout();

    const auto v = *getValue(2, MemoryStorageType::Pointer).pointer_data;
    const auto b = getValueToPointer0(v);
    cout << b << endl;
}

MemValueType MemoryHolder::getValue(const CrPointer &pointer) const
{
    return getValue(pointer.index(), pointer.type());
}

MemValueType MemoryHolder::getValue(const int index, const MemoryStorageType &type) const
{
    MemValueType res;
    res.type = type;
    switch (type){
        case MemoryStorageType::Integer :   res.int_data = m_ints.getValueByIndex(index);break;
        case MemoryStorageType::Float :     res.float_data = m_floats.getValueByIndex(index);break;
        case MemoryStorageType::Bool :      res.bool_data = m_bools.getValueByIndex(index);break;
        case MemoryStorageType::String :    res.string_data = m_strings.getValueByIndex(index);break;
        case MemoryStorageType::Set :       res.set_data = m_sets.getValueByIndex(index);break;
        case MemoryStorageType::Pointer :   res.pointer_data = m_pointers.getValueByIndex(index);break;
        case MemoryStorageType::Object :    res.object_data = m_object.getValueByIndex(index);break;
    default:
        return res;
    }
    return res;
}

MemValueType MemoryHolder::getValueToPointer0(const CrPointer &pointer) const
{
    cout << pointer << endl;
    MemValueType res = getValue(pointer);
    if (res.type != MemoryStorageType::Pointer)
        return res;
    return getValueToPointer0(*res.pointer_data);
}
