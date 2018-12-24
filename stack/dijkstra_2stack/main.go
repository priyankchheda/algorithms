package main

import (
	"fmt"
	"log"
	"os"
)

// ExpressionEvaluation evalutes the expression using Dijkstra's two stack
// algorithm
func ExpressionEvaluation(expression string) {
	operator := newStack()
	operand := newStack()

	for i := 0; i < len(expression); i++ {
		nextCharacter := string(expression[i])

		if isOpenParentheses(nextCharacter) {
			operator.push(nextCharacter)

		} else if isDigit(nextCharacter) {
			value := ""
			j := i
			for j < len(expression) && isDigit(string(expression[j])) {
				value = value + string(expression[j])
				j++
			}
			i = j - 1
			operand.push(value)

		} else if isOperator(nextCharacter) {
			if operator.isEmpty() {
				operator.push(nextCharacter)
				continue
			}

			topElement, _ := operator.peek()

			for getPrecedence(nextCharacter) <= getPrecedence(topElement) &&
				!operand.isEmpty() &&
				!operator.isEmpty() {
				operand2, _ := operand.pop()
				operand1, _ := operand.pop()
				ops, _ := operator.pop()

				result, err := computeOperation(operand1, operand2, ops)
				if err != nil {
					log.Fatalln("Error: while compute_stack2")
				}
				operand.push(result)

				if !operator.isEmpty() {
					topElement, _ = operator.peek()
				}
			}
			operator.push(nextCharacter)

		} else if isCloseParentheses(nextCharacter) {
			topElement, err := operator.peek()
			if err != nil {
				if serr, ok := err.(*stackError); ok {
					if serr.code == 2 {
						log.Fatalln("Error: Invalid Expression")
					}
				}
			}

			for topElement != "(" && !operator.isEmpty() && !operand.isEmpty() {
				operand2, _ := operand.pop()
				operand1, _ := operand.pop()
				ops, _ := operator.pop()

				result, err := computeOperation(operand1, operand2, ops)
				if err != nil {
					log.Fatalln("Error: while compute_stack")
				}
				operand.push(result)

				if !operator.isEmpty() {
					topElement, _ = operator.peek()
				}
			}

			if topElement == "(" {
				operator.pop()
			}

		} else {
			log.Fatalln("Error: Unknown Character")
		}

		// fmt.Printf("\noperand: %v\n", operand)
		// fmt.Printf("operator: %v\n", operator)
	}

	for !operator.isEmpty() {
		operand2, _ := operand.pop()
		operand1, _ := operand.pop()
		ops, _ := operator.pop()

		result, err := computeOperation(operand1, operand2, ops)
		if err != nil {
			log.Fatalln("Error: while compute_stack1")
		}
		operand.push(result)
	}

	// fmt.Printf("\noperand: %v\n", operand)
	// fmt.Printf("operator: %v\n", operator)

	if !operand.isEmpty() {
		finalResult, _ := operand.pop()
		fmt.Printf("Final Result: %s\n", finalResult)
	}

	if !operand.isEmpty() || !operator.isEmpty() {
		fmt.Printf("\noperand: %v\n", operand)
		fmt.Printf("operator: %v\n", operator)
		log.Fatalln("Error: Stacks are not completely empty")
	}
}

func main() {
	var expression string
	if len(os.Args) == 2 {
		expression = os.Args[1]
	} else {
		log.Fatalln("Error: Needs only one expression for evaluate")
	}
	ExpressionEvaluation(expression)
}
