#include <cpptest.h>
#include <iostream>
#include <fstream>

// zz
#include "test_ota_flag.h"
#include "test_pcp.h"

int main()
{
    Test::Suite ts;

    ts.add(std::auto_ptr<Test::Suite>(new TestOta));
	ts.add(std::auto_ptr<Test::Suite>(new TestPcp));
    std::ofstream html;
    html.open("Result.htm");

    Test::HtmlOutput output;
    ts.run(output);
    output.generate(html);
    html.close();
}
