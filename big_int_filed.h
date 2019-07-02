
#ifndef __BIG_INT_FIELD_H__
#define __BIG_INT_FIELD_H__

#include "field.h"

class BigIntField: public IField
{
    private:
        char columnName[MAX_SIZE_COLUMN_NAME];
        int index;
        long long mData;

    public:
        BigIntField(int _index, long long _data);
        ~BigIntField();
        BigIntField();
        BigIntField(int _index);

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

#endif //__BIG_INT_FIELD_H__