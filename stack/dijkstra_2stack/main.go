package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
)

func main() {
	var expression string
	if len(os.Args) == 2 {
		expression = os.Args[1]
	} else {
		log.Fatalln("Error: Needs only one expression for evaluate")
	}

	operator := newStack()
	operand := newStack()

	for i := 0; i < len(expression); i++ {
		if isOpenParentheses(string(expression[i])) {
			continue
		} else if isDigit(string(expression[i])) {
			value := ""
			j := i
			for j < len(expression) && isDigit(string(expression[j])) {
				value = value + string(expression[j])
				j++
			}
			i = j - 1
			operand.push(value)
		} else if isOperator(string(expression[i])) {
			operator.push(string(expression[i]))
		} else if isCloseParentheses(string(expression[i])) {
			operand1_str, _ := operand.pop()
			operand2_str, _ := operand.pop()
			operator, _ := operator.pop()

			operand1, _ := strconv.Atoi(operand1_str)
			operand2, _ := strconv.Atoi(operand2_str)

			var result int
			switch operator {
			case "+":
				result = operand1 + operand2
			case "-":
				result = operand1 - operand2
			case "*":
				result = operand1 * operand2
			case "/":
				result = operand1 / operand2
			case "%":
				result = operand1 % operand2
			}

			operand.push(strconv.Itoa(result))
		} else {
			log.Fatalln("Error: Unknown Character")
		}
		fmt.Printf("\noperand: %v\n", operand)
		fmt.Printf("operator: %v\n", operator)
	}
}
