package main

import "fmt"

// 関数内で
// p := struct {
// 	name string
// 	age int
// }{
// 	name: "Gopher", 
// 	age: 10,
// }

type MedianFinder struct {
	data []float64
}

func Constructor() MedianFinder {
	return MedianFinder{
		data: make([]float64, 0, 1000),
	}
}

func (this *MedianFinder) AddNum(num int) {
	this.data = append(this.data, float64(num))
}

func (this *MedianFinder) FindMedian() float64 {
	d_len := len(this.data)
	if d_len&1 == 1 {
		return this.data[d_len/2]
	} else {
		return (this.data[d_len/2-1] + this.data[d_len/2]) / 2
	}
}

func main() {
	obj := Constructor()
	obj.AddNum(6)
	fmt.Println(obj.FindMedian())
	obj.AddNum(10)
	fmt.Println(obj.FindMedian())
	obj.AddNum(2)
	fmt.Println(obj.FindMedian())
	obj.AddNum(6)
	fmt.Println(obj.FindMedian())
	obj.AddNum(5)
	fmt.Println(obj.FindMedian())
	obj.AddNum(0)
	fmt.Println(obj.FindMedian())
	obj.AddNum(6)
	fmt.Println(obj.FindMedian())
	obj.AddNum(3)
	fmt.Println(obj.FindMedian())
	obj.AddNum(1)
	fmt.Println(obj.FindMedian())
	obj.AddNum(0)
	fmt.Println(obj.FindMedian())
	obj.AddNum(0)
	fmt.Println(obj.FindMedian())
}


/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */


//  ["MedianFinder","addNum","findMedian","addNum","findMedian"]
//  [[],[6],[],[10],[]]
//  に対応するmain関数は，
//  func main() {
// 	 obj := Constructor()
// 	 obj.AddNum(6)
// 	 fmt.Println(obj.FindMedian())
// 	 obj.AddNum(10)
// 	 fmt.Println(obj.FindMedian())
//  }
//  です。
//  ["MedianFinder","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian","addNum","findMedian"]
//  [[],[6],[],[10],[],[2],[],[6],[],[5],[],[0],[],[6],[],[3],[],[1],[],[0],[],[0],[]]
//  に対応するmain関数を書いてください。