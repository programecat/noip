## 基本数据结构

### 1、二叉树 （重点）
- 叶子节点、根节点、父节点、左子树、右子树、树高
- **满二叉树**：除最后一层无任何子节点，每一层上的所有结点都有两个子结点的二叉树。如果层数是k （根节点高度是0），总节点数量 **(2^k) -1**；第i层至多有**2^（i-1）**个节点



![](http://pyfi676fl.bkt.clouddn.com/FullBinary.jpg)

**练习**： 

**NOIP 2018**. 猜猜一颗深度为**h**的满**k**叉树的总节点数量是多少？ （根节点的深度是0）

**A**. (K ^ （h + 1） - 1) / (K - 1)

**B**. K ^ （h - 1）

**C**. K ^ h 

**D**. K ^ (h - 1) / (K - 1)



**NOIP 2016** 设定根节点的深度是1，一颗节点数量2016的二叉树的最小高度是多少？一颗节点数量2016的二叉树的最少可以有多少子节点？



- **完全二叉树**：所有的叶结点都出现在最后一层或者倒数第二层； 树高是**logN向下取整**。
  

  

![](http://pyfi676fl.bkt.clouddn.com/CompleteBinary.jpg)



- **二叉查找树**：左子树上所有节点的值均小于它的根节点的值；右子树上所有节点的值均大于它的根节点的值；搜索的效率最坏是**O(N)**
  
  
  
  ![](http://pyfi676fl.bkt.clouddn.com/BST.bmp)
  
  
  
  - **按层遍历**
  
  
  
  ![](http://pyfi676fl.bkt.clouddn.com/Breadth-First-Search-Algorithm.gif)
  
  
  
  
  
  - 前中后序列的遍历 （深度优先遍历）
  
  ![](http://pyfi676fl.bkt.clouddn.com/tree1.jpg)
  
  


  ```C++
  PreOrder - 8, 5, 9, 7, 1, 12, 2, 4, 11, 3
  InOrder - 9, 5, 1, 7, 2, 12, 8, 4, 3, 11
  PostOrder - 9, 1, 2, 12, 7, 5, 3, 11, 4, 8
  LevelOrder - 8, 5, 4, 9, 7, 11, 1, 12, 3, 2 
  ```

#### 练习

已知一颗二叉树的前序（先序）**a b d e c** 和中序遍历序列 **d b e a c**，请画出这颗二叉树，它的后序遍历序列是什么？



  ### 链表

  - 与数组的区别（是不连续的空间、不能通过下标直接访问）

  - 单链表 （每一个节点都包含了数据部分Data和一个指针Pointer；头节点和尾节点；如何操作指针进行链表反转？）

    

     ![](http://pyfi676fl.bkt.clouddn.com/%E5%8D%95%E9%93%BE%E8%A1%A8.png)

  - 双链表 （每一个节点包含了数据部分和两个指针）

    

    
     ![](http://pyfi676fl.bkt.clouddn.com/%E5%8F%8C%E9%93%BE%E8%A1%A8.jpg)

  

  ### 栈 （重点）

  

  ![](http://pyfi676fl.bkt.clouddn.com/%E6%A0%88.png)

  

  

  - 两个基本操作：进栈和出栈
  - 栈的应用：汉诺塔，函数的调用（思考一下递归函数如何画栈图）

  ```C++
  //NOIP 2017
  16.对于入栈顺序为a,b,c,d,e,f,g的序列，下列（ ）不可能是合法的出栈序列
  A. a,b,c,d,e,f,g 
  B. a,d,c,b,e,g,f 
  C. a,d,b,c,g,f,e 
  D. g,f,e,d,c,b,a
  ```

#### 课后练习

1353：表达式括号匹配(stack) http://ybt.ssoier.cn:8088/problem_show.php?pid=1353

1331：【例1-2】后缀表达式的值 http://ybt.ssoier.cn:8088/problem_show.php?pid=1331

```C++
//NOIP 2014 提高组
  （双栈模拟数组）只使用两个栈结构stack1和stack2，模拟对数组的随机读取。作为栈结构，stack1和stack2只能访问栈顶（最后一个有效元素）。栈顶指针top1和top2均指向栈顶元素的下一个位置。
  输入第一行包含两个整数，分别是数组长度n和访问次数m，中间用单个空格隔开。第二行包含n个整数，依次给出数组各项（数组下标从0到n-1）。第三行包含m个整数，需要访问的数组下标。对于每次访问，输出对应的数组元素。
  
  #include <iostream>
  using namespace std;
  
  const int SIZE = 100;
  int stack1[SIZE], stack2[SIZE];
  int top1, top2;
  int n, m, i, j;
  
  void clearStack() {
      int i;
      for (i = top1; i < SIZE; i++)
          stack1[i] = 0;
          
      for (i = top2; i < SIZE; i++)
          stack2[i] = 0;
  }
  int main() {
      cin >> n >> m;
      for (i = 0; i < n; i++)
      cin >> stack1[i]; 
      top1 = (1) ; 
      top2 = (2) ;
      for (j = 0; j < m; j++) {
          cin >> i;
          while (i < top1 - 1) {
              top1--; 
              (3) ;
              top2++;
          }
          while (i > top1 - 1) {
              top2--; 
              (4) ;
              top1++;
          }
          clearStack(); 
          cout << stack1[ (5) ] << endl;
      }
      return 0;
  }
```





  ### 队列

  

  ![](http://pyfi676fl.bkt.clouddn.com/%E9%98%9F%E5%88%97.png)

  

  

  - First In First Out 先进先出
  - 两个基本操作：入队和出队
  - 两个栈来实现一个队列 ：

  

  <img src="http://pyfi676fl.bkt.clouddn.com/%E5%8F%8C%E6%A0%88%E6%A8%A1%E6%8B%9F%E9%98%9F%E5%88%97.jpg" style="zoom:150%;" />

#### 练习

**1332：周末舞会** http://ybt.ssoier.cn:8088/problem_show.php?pid=1332

  

  ### 图

  - 顶点、边、度（入度和出度）
  - 有向图和无向图



#### 练习 

**NOIP2016**  **简单无向图G有16条边且每个顶点的度数都是2，则G有多少个顶点？**



  - 有权图和无权图
  - 完全图 （n是顶点数，共n(n-1)/2条边，生成树有n-1条边）
  - 生成树 （无向连通图G的极小连通子图，称为它的生成树，它不是唯一的，可以根据广度优先和深度优先得到）
  - 最短路径问题 (Dijkstra算法，重点)

<img src="http://pyfi676fl.bkt.clouddn.com/Dijkstra_Animation.gif" style="zoom:200%;" />



  - 最小生成树问题( Prim算法)
  - 广度优先和深度优先遍历



#### 练习

求从A到E的最短路径：

<img src="http://pyfi676fl.bkt.clouddn.com/%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84.jpg" style="zoom:200%;" />





  ## 排序（*）

  ### 1、选择排序   (每次选择一个最小的)
  ![](http://pyfi676fl.bkt.clouddn.com/selective_sort.gif)



  ### 2、插入排序
  ![](http://pyfi676fl.bkt.clouddn.com/insert_sort.gif)



  ### 3、归并排序 (需要额外的空间)
  ![](http://pyfi676fl.bkt.clouddn.com/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F.gif)



  ### 4、基数排序
  ![](http://pyfi676fl.bkt.clouddn.com/%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F.gif)

  ### 5、快速排序
  ![](https://user-gold-cdn.xitu.io/2018/11/23/1673e00a0d10d84d?imageslim)

  ### 算法复杂度
  ![](http://pyfi676fl.bkt.clouddn.com/all_sort.png)



  参考 https://github.com/hustcc/JS-Sorting-Algorithm

  ```C++
  
  //NOIP 2017
  17.设A和B是两个长为n的有序数组，现在需要将A和B合并成一个排好序的数组，任何以元素比较作为基本运算的归并算法在最坏情况下至少要做（ ）次比较
  A. n^2 
  B. nlogn 
  C. 2n 
  D. 2n-1
  
  //NOIP 2014
  18. 设有100个数据元素，采用折半搜索时，最大比较次数为（ ）。
  A.6
  B.7
  C.8
  D.10
  ```

#### 课后作业

http://ybt.ssoier.cn:8088/problem_show.php?pid=1176

http://ybt.ssoier.cn:8088/problem_show.php?pid=1186





  ## 往期真题

  2018 https://www.jianshu.com/p/657e6273f861

  2017 https://blog.csdn.net/haishu_zheng/article/details/80096986

  2016 http://www.360doc.com/content/19/0916/17/5315_861417943.shtml

  ## 计划
  - 还要有一些计算机常识题准备
  - 每日一练（10分钟左右，题目从往期试卷中找，要家长配合）
  - 考试前做一次模拟（安排在最后一次课）
