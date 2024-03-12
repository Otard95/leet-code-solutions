package main

func start(r rune, last_occurrence map[rune]int, last_repeat int) int {
	if val, exists := last_occurrence[r]; exists && val > last_repeat {
		return val
	}
	return last_repeat
}

func lengthOfLongestSubstring(s string) int {
	max := 0
	last_repeat := 0
	last_occurrence := make(map[rune]int)

	for i, char := range s {
		length := i - start(char, last_occurrence, last_repeat) + 1
		if length > max {
			max = length
		}
		if last_occurrence[char] > last_repeat {
			last_repeat = last_occurrence[char]
		}
		last_occurrence[char] = i + 1
	}

	return max
}
