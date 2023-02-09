package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func lengthOfLIS(nums []int) int {
	dp := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
	}
	var ans int
	for _, len := range dp {
		ans = max(ans, len)
	}
	return ans + 1
}

func main() {
	var nums = []int{5,3,2,3,6,8,7}
	fmt.Println(lengthOfLIS(nums))
}
