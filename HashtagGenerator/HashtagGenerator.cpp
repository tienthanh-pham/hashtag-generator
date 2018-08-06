#include "HashtagGenerator.h"

HashtagGenerator::HashtagGenerator()
{

}

QString HashtagGenerator::generate(QString str)
{
    QString normal_str = generateNormal(str);
    QString no_space_str = generateNoSpace(normal_str);
    return normal_str + " " + no_space_str;
}

QString HashtagGenerator::generateNormal(QString str)
{
    QString result = "";
    if (str[0] != '#') result = "#";
    for (auto i : str)
    {
        if (i == ' ')
        {
            if (result[result.length()-1] != '#')
            {
                result = result + "_";
            }
        }
        else if (i == ',')
        {
            result = result + " #";
        }
        else
        {
            result = result + i;
        }
    }
    return result;
}

QString HashtagGenerator::generateNoSpace(QString str)
{
    QString result = "";
    bool isUpcase = false;
    for (auto i : str)
    {
        if (i != '_')
        {
            if (isUpcase)
            {
                result = result + i.toUpper();
                isUpcase = false;
            }
            else
            {
                result = result + i;
            }

        }
        if (i == '#' || i == '_')
        {
            isUpcase = true;
        }
    }
    return result;
}

