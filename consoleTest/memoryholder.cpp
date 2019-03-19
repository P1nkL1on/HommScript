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


}
