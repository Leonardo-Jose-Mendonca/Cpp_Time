//Time aplication
#include <iostream>
#include <chrono>
#include <ctime>
using std::cout;
int main() {
	/******************** chrono steady_clock declarations *******************/
	using pointer_steady = std::chrono::steady_clock::time_point;
	pointer_steady timePointer;
	double time_begin, time_now, time_period;
	const float max_period = 500000;			//steady_clock precision is 1ns - time scale to 500us
	int sec = 0;
	timePointer = std::chrono::steady_clock::now();
	time_begin = timePointer.time_since_epoch().count();
	int _printAdjusterTime = 0;

	/******************** ctime time declarations ****************************/
	time_t	varTime, _time_begin, _time_now, _time_period;
	const float _max_period = 1;				//time_t precision is 1s - time scale to 1s
	int _sec = 0;
	varTime = time(NULL);
	_time_begin = varTime;

	/******************** ctime clock declarations ***************************/
	clock_t varClock, clock_begin, clock_now, clock_period;
	const float max_period_clock = 1;			//clock_t precision is 1ms - time scale to 1ms
	int __sec = 0;
	varClock = clock();
	clock_begin = varClock;
	int printAdjusterTime = 0;

	do {
	/******************** chrono steady_clock test ***************************/
		timePointer = std::chrono::steady_clock::now();
		time_now = timePointer.time_since_epoch().count();
		time_period = time_now - time_begin;
		if (time_period >= max_period) {
			sec++;
			_printAdjusterTime++;
			if (_printAdjusterTime >= 200000000 / max_period) {			//allows the print in each 200ms
				cout << "chrono time: " << (sec * (max_period/1000)) << "us" << std::endl;
				_printAdjusterTime = 0;
			}
			timePointer = std::chrono::steady_clock::now();
			time_begin = timePointer.time_since_epoch().count();
			time_now = time_begin;
			time_period = time_now - time_begin;
		}
	/******************** ctime time test ************************************/
		varTime = time(NULL);
		_time_now = varTime;
		_time_period = _time_now - _time_begin;
		if (_time_period >= _max_period) {
			_sec++;
			cout << "ctime  time: " << _sec << "s" << std::endl;
			varTime = time(NULL);
			_time_now = varTime;
			_time_begin = varTime;
			_time_period = _time_now - _time_begin;
		}
	/******************** ctime clock test ***********************************/
		varClock = clock();
		clock_now = varClock;
		clock_period = clock_now - clock_begin;
		if (clock_period >= max_period_clock) {
			__sec++;
			printAdjusterTime++;
			if (printAdjusterTime >= 200/max_period_clock) {			//allows the print in each 200ms
				cout << "ctime clock: " << __sec << "ms" << std::endl;
				printAdjusterTime = 0;
			}
			varClock = clock();
			clock_now = varClock;
			clock_begin = varClock;
			clock_period = clock_now - clock_begin;
		}
	} while(true);
}