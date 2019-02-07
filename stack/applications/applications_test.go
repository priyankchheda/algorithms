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
