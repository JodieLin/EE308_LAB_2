//  MU_ID:19105754
//  FZU_ID:831901114
//  Lab_2.cpp
//  Lab_2
//
//  Created by Jodie Lin on 2021/9/22.
//

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <ctype.h>

using namespace std;

const string Keywords[32] =
{
    "auto", "double", "int", "struct", "break", "else", "long","switch",
    "case", "enum", "register", "typedef", "char", "extern", "return", "union",
    "const", "float", "short", "unsigned", "continue", "for", "signed", "void",
    "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"
};

struct CountGroup
{
    int count = 0;
    int count_if_else = 0;
    int count_case = 0;
    int count_switch_case = 0;
    int count_if_elseif_else = 0;
};

int main()
{
    void
}

void ReadFile(string & filename)
{
    
}

void KeywordsMatch(CountGroup &f, queue<string> & keyword_queue)
{
    
}

void TotalOutput(CountGroup &f, int level)
{
    
}

void MatchKeyword(CountGroup &f, string words_file, queue<string> &keyword_queue, fstream &fin)
{
    
}
