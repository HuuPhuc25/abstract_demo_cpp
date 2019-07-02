#include "float_field.h"

FloatField::FloatField()
{
}

FloatField::~FloatField()
{
}

FloatField::FloatField(int _index)
{
    index = _index;
    setDefaultData();
}

FloatField::FloatField(int _index, float _data)
{
    index = _index;
    mData = _data;
}

int FloatField::getIndex()
{
    return this->index;
}
void FloatField::setIndex(int index)
{
    this->index = index;
}

eDataType FloatField::getDataType()
{
    return eFLOAT;
}

void*
FloatField::getData(void* p)
{
    if(p == NULL)
        return NULL;
    memcpy(p,&mData,sizeof(float));
    return &this->mData;
}

void
FloatField::setData(void* _mData)
{
    memset(&mData, 0, sizeof(float));
    memcpy(&mData, (float*)_mData, sizeof(float));
}

void
FloatField::setDataFrom(char* field)
{
    if(field != NULL)
    {
        memset(&mData, 0, sizeof(float));
        mData = atof(field);
    }
}

char*
FloatField::buildQuery( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_FLOAT + strlen(columnName) + 3);
    sprintf(cmd, "%s = %f", columnName, this->mData);
    return cmd;
}

char*
FloatField::genJson( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_FLOAT + strlen(columnName) + 7);
    sprintf(cmd, "\"%s\" = \"%f\"", columnName, this->mData);
    return cmd;
}

long
FloatField::getSizeData()
{
    return BUFFER_SIZE_OF_FLOAT;
}

long
FloatField::getSizeQuery()
{
    return BUFFER_SIZE_OF_FLOAT + MAX_SIZE_COLUMN_NAME + 3;
}

char*
FloatField::data2String()
{
    char* msg = (char*) malloc(BUFFER_SIZE_OF_FLOAT);
    sprintf(msg, "%f", this->mData);
    return msg;
}

void
FloatField::setDefaultData()
{
    this->mData = 0.0;
}