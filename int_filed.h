
#ifndef __INT_FIELD_H__
#define __INT_FIELD_H__

#include "field.h"

class IntField: public IField
{
    private:
        int index;
        int mData;

    public:
        IntField(int _index, int _data);
        ~IntField();
        IntField();
        IntField(int _index);

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

#endif //__INT_FIELD_H__