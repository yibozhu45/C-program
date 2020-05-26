//
//  main.cpp
//  Word Count
//
//  Created by 懿帛   朱 on 5/25/20.
//  Copyright © 2020 懿帛   朱. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

vector<string> load_words(string filename)
{
    vector<string> words;
    ifstream infile(filename);
    
    if(infile)
    {
        string word;
        while(infile >> word)
        {
            string new_word;
            for(char c : word)
            {
                if(c == ','|| c == '.')
                {
                    continue;
                }
                else if(isupper(c))
                {
                    new_word += tolower(c);
                }
                else
                {
                    new_word +=c;
                }
            }
            words.push_back(new_word);
        }
        infile.close();
    }
    return words;
}

map<string, int> get_word_count(vector<string> words)
{
    map<string, int> word_count{};
    
    for(string word : words)
    {
        auto search = word_count.find(word);
        if(search == word_count.end())
        {
            word_count[word] = 1;
        }
        else
        {
            word_count[word] += 1;
        }
    }
    return word_count;
}

int main()
{
    cout << "The Word Counter program\n\n";
    
    string filename = "dickens.txt";
    auto words = load_words(filename);
    
    cout << words.size() << " WORDS: ";
    for(string word: words)
    {
        cout << word << " ";
    }
    
    cout << endl << endl;
    
    auto word_count = get_word_count(words);
    
    cout << word_count.size() << " UNIQUE WORDS: ";
    for (auto pair : word_count)
    {
        cout << pair.first << " ";
    }
    
    cout << endl << endl;
    
    cout << "COUNT PER WORD: ";
    for (auto pair : word_count)
    {
        cout << pair.first << "=" << pair.second << " ";
    }
    
    cout << endl << endl;
}
