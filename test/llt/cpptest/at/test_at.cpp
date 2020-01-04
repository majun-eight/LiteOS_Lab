#include "test_at.h"
#include <cstdio>
#include <cstring>

extern "C" {
#include "at.h"
#include <unistd.h>
int osal_init(void);
extern int at_oobregister(const char *name,const void *index,size_t len,fn_at_oob func,void *args);
extern int at_streammode_set(int mode);
}

using namespace std;

TEST_at::TEST_at()
{
    osal_init();

    TEST_ADD(TEST_at::test_at_init);
    TEST_ADD(TEST_at::test_at_oobregister);
    TEST_ADD(TEST_at::test_at_command);
    TEST_ADD(TEST_at::test_at_streammode_set);
}

void TEST_at::test_at_init()
{
    int ret;
    ret = at_init(NULL);
    TEST_ASSERT (ret == -1);

    ret = at_init("test_at_device");
    TEST_ASSERT (ret == 0);
}

static int test_device_callbak(void *args, void *data, size_t datalen)
{
    cout << "I`m callbak" << endl;
    return 0;
}

void TEST_at::test_at_oobregister()
{
    int ret;

    ret = at_oobregister("test_device", NULL, strlen("TEST+"), test_device_callbak, NULL);
    TEST_ASSERT (ret == -1);

    ret = at_oobregister("test_device", "TEST+", strlen("TEST+"), NULL, NULL);
    TEST_ASSERT (ret == -1);

    ret = at_oobregister("test_device", "TEST+", strlen("TEST+"), test_device_callbak, NULL);
    TEST_ASSERT (ret == 0);
}

void TEST_at::test_at_streammode_set()
{
    (void)at_streammode_set(1);
}

void TEST_at::test_at_command()
{
    int ret;
    ret = at_command(NULL, 0, "AT_test", NULL, 0, 1000);
    TEST_ASSERT (ret == -1);

    ret = at_command("ok", strlen("ok"), NULL, NULL, 0, 1000);
    TEST_ASSERT (ret == 0);

    ret = at_command("TEST+help", strlen("TEST+help"), "OK", NULL, 0, 1000);
    TEST_ASSERT (ret == 0);

    (void)at_streammode_set(1);
    ret = at_command("TEST+help", strlen("TEST+help"), "OK", NULL, 0, 1000);
    TEST_ASSERT (ret == 0);

}
