
#ifndef __DATE_FIELD_H__
#define __DATE_FIELD_H__

#include "field.h"

class DateField: public IField
{
    private:
        int index;
        tm mData;

    public:
        DateField(int _index, tm _data);
        ~DateField();
        DateField();
        DateField(int _index);

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

#endif //__DATE_FIELD_H__