#ifndef CRPOINTER_H
#define CRPOINTER_H

#include "memorystoragetype.h"

namespace CastleRoot{
namespace Mem{

class CrPointer
{
public:
    CrPointer() = default;
    CrPointer(const int index, const MemoryStorageType type);

    MemoryStorageType type() const;
    int index() const;

    //static CrPointer nonePointer();
private:
    int m_index = 0;
    MemoryStorageType m_type = MemoryStorageType::Object;
};

}
}

std::ostream& operator<<(std::ostream& out, const CastleRoot::Mem::CrPointer& p);

#endif // CRPOINTER_H
