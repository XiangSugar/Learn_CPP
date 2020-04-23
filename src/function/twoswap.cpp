// twoswap.cpp -- specialization overrides a template

#include <iostream>

template <typename T> void Swap(T &a, T &b);

struct job
{
    char name[40];
    double salary;
    int floor;
};

//explicit specialization  显式具体化
template<> void Swap<job>(job &j1, job &j2);

void Show(const job &j);

int main()
{
    using namespace std;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler genetated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 78060.72, 9};
    cout << "Before job swapping:\n";
    Show(sue);
    Show(sidney);
    Swap(sue, sidney);
    cout << "After job swapping:\n";
    Show(sue);
    Show(sidney);

    cin.get();
    return 0;
}

template <typename T> void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

//swap just the salary and floors fields of a job structure
template<> void Swap<job>(job &j1, job &j2)
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(const job &j)
{
    std::cout << j.name << ": $" << j.salary
              << " on floor " << j.floor << std::endl;
}


/*要注意区分显示具体化和显式实例化两个概念
template void Swap<int>(int, int)  // explicit instantiation
编译器看到上述申明，将使用Swap()模板生成一个使用int类型的实例，也就是说：
“使用Swap()模板生成int类型的函数的定义”
此外，还可通过函数来创建显示实例化

template <> void Swap<int>(int &, int &) //explicit specialization
template <> void Swap(int &, int &)      //explicit specialization
*/