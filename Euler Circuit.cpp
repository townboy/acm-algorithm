/*混合图欧拉
无向图回路 全部为偶点	通路 只有两个奇点
有向图回路 每个点入度等于出度 通路 存在两个点a,b a出度=入度+1 并且b入度=出度+1
无向图2*n个奇点，则分割成至少n条回路
把该图的无向边随便定向，计算每个点的入度和出度
如果有某个点出入度之差为奇数，那么肯定不存在欧拉回路
有向边直接删掉，无向边按照第一步时的方向建边，容量为1
另新建s和t，对于入度大于出度的点u，连接边u->t，否则连边s->u，容量为出入度差的一半
做网络流看是否满流，满流则存在Euler Circuit欧拉回路
对于欧拉通路,在上一步中如果仅存在两个点度之差为奇数,则在这两个点之间添加一条无向边,接着最大流判满流.*/
