package applications

// InfixToPrefix converts infix expression into prefix expression
func InfixToPrefix(infix string) string {
	infixReverse := reverse(infix)

	for i := 0; i < len(infixReverse); i++ {
		nextCharacter := string(infixReverse[i])
		if nextCharacter == "(" {
			infixReverse = infixReverse[:i] + ")" + infixReverse[i+1:]
		} else if nextCharacter == ")" {
			infixReverse = infixReverse[:i] + "(" + infixReverse[i+1:]
		}
	}

	postfix := InfixToPostfix(infixReverse)
	prefix := reverse(postfix)
	return prefix
}
