/* 
    LifeJS Duktape by Harommel OddSock
    JavaScript interpreter running under Duktape
    Extensions to Duktape, moreso to add libraries
*/

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
#include "lifedukext.h"

void duk_libregister(duk_context *ctx, const char *name, duk_function_list_entry *entries) {
	duk_push_object(ctx);
    for (int i = 0; entries[i].key != NULL; i++) {
        duk_push_c_function(ctx, entries[i].value, entries[i].nargs);
        duk_put_prop_string(ctx, -2, entries[i].key);
    }
    duk_put_global_string(ctx, name);
}

void duk_baseregister(duk_context *ctx, duk_function_list_entry *entries) {
    for (int i = 0; entries[i].key != NULL; i++) {
        duk_push_c_function(ctx, entries[i].value, entries[i].nargs);
        duk_put_global_string(ctx, entries[i].key);
    }
}