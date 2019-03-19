#ifndef MEMORYSTORAGETYPE_H
#define MEMORYSTORAGETYPE_H
#include <vector>
#include <iostream>

namespace CastleRoot{
namespace Mem{


enum class MemoryStorageType
{
    Integer = 0,
    Float = 1,
    String = 2,
    Bool = 3,
    Set = 4,
    Pointer = 5,
    Object = 6
};

static std::vector<std::string> typeNames = {"int", "float", "string", "bool", "set", "pointer", "object"};

inline std::string typeToStdString(const MemoryStorageType &type){
    return typeNames[static_cast<int>(type)];
}



}
}
#endif // MEMORYSTORAGETYPE_H
