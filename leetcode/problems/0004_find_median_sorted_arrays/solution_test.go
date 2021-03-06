package _004_find_median_sorted_arrays

import (
	"testing"
	"math"
)

func TestFindMedianSortedArrays(t *testing.T) {
	tests := []struct {
		a      []int
		b      []int
		expect float64
	} {
		{a: []int{}, b: []int{1}, expect: 1},
		{a: []int{1}, b: []int{2}, expect: 1.5},
		{a: []int{1}, b: []int{2, 3}, expect: 2},
		{a: []int{1, 2}, b: []int{3, 4}, expect: 2.5},
		{a: []int{4, 5}, b: []int{1, 2, 3}, expect: 3},
		{a: []int{3, 4, 5}, b: []int{1, 2}, expect: 3},
		{a: []int{4, 5, 6}, b: []int{1, 2, 3}, expect: 3.5},
		{a: []int{3, 5, 6}, b: []int{1, 2, 4}, expect: 3.5},
	}
	for _, test := range tests {
		if o := findMedianSortedArrays(test.a, test.b); math.Abs(o - test.expect) > 0.000001 {
			t.Errorf("a=%v, b=%v, out=%f, expect=%f", test.a, test.b, o, test.expect)
		}
	}
}

func TestMin(t *testing.T) {
	tests := []struct{
		a int
		b int
		expect int
	} {
		{a: 1, b: 2, expect: 1},
		{a: 2, b: 1, expect: 1},
		{a: 1, b: 1, expect: 1},
	}
	for _, test := range tests {
		if o := min(test.a, test.b); o != test.expect {
			t.Errorf("a=%d, b%d, out=%d, expect=%d", test.a, test.b, o, test.expect)
		}
	}
}