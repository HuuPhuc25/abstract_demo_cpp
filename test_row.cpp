#include "test_row.h"

TestRow::TestRow(/* args */)
{
    this->index = 0;
    this->init();
}

TestRow::TestRow(int index)
{
    this->index = index;
    this->init();
}


void
TestRow::init()
{

    this->instanceOfField[eId_TestField] = &id;
    this->instanceOfField[eCode_TestField] = &code;
    this->instanceOfField[eInt_TestField] = &intField;
    this->instanceOfField[eBigInt_TestField] = &bigIntField;
    this->instanceOfField[eDate_TestField] = &dateField;
    this->instanceOfField[eString_TestField] = &stringField;

    for(int i= eMin_TestField; i < eMax_TestField; i++)
    {
        this->instanceOfField[i]->setIndex(i);
    }

}

TestRow::~TestRow()
{
}

int
TestRow::getIndex()
{
    return this->index;
}

void
TestRow::setIndex(int index)
{
    this->index = index;
}

void
TestRow::setData(TestData_t* data)
{
    id.setData(&data->id);
    code.setData(&data->code);
    intField.setData(&data->intField);
    bigIntField.setData(&data->bigIntField);
    dateField.setData(&data->dateField);
    stringField.setData(&data->stringField);
}


TestData_t
TestRow::getData()
{
    TestData_t data;

    id.getData(&data.id);
    code.getData(&data.code);
    intField.getData(&data.intField);
    bigIntField.getData(&data.bigIntField);
    dateField.getData(&data.dateField);
    stringField.getData(&data.stringField);

    return data;
}

void
TestRow::clearData()
{
    for(int i = eMin_TestField; i < eMax_TestField; i++)
    {
        this->instanceOfField[i]->setDefaultData();
    }
}

void
TestRow::show()
{
    int id;
    char code[MAX_SIZE_NVARCHAR_FIELD];
    int intField;
    long long big;
    tm date = {0};
    char stringField[MAX_SIZE_TEXT_FIELD];
    getInstanceField(eId_TestField)->getData(&id);
    getInstanceField(eCode_TestField)->getData(&code);
    getInstanceField(eInt_TestField)->getData(&intField);
    getInstanceField(eBigInt_TestField)->getData(&big);
    getInstanceField(eDate_TestField)->getData(&date);
    getInstanceField(eString_TestField)->getData(&stringField);

    printf("%d  - %d", this->index, id);
    printf("    - %s", code);
    printf("    - %d", intField);
    printf("    - %lld", big);
    printf("    - %s", date2String(date));
    printf("    - %s\n", stringField);
}

IField*
TestRow::getInstanceField(int indexField)
{
    return this->instanceOfField[index];
    /*
    switch (indexField)
    {
    case eId_TestField:
        return &id;

    case eCode_TestField:
        return &code;

    case eInt_TestField:
        return &intField;

    case eBigInt_TestField:
        return &bigIntField;

    case eDate_TestField:
        return &dateField;

    case eString_TestField:
        return &stringField;
    
    default:
        return NULL;
    }
     */
}

void
TestRow::setDataField(int index, void* p)
{
    this->instanceOfField[index]->setData(p);
    /*
    switch (index)
    {
    case eId_TestField:
        id.setData(p);
        break;
    case eCode_TestField:
        code.setData(p);
        break;

    case eInt_TestField:
        intField.setData(p);
        break;

    case eBigInt_TestField:
        bigIntField.setData(p);
        break;

    case eDate_TestField:
        dateField.setData(p);
        break;

    case eString_TestField:
        stringField.setData(p);
        break;
    }
     */
}

void
TestRow::setDataFieldFrom(int index, char* data)
{   
    this->instanceOfField[index]->setDataFrom(data);
    /*
    switch (index)
    {
    case eId_TestField:
        id.setDataFrom(data);
        break;
    case eCode_TestField:
        code.setDataFrom(data);
        break;

    case eInt_TestField:
        intField.setDataFrom(data);
        break;

    case eBigInt_TestField:
        bigIntField.setDataFrom(data);
        break;

    case eDate_TestField:
        dateField.setDataFrom(data);
        break;

    case eString_TestField:
        stringField.setDataFrom(data);
        break;
    }
     */
}

