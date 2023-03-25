#include <string>
#include <iostream>
#include <map>

using namespace std;

map<char, int> CountVowels(string word)
{
    map<char, int> data 
    { 
        {'a', 0}, 
        {'e', 0}, 
        {'i', 0},
        {'o', 0},
        {'u', 0}  
    };
    
    for(char character : word)
    {
        if (data.count(character) > 0)
            data[character]++;
    }


    return data;
}

int main(int argc, char const *argv[])
{
    string word;
    cin >> word;

    map<char, int> map = CountVowels(word);
    
    for (pair<char, int> pair : map)
    {
        if (pair.second > 0)
            cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}