#ifndef __FIELD_H__
#define __FIELD_H__

#include <stdio.h>
#include <string.h>
#include "../utility"
#include <stdint.h>
#include <stdlib.h>
#include "time.h"
#include "string"

#define MAX_SIZE_HOST 255
#define MAX_SIZE_DATA_BASE_NAME 255
#define MAX_SIZE_USER_NAME 255
#define MAX_SIZE_PASS 255
#define DEFAULT_PORT 3306

#define MAX_SIZE_TABLE_NAME     255
#define MAX_SIZE_COLUMN_NAME    255
#define MAX_SIZE_QUERY          65535
#define MAX_SIZE_TABLE_NAME     255
#define MAX_SIZE_TEXT_FIELD   65535
#define MAX_SIZE_NVARCHAR_FIELD 255
#define MAX_SIZE_DATE           12
#define BUFFER_SIZE_OF_LONG_LONG 30
#define BUFFER_SIZE_OF_TINY_INT 10
#define BUFFER_SIZE_OF_INT      15
#define BUFFER_SIZE_OF_FLOAT    20
#define BUFFER_SIZE_OF_DATE     12
#define BUFFER_SIZE_OF_TEXT     65537 // 65535 + 2 '_'
#define BUFFER_SIZE_OF_NVAR_CHAR 257 // 255 + 2 ' '

#define IN_PUT
#define OUT_PUT
#define SIZE_OF_FIELD_DATA sizeof(uint16_t)
#define DATA_BASE_NAME "travel_db"

#define tiny_field_t  int8_t
#define int_field_t       int
#define big_int_field_t   long long
#define date_field_t      tm
#define text_field_t(_text)   char _text[MAX_SIZE_TEXT_FIELD]
#define nvar_char_field_t(_nchar) char _nchar[MAX_SIZE_NVARCHAR_FIELD]

enum eDataType{
    eTINYINT = 0, // -128 .. 127
    eUINT16, // 0 .. 65535
    eINT, // uint32_t 0 .. 4,294,967,295
    eBIGINT, // unint64_t = unsign long long 0 .. 18,446,744,073,709,551,615
    eFLOAT,
    eDOUBLE,
    eDATE,
    eTIMESTAMP,
    eNVARCHAR,
    eSTRING,
};

char* getSizeOfFieldInBuffer(void* dst, uint16_t* t);
char* getFieldDataInBuffer(void* dst, void* src, int size);
int bufferAppendU16(void* dst, uint16_t t);
int bufferAppendStr(void* dst, char* str);
void printBuffer(char* buffer, int rows, int field);
void string2Date(char* src, tm* date);
char* date2String(tm _date);

class IField
{
public:

    virtual ~IField()
    {
        
    }

    virtual int getIndex() = 0;
    virtual void setIndex(int _index) = 0;
    
    virtual eDataType getDataType() = 0;

    virtual void* getData(void* p) = 0;

    virtual void setData(void* _mData) = 0;

    virtual void setDataFrom(char* field) = 0;

    virtual char* buildQuery( char* columnName) = 0;

    virtual long getSizeData() = 0;
    virtual long getSizeQuery() = 0;
    virtual char* data2String() = 0;
    virtual char* genJson(char* columnName) = 0;

    virtual void setDefaultData() = 0;
};

#endif //__FIELD_H__