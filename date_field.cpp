#include "date_field.h"

DateField::DateField()
{
}

DateField::~DateField()
{
}

DateField::DateField(int _index)
{
    this->index = _index;
    this->setDefaultData();
}

DateField::DateField(int _index,tm _data)
{
    index = _index;
    mData = _data;
}

int DateField::getIndex()
{
    return this->index;
}

void DateField::setIndex(int index)
{
    this->index = index;
}

eDataType DateField::getDataType()
{
    return eDATE;
}

void*
DateField::getData(void* p)
{
    if(p == NULL)
        return NULL;
    memcpy(p,&this->mData,sizeof(tm));
    return &this->mData;
}

void
DateField::setData(void* _mData)
{
    memset(&mData, 0, sizeof(tm));
    memcpy(&mData, (tm*)_mData, sizeof(tm));
}

void
DateField::setDataFrom(char* field)
{
    if(field != NULL)
    {
        memset(&mData, 0, sizeof(tm));
        strptime(field, "%Y-%m-%d", &mData);
    }
}

char*
DateField::buildQuery(char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_DATE + strlen(columnName) + 3);

    sprintf(cmd, "%s = \'%s\'", columnName, date2String(this->mData));
    return cmd;
}

char*
DateField::genJson(char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_DATE + strlen(columnName) + 7);

    sprintf(cmd, "\"%s\" = \"%s\"", columnName, date2String(this->mData));
    return cmd;
}

long
DateField::getSizeData()
{
    return BUFFER_SIZE_OF_DATE;
}

long
DateField::getSizeQuery()
{
    return BUFFER_SIZE_OF_DATE + MAX_SIZE_COLUMN_NAME + 5;
}

char*
DateField::data2String()
{
    char* dst;
    dst = (char*) malloc(BUFFER_SIZE_OF_DATE);
    sprintf(dst, "\'%d-%d-%d\'", 1900 + this->mData.tm_year, this->mData.tm_mon+1,  this->mData.tm_mday);
    return dst;
}

void
DateField::setDefaultData()
{
    memset(&this->mData, 0, sizeof(tm));
}