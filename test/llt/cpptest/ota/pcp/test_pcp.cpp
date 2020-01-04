#include "test_pcp.h"
 
#include <cstring>

extern "C"
{
#include "ota_flag.h"
#include "ota_adaptor.h"
#include "string.h"
#include "hal_flash.h"
#include "osal.h"
#include "pcp.h"

extern int osal_init(void);

}

TestPcp::TestPcp()
{
    TEST_ADD(TestPcp::test_ota_pcp_init);

}

TestPcp::~TestPcp()
{

}

void TestPcp::test_ota_pcp_init(void)
{
ota_pcp_init(NULL);
}