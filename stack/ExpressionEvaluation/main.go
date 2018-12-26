package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	var expression string
	if len(os.Args) == 2 {
		expression = os.Args[1]
	} else {
		log.Fatalln("Error: Needs only one expression for evaluate")
	}
	result, err := ExpressionEvaluation(expression)
	if err != nil {
		log.Fatalln(err)
	}
	fmt.Println("Result: ", result)
}
