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
    int case_number = 0;
    int count_switch_case = 0;
    int count_if_elseif_else = 0;
    int count_case[100] = {0};
};

int main()
{
    void TotalOutput( CountGroup &f, int level);
    void Match( CountGroup &f, string words_file, queue<string> &s, fstream &fin);
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
    Match(f, words_file, Keyword_queue, fin);
    TotalOutput(f,  level);
    fin.close();
    //open the file, solve the problem of "\\"
    
}

//open the file and deal with the text of the file.
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

//using queue ot judge whether the keywords appear in the file.
void KeywordsMatch(CountGroup &f, queue<string> & keyword_queue)
{
    int i = 0;
    int j = 0;
    stack <string> temp;
    while(!keyword_queue.empty())
    {
        if(keyword_queue.front() == "if")
        {
            temp.push(keyword_queue.front());
            keyword_queue.pop();
        }
        else if (keyword_queue.front() == "elseif")
        {
            temp.push(keyword_queue.front());
            keyword_queue.pop();
        }
        else if (keyword_queue.front() == "else")
        {
            if(temp.top() == "if")
            {
                i++;
                f.count_if_else++;
                temp.pop();
            }
            else
            {
                while(temp.top() == "elseif" && !temp.empty())
                {
                    temp.pop();
                }
                if(!temp.empty())
                {
                    j++;
                    f.count_if_elseif_else++;
                    temp.pop();
                }
            }
            keyword_queue.pop();
        }
        else if(keyword_queue.front() == "switch")
        {
            keyword_queue.pop();
            while((keyword_queue.front() == "case" || keyword_queue.front() == "break" ||keyword_queue.front() == "default") && !keyword_queue.empty())
            {
                if(keyword_queue.front() == "case")
                {
                    f.count_case[f.case_number]++;
                    keyword_queue.pop();
                }
                f.case_number++;
            }
        }
        else
        {
            keyword_queue.pop();
        }
    }
}

//setup the Output of the project to achieve the requirement;
void TotalOutput(CountGroup &f, int level)
{
    void Output2(CountGroup &f);
    void Output3(CountGroup &f);
    void Output4(CountGroup &f);

    //output the total number of keywords of the file.
    cout << "total num: " << f.count << endl;
    if (level == 2)
        Output2(f);
    else if (level == 3)
    {
        Output2(f);
        Output3(f);
    }
    else
    {
        Output2(f);
        Output3(f);
        Output4(f);
    }
}

void Output2(CountGroup &f)
{
    int i = f.case_number;
    int j = 0;
    cout << "switch num: " << f.count_switch_case << endl;
    cout << "case num: ";
    while(i--)
    {
        cout << f.count_case[j] << ' ';
        j++;
    }
    cout << endl;
}
void Output3(CountGroup &f)
{
    cout << "if-else num: " << f.count_if_else << endl;
}
void Output4(CountGroup &f)
{
    cout << "if-elseif-else num: " << f.count_if_elseif_else << endl;
}


void Match(CountGroup &f, string words_file, queue<string> &keyword_queue, fstream &fin)
{
    while(fin >> words_file)
    {
        if(words_file[0] == '/' && words_file[1] == '/')
        {
            cout << "//   " << words_file << endl;
            getline(fin, words_file);
            fin >> words_file;
            //to match the next line and make the fin >> words_file become unavaliable.
        }
        else if(words_file[0] == '/' && words_file[1] == '*')
        {
            while(fin >> words_file)
            {
                if(words_file[words_file.size()-2] == '*' && words_file[words_file.size()-1] == '/')
                    break;
            }
        }
    }
    int index = 0;
    int size_words_file = words_file.size();
    string temp_string;
    for(int i = 0; i < size_words_file-1 ; i++)
    {
        if(!isalpha(words_file[i]) && isalpha(words_file[i+1]))
            index = i+1;
        if((isalpha(words_file[i]) && !isalpha(words_file[i+1])) || (i+1 == size_words_file-1 && isalpha(words_file[i+1])))
        {
            if(isalpha(words_file[i]) && !isalpha(words_file[i+1]))
                temp_string = words_file.substr(index, i+1-index);
            else
                temp_string = words_file.substr(index, i+2-index);
            for( int j = 0; j < 32; j++ )
            {
                if(temp_string == Keywords[j])
                {
                    if(temp_string != "else")
                    {
                        keyword_queue.push(temp_string);
                        f.count++;
                        if(temp_string == "switch")
                            f.count_switch_case++;
                    }
                    else
                    {
                        f.count++;
                        //to provent from the condition "else{if}";
                        if(words_file[4] == '{')
                        {
                            keyword_queue.push("else");
                        }
                        else
                        {
                            fin >> words_file;
                            i++;
                            if((words_file[0] == 'i' && words_file[1] == 'f' && words_file[2] == '(') || words_file == "if")
                            {
                                keyword_queue.push("elseif");
                                f.count++;
                            }
                        }
                    }
                    break;
                }
            }
            index = 0;
            break;
            }
        }
}
