package main

import "fmt"

func bs(numbers []int) {
	for i := 0; i < len(numbers); i++ {
		for j := 0; j < len(numbers)-i-1; j++ {
			if numbers[j] > numbers[j+1] {
				numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
			}
		}
	}
}

func main() {
	numbers := []int{2, 1, 4, 3, 5}
	bs(numbers)
	fmt.Println(numbers)
}
