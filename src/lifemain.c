/* 
    LifeJS Duktape by Harommel OddSock
    JavaScript interpreter running under Duktape
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
#include "include/debugScreen.h"

static duk_ret_t duk_print(duk_context *ctx) {
    const char *text = duk_to_string(ctx, 0);
    printf(text);
    return 0;
}

static duk_ret_t duk_delay(duk_context *ctx) {
    float secs = duk_opt_number(ctx, 0, 0);
    sceKernelDelayThread(secs*1000*1000);
    return 0;
}

static duk_ret_t duk_delayCB(duk_context *ctx) {
    float secs = duk_opt_number(ctx, 0, 0);
    sceKernelDelayThreadCB(secs*1000*1000);
    return 0;
}

duk_function_list_entry base_lib[] = {
    {"print", duk_print, 1},
    {"delay", duk_delay, 1},
    {"delayCB", duk_delayCB, 1},
    {NULL, NULL, 0}
};

int main(){
    duk_context *ctx = duk_create_heap_default();
    duk_baseregister(ctx, base_lib);
    psvDebugScreenInit();
    if(duk_peval_file(ctx, "app0:main.js") != 0){
        psvDebugScreenClear(COLOR_DEFAULT_BG);
        psvDebugScreenSetFgColor(COLOR_RED);
        printf("LifeJS has encountered an error:\n%s\n", duk_safe_to_string(ctx, -1));
        psvDebugScreenSetFgColor(COLOR_WHITE);
        while(true){
            sceKernelDelayThread(1000*1000);
        }
    }
    //duk_pop(ctx);
    duk_destroy_heap(ctx);
    return 0;
}