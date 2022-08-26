package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var n = 250
	var step = 100

	var cells []int = make([]int, n)
	var previous_cells []int = make([]int, len(cells))

	for i := 0; i < n; i++ {
		cells[i] = 0
	}
	var m = int(math.Ceil(float64((n / 2.0))))
	cells[m] = 1
	fmt.Println(cells)

	for j := 0; j < step; j++ {
		for i := 0; i < n; i++ {
			var l, c, r int
			if i == 0 {
				l = cells[n-1]
			} else {
				l = cells[i-1]
			}
			c = cells[i]
			if i == n-1 {
				r = cells[0]
			} else {
				r = cells[i+1]
			}
			var s = fmt.Sprintf("%d%d%d", l, c, r)

			parsed, err := strconv.ParseInt(s, 2, 64)
			if err != nil {
			}
			switch parsed {
			case 1, 2, 3, 4:
				previous_cells[i] = 1
			case 0, 5, 6, 7:
				previous_cells[i] = 0
			}
		}
		_ = copy(cells, previous_cells)
		fmt.Println(cells)

	}

}
