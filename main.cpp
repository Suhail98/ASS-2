#include <iostream>
#include <sstream>
using namespace std;

class LabelGenerator
{
private:
    string prefix;
    int count;
public:
    LabelGenerator(string prefix , int count)
    {
        this -> prefix = prefix;
        this -> count = count;
    }
    string nextLabel()
    {
        stringstream s;
        s << count++;
        string counter = s.str();
        return prefix + counter;

    }

};
int main()
{
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++)
    {
        if (i > 0) cout << ", ";
        cout << figureNumbers.nextLabel();
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++)
    {
        if (i > 0) cout << ", ";
        cout << pointNumbers.nextLabel();
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++)
    {
        if (i > 0) cout << ", ";
        cout << figureNumbers.nextLabel();
    }
    cout << endl;
    return 0;
}
