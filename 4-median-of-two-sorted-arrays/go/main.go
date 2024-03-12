package main

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	i1, i2 := 0, 0
	center := (len(nums1)+len(nums2))/2 + 1
	prev, curr := 0, 0

	for i := 0; i < center; i++ {
		prev = curr
		if i1 < len(nums1) && i2 < len(nums2) {
			if nums1[i1] < nums2[i2] {
				curr = nums1[i1]
				i1++
			} else {
				curr = nums2[i2]
				i2++
			}
		} else if i1 < len(nums1) {
			curr = nums1[i1]
			i1++
		} else {
			curr = nums2[i2]
			i2++
		}
	}

	if (len(nums1)+len(nums2))%2 == 0 {
		return float64(prev+curr) / 2
	}
	return float64(curr)
}

func main() {
	nums1 := []int{1, 3}
	nums2 := []int{2}
	result := findMedianSortedArrays(nums1, nums2)
	println(result)

  nums1 = []int{1, 2}
  nums2 = []int{3, 4}
  result = findMedianSortedArrays(nums1, nums2)
  println(result)
}
