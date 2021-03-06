#zstu4193 子序列
>给你A和B两个序列，问最少在A中删掉多少个数可以使得B不为A的子序列。子序列的定义如下：<br>
如果B为A的子序列，则可以在A中删掉一些数使得A序列等于B序列，也就是长度相等，每个位置的数相等。<br>
>A,B的序列长度 <= 2000 ;

* 很明显，当我们在判断 B 串是否是 A 串的子序列时，我们会尽可能让 B 串靠近 A 的前段去匹配：<br>
* 打比方说，我们会采取贪心的原则：<br>
* id 1 2 3 4 5 6<br>
* A  1 2 4 3 2 3<br>
* B  1 2 3<br>
* 当我们贪心的去匹配，肯定是 B(1) 匹配 A(1) , B(2) 匹配 A(2) , B(3) 匹配 A(4) ;
* 而不是 B(2) 匹配 A(5) , B(3) 匹配 B(6) ;<br>
*  也就是如果向令 B(2) 匹配 A(5) , 我们要删掉 A(2) (对于B(3) 匹配 A(6) 要删除 A(4));
*  设pre_B(i): 表示使得 B 中 1～i 这个前缀不为 A 的子序列, A最小要删除的个数；<br>
*  那么答案显然为 min ( pre_B(i) ) ;

#-------------------------------------------------------------------
如果觉得啰嗦，请直接从这开始看：<br>
* dp(i , j) : 表示使的 B(i) 匹配到 A(j) , A至少要删除的元素个数；<br>
* 如果 A 的长度为 n , 那么只要 B(i) 匹配到 A(n+1) 即可 ，此时就等效与是 pre_B(i);<br>
* 剩下的只有转移了：<br>
* dp(i , j) = min (dp(i-1 ,x) + ( [x , j)在A序列的这个区间中B(i)的数量 ) ；<br>
* 显然这个裸得上复杂度为O(m \* n \* n) ;
* 我们可以优化下，设 sumB(i) 为 1～i中 B(i)的个数；<br>
* dp(i , j) = min (dp(i-1 , x) - sumB(x) + sumB(j-1) ) ;<br>
* 及我们之需求出前缀 dp(i-1 , x) - sumB(x) 的最小值即可；<br>
* 这样的复杂度为 O(m*n) ;<br>