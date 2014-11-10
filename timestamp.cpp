template<typename T>
class Request {
	T element;
	Time timestamp;
};
class ServerTime {
public:
	void add(Request q) {
		req.push_back(q);
		while (req.front().timestamp - q.timestamp > 1 hour) {
			req.pop_front();
		}
		while (req[m].timestamp - q.timestamp > 1 min) {
			m--;
			cnt--;
		}
		while (req[s].timestamp - q.timestamp > 1 second) {
			s--;
			cnt--;
		}
	}	
private:
	deque<Request> req;
	int s;
	int m;
};
