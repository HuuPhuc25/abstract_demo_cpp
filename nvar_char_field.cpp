#include "nvar_char_field.h"

NVarCharField::NVarCharField()
{
}

NVarCharField::~NVarCharField()
{
}

NVarCharField::NVarCharField(int _index)
{
    this->index = _index;
    this->setDefaultData();
}

NVarCharField::NVarCharField(int _index, char* _data)
{
    index = _index;
    memset(mData, 0, MAX_SIZE_NVARCHAR_FIELD);
    strncpy(mData, _data, strlen(_data));
    mData[strlen(_data) - 1] = '\0';
}

int
NVarCharField::getIndex()
{
    return this->index;
}

void 
NVarCharField::setIndex(int index)
{
    this->index = index;
}

eDataType
NVarCharField::getDataType()
{
    return eNVARCHAR;
}

void*
NVarCharField::getData(void* p)
{
    if(p == NULL)
        return NULL;
    memcpy(p,this->mData,strlen(this->mData));
    return &this->mData[0];
}

void
NVarCharField::setData(void* _mData)
{
    memset(mData, 0, MAX_SIZE_NVARCHAR_FIELD);
    strncpy(mData, (char*)_mData, strlen((char*)_mData));
}

void
NVarCharField::setDataFrom(char* field)
{
    if(field != NULL)
    {
        memset(mData, 0, MAX_SIZE_TEXT_FIELD);
        strncpy(mData, field, strlen(field));
    }
}

char*
NVarCharField::buildQuery( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(strlen(this->mData) + strlen(columnName) + 5);
    sprintf(cmd, "%s = \'%s\'", columnName, this->mData);
    return cmd;
}

char*
NVarCharField::genJson( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(strlen(this->mData) + strlen(columnName) + 9);
    sprintf(cmd, "\"%s\" = \"%s\"", columnName, this->mData);
    return cmd;
}

long
NVarCharField::getSizeData()
{
    return strlen(this->mData) + 2;
}

long
NVarCharField::getSizeQuery()
{
    return (strlen(this->mData) + MAX_SIZE_COLUMN_NAME + 5);
}

char*
NVarCharField::data2String()
{
    char* dst;
    dst = (char*) malloc(BUFFER_SIZE_OF_NVAR_CHAR);
    sprintf(dst, "\'%s\'", this->mData);
    return dst;
}

void
NVarCharField::setDefaultData()
{
    memset(&this->mData, 0, MAX_SIZE_NVARCHAR_FIELD);
}

