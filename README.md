# ListManage
home work shujujiegouyusuanfa

#作业：链表的维护与文件形式的保存

- 要求


用链表结构的有序表表示某商场家电的库存模型。当有提货或进货时需要对该链表进行维护。每个工作日结束之后，将该链表中的数据以文件形式保存，每日开始营业之前，需将以文件形式保存的数据恢复成链表结构的有序表。  
链表结点的数据域包括家电名称（char类型）、品牌（char类型）、单价（int类型）和数量（int类型），以单价的升序体现链表的有序性。程序功能包括：创建表、营业开始（读入文件恢复链表数据）、进货（插入）、提货（更新或删除）、查询信息、更新信息、营业结束（链表数据存入文件）等。

- 文件格式：

应该是一张表格

名称	品牌	单价	数量

2015/11/10 22:20:29 更新
-
- 程序框图：

1.进货：

>输入进货数n。循环输入**名称 品牌 单价 数量**

2.营业开始

>读入文件，恢复数据

3.进货：
>- 用函数**AddNode**
>- 要判断这件货先前存不存在

4.提货、更新：
>某品牌的家电提了几件，提光了就**删掉**，如果提后的数量小于0就**报错**。

5.查询：
>按照**品牌，家电名称，数目，价格**查询

6.营业结束

			
			
			
			

