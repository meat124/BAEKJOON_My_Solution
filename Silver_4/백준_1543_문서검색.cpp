#include <iostream>
#include <string>

int Find_Word(std::string doc, std::string word)
{
    if (doc.size() < word.size())
        return 0;
    for (size_t i = 0; i < doc.size() - word.size() + 1; i++)
    {
        if (doc.substr(i, word.size()) == word)
        {
            if (i + word.size() > doc.size())
                return 1;
            else
                return 1 + Find_Word(doc.substr(i + word.size()), word);
        }
    }
    return 0;
}

int main()
{
    std::string doc, word;
    std::getline(std::cin, doc);
    std::getline(std::cin, word);

    std::cout << Find_Word(doc, word);

    return 0;
}