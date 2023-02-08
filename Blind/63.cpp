#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
	//内側がtopになるように
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;

	MedianFinder() {}

	void addNum(int num) {
		if (left.empty())
			left.push(num);
		else if (num <= left.top())
			left.push(num);
		else
			right.push(num);
		//leftの方が１つ多いか同じ大きさにする
		if (left.size() - 1 > right.size())
		{
			int temp = left.top();
			left.pop();
			right.push(temp);
		}
		else if (left.size() < right.size())
		{
			int temp = right.top();
			right.pop();
			left.push(temp);
		}
	}

	double findMedian() {
		if (left.size() == right.size())
			return (left.top() + right.top()) / 2.0;
		else
			return left.top();
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
public:
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;

	MedianFinder() {}

	void addNum(int num) {
		if (left.empty())
			left.push(num);
		else if (num <= left.top())
			left.push(num);
		else
			right.push(num);
		if (left.size() - 1 > right.size())
		{
			int temp = left.top();
			left.pop();
			right.push(temp);
		}
		else if (left.size() < right.size())
		{
			int temp = right.top();
			right.pop();
			left.push(temp);
		}
		priority_queue<int> left_copy(left);
		priority_queue<int, vector<int>, greater<int>> right_copy(right);
		cout << "left is ";
		while(!left_copy.empty())
		{
			cout << left_copy.top() << " ";
			left_copy.pop();
		}
		cout << " right is ";
		while(!right_copy.empty())
		{
			cout << right_copy.top() << " ";
			right_copy.pop();
		}
		cout << endl;
	}

	double findMedian() {
		if (left.size() == right.size())
			return (left.top() + right.top()) / 2.0;
		else
			return left.top();
	}
};

int main() {
	MedianFinder* obj = new MedianFinder();
	obj->addNum(1);
	cout << "ans is " << obj->findMedian() << endl;
	obj->addNum(2);
	cout << "ans is " << obj->findMedian() << endl;
	obj->addNum(0);
	cout << "ans is " << obj->findMedian() << endl;
	obj->addNum(10);
	cout << "ans is " << obj->findMedian() << endl;
	obj->addNum(9);
	cout << "ans is " << obj->findMedian() << endl;
	obj->addNum(8);
	cout << "ans is " << obj->findMedian() << endl;
	obj->addNum(7);
	cout << "ans is " << obj->findMedian() << endl;
	obj->addNum(-1);
	cout << "ans is " << obj->findMedian() << endl;
	obj->addNum(11);
	cout << "ans is " << obj->findMedian() << endl;
	return 0;
}