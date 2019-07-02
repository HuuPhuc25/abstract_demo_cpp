
#ifndef __NVAR_CHAR_FIELD_H__
#define __NVAR_CHAR_FIELD_H__

#include "field.h"

class NVarCharField: public IField
{
    private:
        int index;
        nvar_char_field_t(mData);

    public:
        NVarCharField(int _index, char* _data);
        ~NVarCharField();
        NVarCharField();
        NVarCharField(int _index);

        char* buildQuery( char* columnName);

        void* getData(void* p);
        void setData(void* _mData);
        void setDataFrom(char* field);
        void setDefaultData();

        int getIndex();
        void setIndex(int _index);
        
        eDataType getDataType();

        long getSizeData();
        long getSizeQuery();

        char* data2String();

        char* genJson(char* columnName);
};

#endif //__NVAR_CHAR_FIELD_H__