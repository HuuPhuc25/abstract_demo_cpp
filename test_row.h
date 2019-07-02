
#ifndef __TEST_ROW_H__
#define __TEST_ROW_H__

#include <stdarg.h>
#include <memory>
#include "int_filed.h"
#include "big_int_filed.h"
#include "date_field.h"
#include "nvar_char_field.h"
#include "text_field.h"

#define TEST_TABLE_NAME "tblTest"

// Change if this table is an orther table
/*
Name: eTestFields
Type: enum
Using: the index of the fields of this table
Note: the index of element must match with the index of testFieldNames
*/
typedef enum _eTestFields{ // e+ColumnName_tableName+Field
    eMin_TestField = 0,
    eId_TestField = 0,
    eCode_TestField,
    eInt_TestField,
    eBigInt_TestField,
    eDate_TestField,
    eString_TestField,
    eMax_TestField,
} eTestFields;

typedef struct _TestData
{
    int index = 0;
    int_field_t id;
    nvar_char_field_t(code);
    int_field_t intField;
    big_int_field_t bigIntField;
    date_field_t dateField;
    text_field_t(stringField);
} TestData_t;

/*
    Name: TestRow
    Header:     |   id      |   code(key)   |   intField    |   bigIntField     |   dateField   |   stringField     |
    SQLType:    |   int     |   nvarchar    |   int         |   long long       |   date        |   text            |
*/
class TestRow
{
private:
    int index;
    char* tableName = TEST_TABLE_NAME;

    IntField id;
    NVarCharField code;
    IntField intField;
    BigIntField bigIntField;
    DateField dateField;
    TextField stringField;

    IField* instanceOfField[eMax_TestField];
public:

public:
    TestRow();
    TestRow(int index);
    ~TestRow();
    void init();
    int getIndex();
    void setIndex(int index);
    void setDataField(int index, void* data);
    void setDataFieldFrom(int index, char* data);
    void setData(TestData_t* data);
    TestData_t getData();
    void clearData();
    void show();
    IField* getInstanceField(int indexField);

};

#endif