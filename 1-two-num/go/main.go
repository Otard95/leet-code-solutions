package main

import "fmt"

func twoSum(nums []int, target int) []int {
  rests := make(map[int]int)

  for i, num := range nums {
    j, exists := rests[num]
    if exists {
      return []int{j, i}
    }
    rests[target - num] = i
  }

  return []int{}
}

func main() {
  nums := []int{2, 7, 11, 15}
  target := 9
  result := twoSum(nums, target)
  fmt.Println(result)
}
