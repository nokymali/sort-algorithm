# 1. sort algorithm

## 1.1 sort-bubble 
  bubble sort type: ST_BUBBLE
## 1.2 sort-selection 
  selection sort, TYPE: ST_SELECTION,
## 1.3 sort-insertion
   insertion sort, type: ST_INSERTION 
## 1.4 sort-merge
   merge sort, type: ST_MERGE
## 1.5 sort-quick
   quick sort, type: ST_QUICK
## 1.6 sort-heap
   heap sort, type: ST_HEAP
## 1.7 sort-shell
   shell sort, type: ST_SHELL
## 1.8 sort-counting
   counting sort, type: ST_COUNTING
## 1.9 sort-bucket
   bucket sort, type: ST_BUCKET
## 1.10 sort-radix
   radix sort, type: ST_RADIX
## 1.11 sort-cocktail
   cocktail sort. type: ST_COCKTAIL



# 2. Compare

| algorithm | TC(average) | TC (worst case) | Space complexity | Stability | scenarios                                                  |
|-----------|-------------|-----------------|------------------|-----------|------------------------------------------------------------|
| bubble    | O(n²)       | O(n²)           | O(1)             | ✓         | Teaching, small-scale data                                 |
| selection | O(n²)       | O(n²)           | O(1)             | ✓         | Simple implementation, small data volume                   |
| insertion | O(n²)       | O(n²)           | O(1)             | ✓         | The data is generally well-organized and of a small scale. |
| merge     | O(n log n)  | O(n log n)      | O(n)             | ✓         | Require stability and large data volume                    |
| quick     | O(n log n)  | O(n²)           | O(log n)         | ✗         | General preference, large-scale random data                |
| heap      | O(n log n)  | O(n log n)      | O(1)             | ✗         | Memory-constrained, Top K problem                          |
| shell     | O(n log² n) | O(n²)           | O(1)             | ✗         | Medium-sized data                                          |
| counting  | O(n + k)    | O(n + k)        | O(k)             | ✓         | The range of integers is small and dense.                  |
| bucket    | O(n + k)    | O(n²)           | O(n + k)         | ✓         |                                                            |
| radix     | O(nk)       | O(nk)           | O(n + k)         | ✓         |                                                            |
| cocktail  |             |                 |                  |           |                                                            |

