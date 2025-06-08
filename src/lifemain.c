#include <vitasdk.h>
#include <stdio.h>
#include <stdbool.h>
#include "duktape/duktape.h"
#include "duktape/duk_config.h"
#include "duktape/duk_v1_compat.h"
#include "include/debugScreen.h"

int main(){
    duk_context *ctx = duk_create_heap_default();
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