#include "EasyLogger_test.h"
#include <stdio.h>
#include <windows.h>
#include "elog.h"

void EasyLogger_test(void)
{
    char test[] = "ddd" "eee" "222";

    elog_init();

    // elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME |ELOG_FMT_LINE|ELOG_FMT_FUNC|ELOG_FMT_DIR);
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    // elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
    // elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);

    elog_start();

    log_a("0 assert");
    log_e("1 error");
    log_w("2 warn");
    log_i("3 info");
    log_d("4 debug");
    log_v("5 verbose");

    elog_raw("%s = %d", test, sizeof(test));
}