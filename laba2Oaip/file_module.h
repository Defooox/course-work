#ifndef FILE_MODULE_H
#define FILE_MODULE_H

#include "stack_module.h"
#include <fstream>

void save_DB(Stack *stack, const char *filename);
void load_DB(Stack *stack, const char *filename);
void remove_DB(const char *filename);
std::ofstream new_DB(const char *filename);

#endif // FILE_MODULE_H