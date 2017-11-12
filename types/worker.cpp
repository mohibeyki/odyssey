#include <mutex>
#include <pthread.h>
#include <thread>
#include <iostream>
#include <chrono>
#include "worker.h"

using namespace std;

void Worker::Start(int id, std::mutex& iomutex) {
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	{
		std::lock_guard<std::mutex> iolock(iomutex);
		cout << "Thread #" << id << ": on CPU #" << sched_getcpu() << "\n";
	}
	auto start = std::chrono::steady_clock::now();
	this->Tick();
	auto dur = std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::steady_clock::now() - start);
	{
		std::lock_guard<std::mutex> iolock(iomutex);
		cout << dur.count() << "\n";
	}
}

void Worker::addTask(Task* task) {
	this->queue.push_back(task);
}

void Worker::Load() {
	unsigned long i, num;
	for (num = 1; num < this->max; ++num) {
		for (i = 2; i < num && num % i != 0; ++i)
			;
	}
}

void Worker::Tick() {
	if (!this->queue.empty()) {
		Task* currentTask = this->queue.front();
		if (!currentTask->isFinished() && currentTask->isExecutable()) {
			currentTask->Tick();
			this->Load();
			if (currentTask->isFinished()) {
				this->queue.pop_front();
			}
		} else {
			cerr << "Something went wrong" << endl;
		}
	}
}
