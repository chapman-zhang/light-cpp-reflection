#include "ref.h" // You need to include ref.h

class Test
{
public:
    REF_DECLARE(Test);  //nessesary

    Test(){}; //a default constructor is nessesary
    void init(int d, char* s, char* str) 
    {
        a = d;
        memset(this->s, 0, 10);
        memcpy_s(this->s, 9, s, 9);
        this->str = str;
    }

private:
    r(int a, a);   // You need to declare a field like this.
    r(char s[10], s);
    r(std::string str, str);
};

REF_IMPEL(Test)  //nessesary

void main()
{

    Test t;
    t.init(10, "sdfsdfsdfsdfsdf", "abc");


    int a = Test::getValue<int>(&t, "a"); // a = 10
    Test::setValue<int>(&t, "a", 5);
    a = Test::getValue<int>(&t, "a");  // a = 5

    auto s = Test::getValue<char[10]>(&t, "s"); //s = "sdfsdfsdfsdfsdf"
    memcpy_s(s, 9, "abcabcabc", 9);
    s = Test::getValue<char[10]>(&t, "s"); //s = "abcabcabc"

    std::string str = Test::getValue<std::string>(&t, "str"); // str = "abc"
    Test::setValue<std::string>(&t, "str", "efd");
    str = Test::getValue<std::string>(&t, "str");  //str = "efd"

}
