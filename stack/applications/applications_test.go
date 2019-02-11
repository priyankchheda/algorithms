package applications_test

import (
	"testing"

	"github.com/x899/algorithms/stack/applications"
)

func TestInfixToPostfix(t *testing.T) {
	tests := []struct {
		infix   string
		postfix string
	}{
		{"3 + 34", "3 34 +"},
		{"34 + 57 * 234 + 12", "34 57 234 * + 12 +"},
		{"(34 + 57) * (234 + 12)", "34 57 + 234 12 + *"},
		{"34 * 57 + 234 * 12", "34 57 * 234 12 * +"},
		{"34 + 57 + 234 + 12", "34 57 + 234 + 12 +"},
		{"( 2 + 1 ) * 45 - ( 20 - 7 ) * ( 4 + 12 )", "2 1 + 45 * 20 7 - 4 12 + * -"},
	}

	for _, test := range tests {
		postfix := applications.InfixToPostfix(test.infix)
		if postfix != test.postfix {
			t.Errorf("wrong output expected: %s got: %s",
				test.postfix, postfix)
		}
	}
}

func TestInfixToPrefix(t *testing.T) {
	tests := []struct {
		infix  string
		prefix string
	}{
		{"3 + 34", "+ 3 34"},
		{"34 + 57 * 234 + 12", "+ 34 + * 57 234 12"},
		{"(34 + 57) * (234 + 12)", "* + 34 57 + 234 12"},
		{"34 * 57 + 234 * 12", "+ * 34 57 * 234 12"},
		{"34 + 57 + 234 + 12", "+ 34 + 57 + 234 12"},
		{"( 2 + 1 ) * 45 - ( 20 - 7 ) * ( 4 + 12 )", "- * + 2 1 45 * - 20 7 + 4 12"},
	}

	for _, test := range tests {
		prefix := applications.InfixToPrefix(test.infix)
		if prefix != test.prefix {
			t.Errorf("wrong output expected: %s got: %s",
				test.prefix, prefix)
		}
	}
}

func TestInfixEvaluation(t *testing.T) {
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
		result, _ := applications.InfixEvaluation(table.expression)
		if result != table.result {
			t.Errorf("Evaluation of %s is incorrect, got: %s, want: %s",
				table.expression, result, table.result)
		}
	}
}
