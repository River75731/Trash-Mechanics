### 一些简单约定

- 不使用using namespace
- 不使用标准库以外的宏定义
- 尽量不抛异常，捕捉后进行处理即可
- 尽量不写inline（简单函数可以直接在.h中写出实体），实测跨cpp访问inline函数会报错

### const的使用

- 对于不会更改成员变量的函数均加上const后标，便于const的类实例访问

  eg.

  double Vec::getX() const {}

- 对于函数里不会更改的变量，使用const typename &variablename的格式定义，增强安全性和访问速度

  eg.

  double VecAngle(const Vec &v, const Vec &v1, const Vec &v2) {}

