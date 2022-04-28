# [Static Member] Seminar Logger2

# Description

SDCS will organize students to participate in the seminar。`curr_ people` off campus mysterious guests and organizers have confirmed their participation. Meanwhile, they have been waiting in the venue. There are `student_ num` students participated, and each student has to introduce himself. At the end of the event, the students will leave in the order of admission, and the guests and the organizer will leave after the final discussion.

Use the `Student` class to record the students. Please complete the `Student.cpp` so as to make the program achieve the corresponding record results.

SDCS将组织学生参加讨论会，已经有`curr_people`个校外神秘嘉宾以及举办方确定参与，同时他们已经在会场中等待。共有`student_num`个学生参加，每一个学生到场后都要进行一次自我介绍。活动结束后，学生按照入场的顺序依次退场，嘉宾以及举办方在最终商讨后最后离场。

用`Student`类来记录参加的学生，请完成`Student.cpp`文件的编写，使得程序能够达成对应的记录结果。

# Sample Input

In the first line, there are two numeric inputs, which are the number of organizers and guests (`curr_ people`), and the number of students in SDCS(`student_ num`).

In next `student_num` lines, each line has two inputs. The first input is indicate the gender of the student: if the student is a boy, it will be 1, otherwise, it's 0. The second input is a string, which indicates the name of the student

第一行有两个数字输入，分别为举办方与嘉宾的数目`curr_people`，以及SDCS中学生的数量`student_num`。

此后的`person_num`行中，每行都有2个输入，第一个int输入表示参与者的性别，如果是男生则为1，否则为0；第二个string输入表示参与者的姓名。

```
7 7
1 Jack
0 Lisa
1 Jackson
0 Rose
0 Jisoo
1 Jack
0 Jennie
```

# Sample Output

```
Hi! My name is Jack. I have no classmates here.
Hi! My name is Lisa. I have only 1 classmate here.
Hi! My name is Jackson. I have 2 classmates here.
Hi! My name is Rose. I have 3 classmates here.
Hi! My name is Jisoo. I have 4 classmates here.
Hi! My name is Jack. I have 5 classmates here.
Hi! My name is Jennie. I have 6 classmates here.
The number of people is 14. The number of students is 7. The number of girls is 4. The number of boys is 3.

The number of people is 13. The number of students is 6. The number of girls is 4. The number of boys is 2.
The number of people is 12. The number of students is 5. The number of girls is 3. The number of boys is 2.
The number of people is 11. The number of students is 4. The number of girls is 3. The number of boys is 1.
The number of people is 10. The number of students is 3. The number of girls is 2. The number of boys is 1.
The number of people is 9. The number of students is 2. The number of girls is 1. The number of boys is 1.
The number of people is 8. The number of students is 1. The number of girls is 1. The number of boys is 0.
The number of people is 7. The number of students is 0. The number of girls is 0. The number of boys is 0.
There is nobody here.
```
