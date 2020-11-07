package applications

import (
	"errors"

	"github.com/x899/algorithms/stack"
)

// InfixEvaluation evalutes the expression using Dijkstra's two stack
// algorithm
func InfixEvaluation(infix string) (string, error) {
	operator := stack.NewStack()
	operand := stack.NewStack()

	for i := 0; i < len(infix); i++ {
		nextCharacter := string(infix[i])

		if nextCharacter == "(" {
			operator.Push(nextCharacter)

		} else if isDigit(nextCharacter) {
			value := ""
			j := i
			for j < len(infix) && isDigit(string(infix[j])) {
				value = value + string(infix[j])
				j++
			}
			i = j - 1
			operand.Push(value)

		} else if isOperator(nextCharacter) {
			if operator.IsEmpty() {
				operator.Push(nextCharacter)
				continue
			}

			topElement, _ := operator.Peek()

			for getPrecedence(nextCharacter) <= getPrecedence(topElement) &&
				!operand.IsEmpty() &&
				!operator.IsEmpty() {
				if operand.Size() < 2 {
					return "", errors.New("Invalid Expression")
				}
				operand2, _ := operand.Pop()
				operand1, _ := operand.Pop()
				ops, _ := operator.Pop()

				result, err := computeOperation(operand1, operand2, ops)
				if err != nil {
					return "", err
				}
				operand.Push(result)

				if !operator.IsEmpty() {
					topElement, _ = operator.Peek()
				}
			}
			operator.Push(nextCharacter)

		} else if nextCharacter == ")" {
			topElement, err := operator.Peek()
			if err != nil {
				return "", errors.New("Invalid Expression")
			}

			for topElement != "(" && !operator.IsEmpty() && !operand.IsEmpty() {
				if operand.Size() < 2 {
					return "", errors.New("Invalid Expression")
				}
				operand2, _ := operand.Pop()
				operand1, _ := operand.Pop()
				ops, _ := operator.Pop()

				result, err := computeOperation(operand1, operand2, ops)
				if err != nil {
					return "", err
				}
				operand.Push(result)

				topElement, err = operator.Peek()
				if err != nil {
					return "", errors.New("Invalid Expression")
				}
			}

			if topElement == "(" {
				operator.Pop()
			}

		} else {
			return "", errors.New("Unknown Character")
		}
	}

	for !operator.IsEmpty() {
		if operand.Size() < 2 {
			return "", errors.New("Invalid Expression")
		}
		operand2, _ := operand.Pop()
		operand1, _ := operand.Pop()
		ops, _ := operator.Pop()

		result, err := computeOperation(operand1, operand2, ops)
		if err != nil {
			return "", err
		}
		operand.Push(result)
	}

	var finalResult string
	if !operand.IsEmpty() {
		finalResult, _ = operand.Pop()
	}

	return finalResult, nil
}
