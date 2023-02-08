package main

func isAnagram(s string, t string) bool {
	var mp map[rune]int
	mp = make(map[rune]int)
	for _, r := range t {
		mp[r]++
	}
	for _, r := range s {
		if mp[r] == 0 {
			return false
		}
		mp[r]--
	}
	for _, r := range t {
		if mp[r] != 0 {
			return false
		}
	}
	return true
}