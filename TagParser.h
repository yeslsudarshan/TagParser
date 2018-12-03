#include <string>
#include <iostream>
#include <ctype.h>
#include <vector>
#include <unordered_map>
class TagParser
{
    public:

        TagParser(const std::string aInStr) {tagString.assign(aInStr);}
        TagParser(const char* aInStr) {tagString.assign(aInStr);}

        std::string& getTagExpr() { return tagString;}

        typedef enum 
        {
            OR_CHAR = 0,
            AND_CHAR,
            COMMA_CHAR,
            NOT_CHAR,
            EQ_CHAR,
            ALPHA_CHAR,
            BRACKET_CHAR,
            NUM_CHAR,
            WHITESPACE_CHAR,
            BRACKET_OPEN_CHAR,
            BRACKET_CLOSE_CHAR,
            UNKNOWN_CHAR
        } CHAR_TYPE;

        typedef enum 
        {
            TAG_EXPR_TYPE_EQUAL,
            TAG_EXPR_TYPE_NOT_EQUAL,
            TAG_EXPR_TYPE_KEY_EXISTS, 
            TAG_EXPR_TYPE_KEY_NOT_EXISTS, 
            TAG_EXPR_TYPE_KEY_IN_LIST,
            TAG_EXPR_TYPE_KEY_NOT_IN_LIST
        } TAG_EXPR_TYPE;

        typedef struct object_tag_
        { 
            std::string key;
            std::vector<std::string> val;
            TAG_EXPR_TYPE tagExprType;
        } ObjectTag;

        typedef enum
        {
            


        }FSM_STATE;

        typedef std::vector <ObjectTag> AndList;
        typedef std::vector <AndList> TagExpr;

        TagParser::CHAR_TYPE getCharType(char c);
    private:
        std::string tagString;
        TagExpr tagExprParsed;
        std::unordered_map<char, CHAR_TYPE> delim_map = 
        {
            {'|', OR_CHAR},
            {'&', AND_CHAR},
            {',', COMMA_CHAR},
            {'!', NOT_CHAR},
            {'=', EQ_CHAR},
            {'(', BRACKET_OPEN_CHAR},
            {')', BRACKET_CLOSE_CHAR},
        };
};
