#include "test_row.h"
#include "memory"
using namespace std;
int main(int argc, char const *argv[])
{
    TestRow row;
    row.setDataFieldFrom(eId_TestField, "1");
    row.setDataFieldFrom(eCode_TestField, "code 1");
    row.setDataFieldFrom(eInt_TestField, "60000");
    row.setDataFieldFrom(eBigInt_TestField, "10000000000");
    row.setDataFieldFrom(eDate_TestField, "1990-03-25");
    row.setDataFieldFrom(eString_TestField, "The life is not waiting");

    row.show();

    return 0;
}
