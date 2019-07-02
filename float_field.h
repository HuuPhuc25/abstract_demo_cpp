#ifndef __FLOAT_FIELD_H__
#define __FLOAT_FIELD_H__

#include "field.h"

class FloatField: public IField
{
    private:
        int index;
        float mData;

    public:
        FloatField(int _index, float _data);
        ~FloatField();
        FloatField();
        FloatField(int _index);

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

#endif //__FLOAT_FIELD_H__