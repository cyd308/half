#hdu4393 Throw nails
>有 n(~ 5e4) 个选手 , 每个选手有一个初速度 F(i) (~ 500) , 有一个之后的匀速度 S(i) (~ 100);<br>
>在每一秒我们都会干掉一个当前跑在最前面的选手（如果一样前，那么选id小的）;<br>
>求选手被依次干掉的序列 ;<br>

* 从F(i)入手，考虑到最大只有500 , 所以初速度的优势至多持续到第501s所以 ,所以501s前暴力求 ,
* 之后用sort 啥的搞一下就好了。<br>