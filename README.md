## 散布熵算法描述

### (1)

#### 首先，对给定的输入序列 $X$，由其正态累积分布函数(NCDF)生成新的时间序列 $Y =\{y_1, y_2,\cdots,y_L\}$，并且 $y_j\in[0, 1]$。

$$
	      \begin{align}
		      y_j=\frac{1}{\sigma\sqrt{2\pi}}\int_{-\infty}^{x_i}e^{\frac{-(t-\mu)^2}{2\sigma^2}}dt
	      \end{align}
$$

#### 然后，采用线性算法将 $y_j (j = 1, 2,\cdots , L)$映射到 $c$个类，其中 $1$到 $c$是整数索引。信号中每个映射的元素表示为：

$$
	      \begin{align}
		      z_j^c=Round(c\cdot y_j+0.5)
	      \end{align}
$$

#### 其中 $z_j^c$是分类时间序列的第 $j$个元素， $Round(\cdot)$标识 $Round$舍入操作。

### (2)

#### 对于嵌入维数 $m$，类数目 $c$和时间延迟 $d$，嵌入向量 $z_i^{m,c}$按下式构造：

$$
\begin{align}
		      z_i^{m,c}=\{z_i^c,z_{i+d}^c,\cdots,z_{i+(m-1)d}^c\}
	      \end{align}
$$

#### 其中 $i=1,2,\cdots,L-(m-1)d$。然后，每个 $z_i^{m,c}$映射为一个分散模式(DispersionPattern) $\pi_{\nu_0,\nu_1,\cdots,\nu_{m-1}}$， $z_i^c=\nu_0,z_{i+d}^c=\nu_1,\cdots,z_{i+(m-1)d}^c=\nu_{m-1}$。每一 $z_i^{m,c}$可行分散模式总数为 $c^m$。

### (3)

#### 每个分散模式的相对频率可按下式计算：

$$
	      \begin{align}
		      p(\pi_{\nu_0,\nu_1,\cdots,\nu_{m-1}})=\frac{Number \ \{i|i\leq-(m-1)d,z_i^{m,c} \ has \ type \ \pi_{\nu_0,\nu_1,\cdots,\nu_{m-1}}\}}{L-(m-1)d}
	      \end{align}
$$

#### 注意 $L-(m-1)d$是嵌入向量的总数。

### (4)

#### 最后，DE的类数为 $c$，嵌入维数 $m$和时间延迟 $d$，根据Shannon熵定义，可计算分散熵为：

$$
	      \begin{align}
		      DE(X,m,c,d)=-\sum_{\pi=1}^{c_m}p(\pi_{\nu_0,\nu_1,\cdots,\nu_{m-1}})\ln (p(\pi_{\nu_0,\nu_1,\cdots,\nu_{m-1}}))
	      \end{align}
$$

## 参考文章

### 1.原始论文：《Dispersion Entropy: A Measure for Time Series Analysis》

### 2.具体的计算步骤，方便更好理解：<https://zhuanlan.zhihu.com/p/539611038>
