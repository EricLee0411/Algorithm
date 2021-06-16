# Dijkstra's algorithm
Dijkstra's algorithm使用類似廣度優先搜尋的方法解決單源最短路徑問題。
演算法的流程執行範例如下圖，範例為從s點尋找至d點的最短路徑。
 
## Input
首先第一行會輸入兩個字元(s, d)，代表目標為找出s到d的最短路徑，接著會輸入一個整數n，代表接下來會有n條有向且有權重的邊，接下來的n行輸入，每行會有兩格字元(a,b)及一個整數(m)，代表有一條邊由a連至b且權重為m。
## Output
輸出s至d的最短路徑長
### Sample input
s d  
10  
s a 6  
s c 3  
a c 4  
a b 2  
b d 1  
c a 2  
c b 3  
c d 5  
d a 1  
d a 5
### Sample output
7

