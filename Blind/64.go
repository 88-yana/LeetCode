package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func lengthOfLIS(nums []int) int {
	var max_len int
	ans := 1
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] < nums[i+1] {
			max_len++
		} else {
			ans = max(ans, max_len)
			max_len = 0
		}
	}
	return ans
}
