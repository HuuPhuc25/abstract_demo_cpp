#include "tiny_int_field.h"

TinyIntField::TinyIntField()
{
}

TinyIntField::~TinyIntField()
{
}

TinyIntField::TinyIntField(int _index)
{
    this->index = _index;
    this->setDefaultData();
}

TinyIntField::TinyIntField(int _index,signed char _data)
{
    this->index = _index;
    this->mData = _data;
}

int
TinyIntField::getIndex()
{
    return this->index;
}
void
TinyIntField::setIndex(int index)
{
    this->index = index;
}

eDataType
TinyIntField::getDataType()
{
    return eTINYINT;
}

void*
TinyIntField::getData(void* p)
{
    if(p == NULL)
        return NULL;
    memcpy(p,&this->mData,sizeof(int8_t));
    return &this->mData;
}

void
TinyIntField::setData(void* _mData)
{
    memset(&mData, 0, sizeof(int8_t));
    memcpy(&mData, (int8_t*)_mData, sizeof(int8_t));
}

void
TinyIntField::setDataFrom(char* field)
{
    if(field != NULL)
    {
        memset(&mData, 0, sizeof(int8_t));
        this->mData = (int8_t) atoi(field);
    }
}

char*
TinyIntField::buildQuery( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_TINY_INT + strlen(columnName) + 3);
    sprintf(cmd, "%s = %d", columnName, this->mData);
    return cmd;
}

char*
TinyIntField::genJson( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_TINY_INT + strlen(columnName) + 7);
    sprintf(cmd, "\"%s\" = \"%d\"", columnName, this->mData);
    return cmd;
}

long
TinyIntField::getSizeData()
{
    return BUFFER_SIZE_OF_TINY_INT;
}

long
TinyIntField::getSizeQuery()
{
    return BUFFER_SIZE_OF_TINY_INT + MAX_SIZE_COLUMN_NAME + 3;
}

char*
TinyIntField::data2String()
{
    char* msg = (char*) malloc(BUFFER_SIZE_OF_TINY_INT);
    sprintf(msg, "%d", this->mData);
    return msg;
}

void
TinyIntField::setDefaultData()
{
    mData = 0;
}