#ifndef __TINY_INT_FIELD_H__
#define __TINY_INT_FIELD_H__

#include "field.h"

class TinyIntField: public IField
{
    private:
        int index;
        tiny_field_t mData;

    public:
        TinyIntField(int _index, signed char _data);
        ~TinyIntField();
        TinyIntField();
        TinyIntField(int _index);

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

#endif