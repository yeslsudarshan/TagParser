#include "TagParser.h" 

void TagParser::getFsmState()
{
    FSM_STATE curState = UNKNOWN_STATE , prevState = UNKNOWN_STATE;
    CHAR_TYPE curChar = UNKNOWN_CHAR, prevChar = UNKNOWN_CHAR;

    for (int i = 0; i < tagString.length(); i++)
    {
        curChar = getCharType(tagString[i]); 

        switch (curState)
        {
            case UNKNOWN_STATE:
            case WHITESPACE_CHAR:
                break;

            case 

        }
    }



}

TagParser::CHAR_TYPE TagParser::getCharType(char c)
{
    if (isspace(c))
    {
        return WHITESPACE_CHAR;
    } 

    if (isalpha(c))
    {
        return ALPHA_CHAR;
    }

    if (isdigit(c))
    {
        return NUM_CHAR;
    }

    if(ispunct(c))
    {
        auto it = delim_map.find(c);

        return it != delim_map.end() ? 
                    it->second : UNKNOWN_CHAR;
    }

    return UNKNOWN_CHAR;
}
