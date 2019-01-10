#include <stdlib.h>
#include <string.h>
#include "Exception.h"

void throw(exc_code excCode) {
    if (excCode != NO_EXC) {
        longjmp(jmpBuff, excCode);
    }
}
