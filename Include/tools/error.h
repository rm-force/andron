#pragma once


const char *IDX_ERR = "Index outside";
const char *MALLOC_ERR = "Could not allocate memory";
const char *ZERO_DIV_ERR = "Error dividing by zero";

void error(char *source, const char *reason);