package sort

func OddEvenSort(data []int){
	sorted := false
	dataLen := len(data)

	for sorted == false{
		sorted = true
		for i := 1; i < dataLen-1; i+=2 {
			if data[i] > data[i+1] {
				data[i], data[i+1] = data[i+1], data[i]
				sorted = false
			}
		}
		for i := 0; i < dataLen-1; i+=2 {
			if data[i] > data[i+1] {
				data[i], data[i+1] = data[i+1], data[i]
				sorted = false
			}
		}
	}
}
