# LightCppReflection
LightCppReflection 是一个轻量级的C++反射库，用它你可以通过变量名来获取或修改成员变量。以此就可以很方便的将对象序列化成Json，Xml，或者生成Sql。由于LightCppReflection不需要依赖C++代码生成器，你无须修改自己的开发环境。
使用LightCppReflection，你只需将成员变量按照这种方式声明：
r(int a, a); //declare an int named a in class Test
然后可以通过以下方式来获取或者修改它的值
Test T; //实例化 Test
Test::setValue<int>(&t, "a", 5); //将t.a置为5
a = Test::getValue<int>(&t, "a");  // 获取t.a的值。a = 5

LightCppReflection is a light c++ reflection library. You can get or set a field by field's name. So it is very easy to serialize an object to Json or Xml, or generate SQL. Because this library dosen't depends on C++ code generator, you don't need to modify your develop environment.
Using LightCppReflection, you just need to declare a field like this:
r(int a, a); //declare an int named a in class Test
You can get or set it's value using:
Test T; //construct a Test
Test::setValue<int>(&t, "a", 5); //set t.a's value as 5
a = Test::getValue<int>(&t, "a");  // get t.a's value. a = 5
