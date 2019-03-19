#ifndef CRVALUETYPES_H
#define CRVALUETYPES_H

#include "crobject.h"
#include "crpointer.h"
#include "crset.h"


namespace CastleRoot{
namespace Mem{

//Integer = 0,
//Float = 1,
//String = 2,
//Bool = 3,
//Set = 4,
//Pointer = 5,
//Object = 6

struct MemValueType
{
    MemoryStorageType type;
    union
    {
        int   *int_data;
        float *float_data;
        QString *string_data;
        bool *bool_data;
        CrSet *set_data;
        CrPointer *pointer_data;
        CrObject *object_data;
        void *ptr_data;
    };
};

}
}
std::ostream& operator<<(std::ostream& out, const CastleRoot::Mem::MemValueType& val);

#endif // CRVALUETYPES_H
