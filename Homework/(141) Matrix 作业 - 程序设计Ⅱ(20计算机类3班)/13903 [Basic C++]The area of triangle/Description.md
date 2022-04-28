# [Basic C++]The area of triangle

# Description
给出平面内的三个点，求这三个点所围成的三角形的面积。

# Input
平面内三个点的坐标，保证输入三角形是合法的

# Output
三角形的面积，结果保留两位小数。
 
# Sample Input
0 0
0 1
1 0

# Sample Output
0.50

# Hint
求三角形的面积可用叉积公式，fabs(xA * yB - xB * yA) * 0.5，其中xA = x1 - x2; yA = y1 - y2; xB = x3 - x2; yB = y3 - y2.


