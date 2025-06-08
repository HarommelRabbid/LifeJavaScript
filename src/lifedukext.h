/* 
    LifeJS Duktape by Harommel OddSock
    JavaScript interpreter running under Duktape
*/

#ifndef LIFE_DUKTAPE_EXTENSIONS
#define LIFE_DUKTAPE_EXTENSIONS

#include <vitasdk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include "duktape/duktape.h"
#include "duktape/duk_config.h"
#include "duktape/duk_v1_compat.h"
#include "include/debugScreen.h"

void duk_libregister(duk_context *ctx, const char *name, duk_function_list_entry *entries);
void duk_baseregister(duk_context *ctx, duk_function_list_entry *entries);

#endif