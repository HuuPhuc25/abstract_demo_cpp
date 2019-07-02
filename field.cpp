#include "field.h"


char* getSizeOfFieldInBuffer(void* dst, uint16_t* t)
{
    memcpy(t, dst, sizeof(uint16_t));
    return (char*) (dst +  sizeof(uint16_t));
}

char* getFieldDataInBuffer(void* dst, void* src, int size)
{
    memcpy(dst, (char*) src, size);
    return (char*) ( src + size); // return current offset of bufert
}



int bufferAppendU16(void* dst, uint16_t t)
{
    memcpy(dst, &t, sizeof(uint16_t));
    return sizeof(uint16_t);
}

int bufferAppendStr(void* dst, char* str)
{
    int len = 0;
    len += bufferAppendU16(dst, (uint16_t)strlen(str));
    memcpy((char*) dst + len, str, strlen(str));
    return (len + strlen(str));
}

void printBuffer(char* buffer, int rows, int field)
{
    char* offset = buffer;
    uint16_t sizeOfField = 0;
    for(int i=0; i < rows; i++)
    {
        for(int j= 0; j < field; j++)
        {
            if(offset != NULL)
            {
                offset = getSizeOfFieldInBuffer(offset, &sizeOfField);

                char tmp[sizeOfField] = {0};
                offset = getFieldDataInBuffer(&tmp[0], offset, sizeOfField);
                tmp[sizeOfField] = '\0';
                printf("%s\t", tmp);
            }
            printf("\n");
        }
    }
}

void string2Date(char* src, tm* date)
{
    memset(date, 0, sizeof(tm));
    strptime(src, "%Y-%m-%d", date);
}

char* date2String(tm _date)
{
    char* dst;
    dst = (char*) calloc(1, MAX_SIZE_DATE);
    sprintf(dst, "%d-%d-%d\0", 1900 + _date.tm_year, _date.tm_mon+1,  _date.tm_mday);
    return dst;
}