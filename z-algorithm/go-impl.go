package main

import "fmt"

// This function is to generate z array in O(m+n) time where m is length of text and n is length of pattern
func generateZArr(str string) []int {
	zArr := make([]int, len(str))
	var left = 0
	var right = 0
	var k = 0
	for k = 1 ; k< len(str); k++ {
		if k > right {
			left = k
			right = k
			for {
				if right < len(str) && str[right] == str[right - left] {
					right++
				} else {
					break
				}
			}
			zArr[k] = right-left
			right--
		} else {
			k1 := k - left
			if zArr[k1] < right - k + 1 {
				zArr[k] = zArr[k1]
			} else {
				left = k
				for {
					if right < len(str) && str[right] == str[right - left] {
						right++
					} else {
						break
					}
				}
				zArr[k] = right - left
				right--
			}
		}
	}
	return zArr
}

func isMatchPattern(text, pattern string) bool {
	isPatternMatched := false
	// we will add the two string into and with a character in the middle of the two string which is not present either
	// of the two strings. we are using "$" here.
	fullText := text+"$"+pattern
	zArr := generateZArr(fullText)
	for i := range zArr {
		if zArr[i] == len(pattern) {
			isPatternMatched = true
			return isPatternMatched
		}
	}

	return isPatternMatched
}

func main() {
	str := "aabkcad"
	str1 := "aabc"
	fmt.Println(isMatchPattern(str, str1))
}
