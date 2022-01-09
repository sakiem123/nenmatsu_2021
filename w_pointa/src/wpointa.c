#include "wpointa.h"
#include "log.h"
#include "share.h"

int wpointa_test(void)
{
    int ret = WP_OK;
    struct wptst **wptst;
    struct wptst *ptst;
    const char cpchar[10] = "HenkanMae";
    LDEBUG_LOG("START");
#if DEBUG_MODE
    LDEBUG_LOG("ptst pointer:%p", ptst);
    LDEBUG_LOG("wptst pointer:%p", wptst);
#endif
    ptst = (struct wptst*)malloc(sizeof(struct wptst));
    wptst = &ptst;
    memset(ptst,0,sizeof(struct wptst));
    strncpy(ptst->name, cpchar, sizeof(cpchar));
    ptst->number = 13221;
    ptst->age = 19;
#if DEBUG_MODE
    LDEBUG_LOG("ptst->name:%s",ptst->name);
    LDEBUG_LOG("ptst->number:%d",ptst->number);
    LDEBUG_LOG("ptst->age:%d",ptst->age);
#endif
    ret = phenkan(wptst);
#if DEBUG_MODE
    LDEBUG_LOG("ptst->name:%s",ptst->name);
    LDEBUG_LOG("ptst->number:%d",ptst->number);
    LDEBUG_LOG("ptst->age:%d",ptst->age);
#endif
    free(*wptst);
    LDEBUG_LOG("END");

    return ret;
}


int phenkan(struct wptst **wp)
{
    struct wptst *wphenkan;
    char cpchar[10] = "henkanATO";
    int ret = WP_OK;

    wphenkan = (struct wptst*)malloc(sizeof(struct wptst));
    strncpy(wphenkan->name, cpchar, sizeof(cpchar));
    wphenkan->number = 483221;
    wphenkan->age = 28;
#if DEBUG_MODE
    LDEBUG_LOG("wphenkan->name:%s",wphenkan->name);
    LDEBUG_LOG("wphenkan->number:%d",wphenkan->number);
    LDEBUG_LOG("wphenkan->age:%d",wphenkan->age);
#endif
    *wp = wphenkan;
    return ret;

}