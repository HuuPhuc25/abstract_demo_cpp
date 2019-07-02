#include "text_field.h"

TextField::TextField()
{
}

TextField::~TextField()
{
}

TextField::TextField(int _index)
{
    index = _index;
    setDefaultData();
}

TextField::TextField(int _index, char* _data)
{
    this->index = _index;
    memset(this->mData, 0, MAX_SIZE_TEXT_FIELD);
    strncpy(this->mData, _data, strlen(_data));
    this->mData[strlen(_data) - 1] = '\0';
}

int TextField::getIndex()
{
    return this->index;
}

void TextField::setIndex(int index)
{
    this->index = index;
}

eDataType TextField::getDataType()
{
    return eSTRING;
}

void*
TextField::getData(void* p)
{
    if(p == NULL)
        return NULL;
    memcpy(p,mData,strlen(mData));
    return &this->mData[0];
}

void
TextField::setData(void* _mData)
{
    memset(this->mData, 0, MAX_SIZE_TEXT_FIELD);
    strncpy(this->mData, (char*)_mData, strlen((char*) _mData));
}

void
TextField::setDataFrom(char* field)
{
    if( field != NULL)
    {
        memset(mData, 0, MAX_SIZE_TEXT_FIELD);
        strncpy(mData, field, strlen(field));
    }
}

char*
TextField::buildQuery(char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(strlen(this->mData) + strlen(columnName) + 5);
    sprintf(cmd, "%s = \'%s\'", columnName, this->mData);
    return cmd;
}

char*
TextField::genJson(char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(strlen(this->mData) + strlen(columnName) + 9);
    sprintf(cmd, "\"%s\" = \"%s\"", columnName, this->mData);
    return cmd;
}

long
TextField::getSizeData()
{
    return strlen(this->mData) + 2;
}

long
TextField::getSizeQuery()
{
    return (strlen(this->mData) + MAX_SIZE_COLUMN_NAME + 5);
}

char*
TextField::data2String()
{
    char* dst;
    dst = (char*) malloc(BUFFER_SIZE_OF_TEXT);
    sprintf(dst, "\'%s\'", this->mData);
    return dst;
}

void
TextField::setDefaultData()
{
    memset(&this->mData, 0, MAX_SIZE_TEXT_FIELD);
}

