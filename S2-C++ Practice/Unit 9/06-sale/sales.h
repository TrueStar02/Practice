/*第九章：编程练习 4 */
//sales.h
/* SALES头文件，定义了SALES名字空间，及相关的函数*/
namespace SALES
{
    const int QUARTERS = 4;
    struct Sales{
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    void setSales(Sales& s, const double ar[], int n);
    void setSales(Sales& s);
    void showSales(const Sales& s);
}
