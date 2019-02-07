package applications

import (
	"strings"

	"github.com/x899/algorithms/stack"
)

// InfixToPostfix converts infix expression into postfix expression
func InfixToPostfix(infix string) string {
	operator := stack.NewStack()
	postfix := ""

	for i := 0; i < len(infix); i++ {
		nextCharacter := string(infix[i])

		if nextCharacter == " " {
			continue

		} else if nextCharacter == "(" {
			operator.Push(nextCharacter)

		} else if isDigit(nextCharacter) {
			value := ""
			j := i
			for j < len(infix) && isDigit(string(infix[j])) {
				value = value + string(infix[j])
				j++
			}
			i = j - 1
			postfix += " " + value

		} else if isOperator(nextCharacter) {
			if operator.IsEmpty() {
				operator.Push(nextCharacter)
				continue
			}

			topElement, _ := operator.Peek()
			for getPrecedence(nextCharacter) <= getPrecedence(topElement) &&
				!operator.IsEmpty() {
				op, _ := operator.Pop()
				postfix += " " + op

				if !operator.IsEmpty() {
					topElement, _ = operator.Peek()
				}
			}
			operator.Push(nextCharacter)

		} else if nextCharacter == ")" {

			for !operator.IsEmpty() {
				op, _ := operator.Pop()
				if op == "(" {
					break
				}
				postfix += " " + op
			}
		}
	}

	for !operator.IsEmpty() {
		op, _ := operator.Pop()
		postfix += " " + op
	}
	return strings.TrimSpace(postfix)
}
