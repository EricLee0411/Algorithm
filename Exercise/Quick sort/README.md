# Quick sort
請參考投影片實作出快速排序演算法，並輸出每次有交換的結果。Pivot都是取最左邊的元素。
## Input
一開始會輸入一個整數n，代表接下來會有多少數字需要進行排序，並且接下來會輸入n個整數
### Output
輸出quick sort的排序過程
### Sample input
8  
85 24 63 50 17 51 96 58
### Sample output
85 24 63 50 17 51 96 58  
85 24 63 50 17 51 58 96  
58 24 63 50 17 51 85 96  
58 24 51 50 17 63 85 96  
17 24 51 50 58 63 85 96  
17 24 51 50 58 63 85 96  
17 24 51 50 58 63 85 96  
17 24 50 51 58 63 85 96
