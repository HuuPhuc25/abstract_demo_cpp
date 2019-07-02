#ifndef __TEXT_FIELD_H__
#define __TEXT_FIELD_H__

#include "field.h"

class TextField: public IField
{
    private:
        int index;
        text_field_t(mData);

    public:
        TextField(int _index, char* _data);
        ~TextField();
        TextField();
        TextField(int _index);

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

#endif //__TEXT_FIELD_H__