#include "int_filed.h"

IntField::IntField()
{
}

IntField::~IntField()
{
}

IntField::IntField(int _index)
{
    this->index = _index;
    this->setDefaultData();
}

IntField::IntField(int _index, int _data)
{
    this->index = _index;
    this->mData = _data;
}

int
IntField::getIndex()
{
    return this->index;
}
void
IntField::setIndex(int index)
{
    this->index = index;
}

eDataType
IntField::getDataType()
{
    return eINT;
}

void*
IntField::getData(void* p)
{
    if(p == NULL)
        return NULL;
    memcpy(p,&mData,sizeof(int));
    return &mData;
}

void
IntField::setData(void* _mData)
{
    memset(&mData, 0, sizeof(int));
    this->mData = *((int*) _mData);
}

void
IntField::setDataFrom(char* field)
{
    /*
    if(field != NULL)
    {
        memset(&mData, 0, sizeof(int));
        mData = atoi(field);
    }
     */
}

char*
IntField::buildQuery( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_INT + strlen(columnName) + 3);
    sprintf(cmd, "%s = %d", columnName, this->mData);
    return cmd;
}

char*
IntField::genJson( char* columnName)
{
    char* cmd;
    cmd = (char*) malloc(BUFFER_SIZE_OF_INT + strlen(columnName) + 7);
    sprintf(cmd, "\"%s\" = \"%d\"", columnName, this->mData);
    return cmd;
}

long
IntField::getSizeData()
{
    return BUFFER_SIZE_OF_INT;
}

long
IntField::getSizeQuery()
{
    return BUFFER_SIZE_OF_INT + MAX_SIZE_COLUMN_NAME + 3;
}

char*
IntField::data2String()
{
    char* msg = (char*) malloc(BUFFER_SIZE_OF_INT);
    sprintf(msg, "%d", this->mData);
    return msg;
}

void
IntField::setDefaultData()
{
    mData = 0;
}