#ifndef EXECUTE_H
#define EXECUTE_H
#include "stack.h"
#include "commands.h"
#include "runtime.h"

void executeCommand(runTime* rt, int command, int argument);

#endif
