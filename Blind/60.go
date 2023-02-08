package main

// import "sort"

// func missingNumber(nums []int) int {
// 	sort.Ints(nums)
// 	for i, n := range nums {
// 		if i != n {
// 			return i
// 		}
// 	}
// 	return len(nums)
// }

func missingNumber(nums []int) int {
	buckets := make([]bool, len(nums) + 1)
	for _, n := range nums {
		buckets[n] = true
	}
	for i := range buckets {
		if !buckets[i] {
			return i
		}
	}
	return len(nums)
}