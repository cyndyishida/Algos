//DISCLAIMER : this is not my solution, i just wanted to capture an algorithm my coworker developed for getting O(1) time & space using relative arithmetic


#include <algorithm>
#include <stack>
class MinStack {
public:
	/** initialize your data structure here. */
	std::stack<int64_t> _stack;
	int64_t _min;
	MinStack() : _stack(), _min(0) {}

	void push(int x) {
		if (_stack.empty()) {
			_stack.push(0);
			_min = x;
		}
		else {
        int64_t v = static_cast<int64_t>(x);
			_stack.push(_min -v );
			_min = std::min(_min, v) ;
		}
	}

	void pop() {
		if (_stack.top() > 0) _min = _min + _stack.top();
		_stack.pop();
		if (_stack.empty()) _min = 0;
	}

	int top() {
		if (_stack.top() < 0) return _min - _stack.top();
		else return _min;
	}

	int getMin() {
		return _min;
	}
};

static auto io_sync_off = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();
