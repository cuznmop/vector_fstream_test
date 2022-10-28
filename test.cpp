#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void printVector(vector<unsigned char> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << (int)v[i] << " ";
    }
    cout << endl;
}

class TestDB
{
public:
    vector <unsigned char> d1;
    vector <unsigned char> d2;
    vector<vector <unsigned char>> c;
public:
    TestDB(int len)
    {
        for(int i=0; i<len; i++)
        {
            if (int(i/16) == 0)
            {
                d1.push_back(i);
            }
            else if(int(i/16) == 1)
            {
                d2.push_back(i);
            }
        }
        c.push_back(d1);
        c.push_back(d2);
    }

    void json_output()
    {
        ofstream ofs("test.json", ios::out);        
        if (ofs.is_open() == false)
        {   
            cout << "not open" << endl;
        }
        else
        {
            cout << "open" << endl;
        }
        cout << "test: print the vector" << endl;
        printVector(d1);
        printVector(d2);
        ofs << "{ ";
        for(int i=0; i<c.size(); i++)
        {
            ofs << "\"v";
            ofs << i;
            ofs << "\":[";
            int j;
            for(j=0; j<c[i].size() - 1; j++)
            {
                ofs << (int)c[i][j] << ", ";
            }
            ofs << (int)c[i][j] << "], " << endl;

        }
        ofs << "}";       

        ofs.close();
    }
};


void test()
{
    TestDB t(32);
    t.json_output();
}



int main()
{
    test();
}