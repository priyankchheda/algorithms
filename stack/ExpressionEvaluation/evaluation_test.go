package main

import "testing"

func TestEvaluationExpression(t *testing.T) {
	tables := []struct {
		expression string
		result     string
	}{
		{"5+6", "11"},
		{"100*2+12", "212"},
		{"100*(2+12)", "1400"},
		{"100*(2+12)/14", "100"},
		{"(5+33)*(456-(34%2345))+45+(0-56)", "16025"},
		{"(5+33)*(456-(34+2345)))", ""},
	}

	for _, table := range tables {
		result, _ := ExpressionEvaluation(table.expression)
		if result != table.result {
			t.Errorf("Evaluation of %s is incorrect, got: %s, want: %s",
				table.expression, result, table.result)
		}
	}
}
