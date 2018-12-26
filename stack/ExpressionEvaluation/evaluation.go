package main

import (
	"errors"
)

// ExpressionEvaluation evalutes the expression using Dijkstra's two stack
// algorithm
func ExpressionEvaluation(expression string) (string, error) {
	operator := newStack()
	operand := newStack()

	for i := 0; i < len(expression); i++ {
		nextCharacter := string(expression[i])

		if nextCharacter == "(" {
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
				if operand.size() < 2 {
					return "", errors.New("Invalid Expression")
				}
				operand2, _ := operand.pop()
				operand1, _ := operand.pop()
				ops, _ := operator.pop()

				result, err := computeOperation(operand1, operand2, ops)
				if err != nil {
					return "", err
				}
				operand.push(result)

				if !operator.isEmpty() {
					topElement, _ = operator.peek()
				}
			}
			operator.push(nextCharacter)

		} else if nextCharacter == ")" {
			topElement, err := operator.peek()
			if err != nil {
				if serr, ok := err.(*stackError); ok {
					if serr.code == 2 {
						return "", errors.New("Invalid Expression")
					}
				}
			}

			for topElement != "(" && !operator.isEmpty() && !operand.isEmpty() {
				if operand.size() < 2 {
					return "", errors.New("Invalid Expression")
				}
				operand2, _ := operand.pop()
				operand1, _ := operand.pop()
				ops, _ := operator.pop()

				result, err := computeOperation(operand1, operand2, ops)
				if err != nil {
					return "", err
				}
				operand.push(result)

				topElement, err = operator.peek()
				if err != nil {
					if serr, ok := err.(*stackError); ok {
						if serr.code == 2 {
							return "", errors.New("Invalid Expression")
						}
					}
				}
			}

			if topElement == "(" {
				operator.pop()
			}

		} else {
			return "", errors.New("Unknown Character")
		}

		// fmt.Printf("\noperand: %v\n", operand)
		// fmt.Printf("operator: %v\n", operator)
	}

	for !operator.isEmpty() {
		if operand.size() < 2 {
			return "", errors.New("Invalid Expression")
		}
		operand2, _ := operand.pop()
		operand1, _ := operand.pop()
		ops, _ := operator.pop()

		result, err := computeOperation(operand1, operand2, ops)
		if err != nil {
			return "", err
		}
		operand.push(result)
	}

	// fmt.Printf("\noperand: %v\n", operand)
	// fmt.Printf("operator: %v\n", operator)

	var finalResult string
	if !operand.isEmpty() {
		finalResult, _ = operand.pop()
	}

	return finalResult, nil
}
