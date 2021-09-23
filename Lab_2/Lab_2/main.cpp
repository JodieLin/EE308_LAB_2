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
    void TotalOutput( CountGroup &f, int level);
    void MatchKeyword( CountGroup &f, string words_file, queue<string> &s, fstream &fin);
    void KeywordMatch( CountGroup &f, queue<string> &s);
    void ReadFile(string & filename);
    
    string filename;
    int level;
    cout << "Please enter the location of the file: ";
    cin >> filename;
    cout << "Please enter the level you want to achieve: ";
    cin >> level;
    //Users enter the location of the file ana the level of the result.
    
    
    ReadFile( filename );
    string words_file = " ";
    fstream fin;
    fin.open(filename.c_str(), ios::in );
    CountGroup f;
    queue<string> Keyword_queue;
    MatchKeyword(f, words_file, Keyword_queue, fin);
    TotalOutput(f,  level);
    fin.close();
    //open the file, solve the problem of "\\"
    
}

void ReadFile(string & filename)
{
    int s = filename.length();
    stack <char> temp;
    while(s--)
    {
        temp.push(filename[s]);
    }
    filename = " ";
    while(!temp.empty())
    {
        filename += temp.top();
        if (temp.top() == '\\')
        {
            filename += '\\';
        }
        temp.pop();
    }
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
