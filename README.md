# DataStructure_C
大家好！欢迎来和我一起学习数据结构。  
本页的数据结构全部使用C语言。  
本页的所有数据结构的知识和代码参考自：  
[1]https://www.dotcpp.com/course/ds/;  
[2]程杰.《大话数据结构》.清华大学出版社.  
里面包含的代码注释了很多自己学习过程中的一些理解，当然，代码肯定不是照着参考资料抄的，那样的作法没有意义，所以里面有很多地方也许还需要优化，欢迎大家提出优化建议。  

开发经验:  
tips1:和链表有关的基本操作（增删操作），定位在操作位置的前一个结点最好，因为通过指针可以看得到后面的结点。

tips2:C语言开发中，如果自定义的函数中要改变函数外某变量的值，传入的参数一定应该是指针类型，否则无法改变你想改变的值；  

tips3:这是一段碎碎念，主要是写下一些在用指针和结构体时遇到的一些比较混淆的概念用法：  

      (1)typedef struct vexnode
        {
		int vertex;
		arcnode* firstarc;
          }adjlist[Vnum];  
        这段代码定义了一个结构体数组变量名"adjlist"，后续写代码如果用"adjust a"意思是建立一个名为a的vexnode数组，a有Vnum个vexnode元素；  
        这要和下面这段代码区分开：  
        typedef struct NAME{
          int a[num];
        }name;  
        这个就比较常用了，就是在结构体name中的一个元素是数组，访问的时候用"name p.a[1]"这样的形式。  
        
        (2)typedef struct Test
           {
	            int num;
	            struct Test *pt;
            }t;  
          上面这段代码的pt是一个指向自己这个结构体的指针，和链表有关的代码中经常看到。举个例子，假设我在后续的代码中有"t temp;",假设temp.num=1,那么如果我想访问这个temp里面的num有两种方法：方法一：使用"temp.num;"。方法二：先将"temp.pt=&temp;"，也就是将temp的地址赋给temp的pt，然后使用"temp.pt->num"来访问temp中的num。兜兜转转绕了一个圈，但是确实都访问到了temp中的num。
          typedef struct Test
          {
	         int num;
           }t,*PT;
           和上一段代码相比，这次有了小改动，我的结构体里只有一个元素num了，然后用typedef定义了一个指向该结构体的指针变量类型pt，假设和上面一样，我定义一个temp.num=1，那么如果我想使用pt来访问这个等于1的num，我可以先用"PT pt=&temp;"，然后直接使用"pt->num;"。。
           综合起来看（2）中的两段代码，可以很明显的感觉到前者是一个整体（数据和指针放到一起），而后者是指针和数据分开。可以根据要求灵活使用。。
           
        
