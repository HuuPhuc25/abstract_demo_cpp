#include "big_int_filed.h"

BigIntField::BigIntField()
{
}

BigIntField::~BigIntField()
{
}

BigIntField::BigIntField(int _index)
{
    index = _index;
    setDefaultData();
}

BigIntField::BigIntField(int _index,long long _data)
{
    index = _index;
    mData = _data;
}

int
BigIntField::getIndex()
{
    return this->index;
}

void
BigIntField::setIndex(int _index)
{
    index = _index;
}

eDataType
BigIntField::getDataType()
{
    return eBIGINT;
}

void*
BigIntField::getData(void* p)
{
    if(p == NULL)
        return NULL;
    memcpy(p,&mData,sizeof(long long));
    return &mData;
}

void
BigIntField::setData(void* _mData)
{
    memset(&mData, 0, sizeof(long long));
    memcpy(&mData, (long long*)_mData, sizeof(long long));
}

void
BigIntField::setDataFrom(char* field)
{
    /*
    if(field != NULL)
    {
        memset(&mData, 0, sizeof(big_int_field_t));
        mData = atoll(field);
    }
     */
}

char*
BigIntField::buildQuery( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_LONG_LONG + strlen(columnName) + 3);
    sprintf(cmd, "%s = %lld", columnName, this->mData);
    return cmd;
}

char*
BigIntField::genJson( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_LONG_LONG + strlen(columnName) + 7);
    sprintf(cmd, "\"%s\" = \"%lld\"", columnName, this->mData);
    return cmd;
}

long
BigIntField::getSizeData()
{
    return BUFFER_SIZE_OF_LONG_LONG;
}

long
BigIntField::getSizeQuery()
{
    return BUFFER_SIZE_OF_LONG_LONG + MAX_SIZE_COLUMN_NAME + 3;
}

char*
BigIntField::data2String()
{
    char* msg = (char*) malloc(BUFFER_SIZE_OF_LONG_LONG);
    sprintf(msg, "%lld", this->mData);
    return msg;
}

void
BigIntField::setDefaultData()
{
    mData = 0;
}

