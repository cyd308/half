#hdu4398 Template Library Management
>有n道关卡(n~ 1e5),第i个关卡需要T(i)型钥匙才能打开(T(i)~1e9)。<br>
>只有经过了第i个关卡，才能去第i+1个关卡，而一开始你有第1,2,3,……,M型钥匙(M~1e5)；<br>
>当你没有当前这关的钥匙时，你可以问你的朋友要这把钥匙，然过这关后，你要决策从当前M+1把中丢掉一把钥匙;<br>
>请问最少要问朋友拿几次钥匙？<br>

* 设dis(i)为第i把钥匙最近一次要用到的关卡的id,<br>
* 当第i把钥匙在之后的关卡中都用不到时，我们令dis(i)=inf ;<br>
* 显然当要丢弃钥匙时，我们选择(dis(i))max的钥匙即可。<br>
* 实现：
* set< make_pair(dis(i),i)> DIS ;<br>
* set< i> cur_key ;<br>
* dis(i) ;<br>
* 想办法维护这三个即可。<br>
