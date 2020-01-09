/**
 * Copyright (c) <2018>, <Huawei Technologies Co., Ltd>. All rights reserved.
 *
 *  DATE        AUTHOR      INSTRUCTION
 *  2020-1-8    maminjie    The first version
 */

#include "test_tickless.h"

#include "los_adapter.h"
#include "los_tickless.h"

#include <unistd.h>

extern "C"
{
#include "osal.h"
#include "los_tickless.ph"

    extern BOOL g_bTickIrqFlag;
}

/* functions */

TestTickless::TestTickless()
{
    osal_init();

    LOS_TicklessEnable();

    TEST_ADD(TestTickless::test_demo);
}

TestTickless::~TestTickless()
{
    LOS_TicklessDisable();
}

void TestTickless::setup()
{

}

void TestTickless::tear_down()
{

}

static int idle_task(void *args)
{
    while (1)
    {
        osTicklessHandler();
    }
}

void TestTickless::test_demo(void)
{
    osTicklessStart();

    void *handle = osal_task_create("idle", idle_task, 0, 0x800, NULL, 1);
    if (NULL == handle)
    {
        return;
    }

    g_bTickIrqFlag = 0;
    sleep(1);

    g_bTickIrqFlag = 1;
    sleep(1);

    osal_task_kill(handle);

    usleep(100000); // wait task exit
}
