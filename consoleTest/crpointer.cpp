#include "crpointer.h"

using namespace CastleRoot;
using namespace Mem;
using namespace std;

CrPointer::CrPointer(const int index, const MemoryStorageType type):
    m_index(index),
    m_type(type)
{
}

MemoryStorageType CrPointer::type() const
{
    return m_type;
}

int CrPointer::index() const
{
    return m_index;
}


//CrPointer CrPointer::nonePointer()
//{
//    return CrPointer(-1, MemoryStorageType::Objects);
//}

ostream &operator<<(ostream &out, const CrPointer &p)
{
    out << "pointer { on " << p.index()<< " in " << Mem::typeToStdString(p.type()) << " }";
    return out;
}
