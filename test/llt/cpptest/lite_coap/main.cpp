#include <cpptest.h>
#include <iostream>
#include <fstream>

#include "test_coap_core.h"
//#include "test_litecoap_port.h"


int main()
{
    Test::Suite ts;

    ts.add(std::auto_ptr<Test::Suite>(new TestCoapCore));
    //ts.add(std::auto_ptr<Test::Suite>(new TestLiteCoapPort));

    std::ofstream html;
    html.open("Result.htm");

    Test::HtmlOutput output;
    ts.run(output);
    output.generate(html);
    html.close();
}
