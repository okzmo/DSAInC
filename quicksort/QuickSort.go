package main

import "fmt"

func partition(numbers []int, lo int, hi int) int {
	pivot := numbers[hi]
	idx := lo - 1

	for i := lo; i < hi; i++ {
		if numbers[i] <= pivot {
			idx++
			tmp := numbers[i]
			numbers[i] = numbers[idx]
			numbers[idx] = tmp
		}
	}

	idx++
	numbers[hi] = numbers[idx]
	numbers[idx] = pivot

	return idx
}

func qs(numbers []int, lo int, hi int) {
	if lo >= hi {
		return
	}

	pivot := partition(numbers, lo, hi)

	qs(numbers, lo, pivot-1)
	qs(numbers, pivot+1, hi)
}

func main() {
	numbers := []int{2, 1, 4, 3, 5}
	qs(numbers, 0, len(numbers)-1)
	fmt.Println(numbers)
}
