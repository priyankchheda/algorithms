package main

import "strconv"

func isDigit(char string) bool {
	_, err := strconv.Atoi(char)
	return err == nil
}

func isOpenParentheses(char string) bool {
	openParentheses := [3]string{"(", "{", "["}
	for _, elem := range openParentheses {
		if elem == char {
			return true
		}
	}
	return false
}

func isCloseParentheses(char string) bool {
	closeParentheses := [3]string{")", "}", "]"}
	for _, elem := range closeParentheses {
		if elem == char {
			return true
		}
	}
	return false
}

func isOperator(char string) bool {
	operator := [5]string{"+", "-", "*", "/", "%"}
	for _, elem := range operator {
		if elem == char {
			return true
		}
	}
	return false
}
