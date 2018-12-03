#include <string>
#include <iostream>
#include "TagParser.h"

int main (int argc, char**argv)
{
    if (argc < 2) return 0;
    TagParser tagParser(argv[1]);

    auto tag = tagParser.getTagExpr();

    for (int i=0; i<tag.length(); i++)
    {
        std::cout << tagParser.getCharType(tag[i]) << std::endl;
    }
    return 0;
}

