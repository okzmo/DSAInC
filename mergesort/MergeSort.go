package main

import "fmt"

func merge(l []int, r []int) []int {
	final := []int{}
	i, j := 0, 0

	for i < len(l) && j < len(r) {
		if l[i] < r[j] {
			final = append(final, l[i])
			i++
		} else {
			final = append(final, r[j])
			j++
		}
	}

	for ; i < len(l); i++ {
		final = append(final, l[i])
	}

	for ; j < len(r); j++ {
		final = append(final, r[j])
	}

	return final
}

func mergeSort(numbers []int) []int {
	if len(numbers) < 2 {
		return numbers
	}

	l := mergeSort(numbers[:len(numbers)/2])
	r := mergeSort(numbers[len(numbers)/2:])
	return merge(l, r)
}

func main() {
	numbers := []int{2, 1, 4, 3, 5, 6, 8, 7}
	sorted := mergeSort(numbers)
	fmt.Println(sorted)
}
