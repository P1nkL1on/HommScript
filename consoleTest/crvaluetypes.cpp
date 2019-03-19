#include "crvaluetypes.h"

std::ostream& operator<<(std::ostream& out, const CastleRoot::Mem::MemValueType& val)
{
    using namespace CastleRoot::Mem;
    out << typeToStdString(val.type) << "(";
    switch (val.type){
        case MemoryStorageType::Integer : out << *val.int_data; break;
        case MemoryStorageType::Float : out << *val.float_data; break;
        case MemoryStorageType::Bool : out << *val.bool_data; break;
        case MemoryStorageType::String : out << (*val.string_data).toLocal8Bit().constData(); break;
        case MemoryStorageType::Set : out << *val.set_data; break;
        case MemoryStorageType::Pointer : out << *val.pointer_data; break;
        case MemoryStorageType::Object : out << *val.object_data; break;
    default:
        out << "???"; break;
    }
    out << ")";
    return out;
}
