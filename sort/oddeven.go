package sort

//Odd-Even Sort is a variation of bubble sort where the sorting is divided into
//two phases, Odd and Even Phase and it runs until all the elements are sorted
//In the odd phase we perform bubble sort on odd indexed elements and in the
//even phase we perform bubble sort on even indexed elements.

func OddEvenSort(data []int) {
	sorted := false
	dataLen := len(data)

	for {
		sorted = true
<<<<<<< HEAD
		for i := 1; i < dataLen-1; i += 2 {
=======
		for i := 1; i < dataLen-1; i+=2 {
>>>>>>> 1f0f09e... Update oddeven.go
			if data[i] > data[i+1] {
				data[i], data[i+1] = data[i+1], data[i]
				sorted = false
			}
		}
<<<<<<< HEAD
		for i := 0; i < dataLen-1; i += 2 {
=======
		for i := 0; i < dataLen-1; i+=2 {
>>>>>>> 1f0f09e... Update oddeven.go
			if data[i] > data[i+1] {
				data[i], data[i+1] = data[i+1], data[i]
				sorted = false
			}
		}
		if sorted {
			break
		}
	}
}
