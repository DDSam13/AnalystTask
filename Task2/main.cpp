#include "analyst.h"
#include <QApplication>
#include <random>
#include <deque>
#include <queue>

const int constMinValue = 0;
const int constMaxValue = 1000;

#define FUNC_NAME(X) "##X"

std::vector<int> doVector(int n) {
    std::vector<int> result;
    result.resize(n);
    std::random_device rd;
    std::uniform_int_distribution<int> dist(constMinValue, constMaxValue);
    for (int i = 0; i < n; ++i) {
        result[i] = dist(rd);
    }
    return result;
}

std::list<int> doList(int n) {
    std::list<int> result;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(constMinValue, constMaxValue);
    for (int i = 0; i < n; ++i) {
        result.push_back(dist(rd));
    }
    return result;
}

std::deque<int> doDeque() {
    std::deque<int> result;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, constMaxValue);
    int n = dist(rd);
    for (int i = 0; i < n; ++i) {
        result.push_back(dist(rd));
    }
    return result;
}

std::queue<int> doQueue() {
    std::queue<int> result;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, constMaxValue);
    int n = dist(rd);
    for (int i = 0; i < n; ++i) {
        result.push(n);
    }
    return result;
}

std::map<int, int> doMap(int n) {
    std::map<int, int> result;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(constMinValue, constMaxValue);
    int count = 0;
    while (count != n) {
        result[count++] = dist(rd);
    }
    return result;
}


uint64_t doSortingVector(std::vector<int> &example) {
    auto start = std::chrono::steady_clock::now();
    std::sort(example.begin(), example.end());
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doSortingList(std::list<int> &example) {
    auto start = std::chrono::steady_clock::now();
    example.sort();
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doInsertionDequeBefore(std::deque<int> &example, int n) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(constMinValue, constMaxValue);
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; ++i) {
        example.push_front(dist(rd));
    }
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doInsertionDequeAfter(std::deque<int> &example, int n) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(constMinValue, constMaxValue);
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; ++i) {
        example.push_back(dist(rd));
    }
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doInsertionDequeRandom(std::deque<int> &example, int n) {
    std::random_device rd;
    std::uniform_int_distribution<int> distIndex(0, example.size() - 1);
    std::uniform_int_distribution<int> distValue(constMinValue, constMaxValue);
    int value = distValue(rd);
    int index = distIndex(rd);

    auto it = example.begin();
    while (index--) {
        ++it;
    }
    auto start = std::chrono::steady_clock::now();
    example.insert(it, n, value);
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doInsertionListAfter(std::list<int> &example, int n) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(constMinValue, constMaxValue);
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; ++i) {
        example.push_back(dist(rd));
    }
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doInsertionListBefore(std::list<int> &example, int n) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(constMinValue, constMaxValue);
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; ++i) {
        example.push_front(dist(rd));
    }
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doInsertionListRandom(std::list<int> &example, int n) {
    std::random_device rd;
    std::uniform_int_distribution<int> distIndex(0, example.size() - 1);
    std::uniform_int_distribution<int> distValue(constMinValue, constMaxValue);
    int value = distValue(rd);
    int index = distIndex(rd);

    auto it = example.begin();
    while (index--) {
        ++it;
    }
    auto start = std::chrono::steady_clock::now();
    example.insert(it, n, value);
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doInsertionQueue(std::queue<int> &example, int n) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(constMinValue, constMaxValue);
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; ++i) {
        example.push(dist(rd));
    }
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doAccessVector(std::vector<int> &example) {
    int count = 1000;
    int n = example.size();
    int value;
    int index;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, n - 1);
    auto start = std::chrono::steady_clock::now();
    while (count--) {
        index = dist(rd);
        value = example[index];
        (void)value;
    }
    auto end = std::chrono::steady_clock::now();
    uint64_t time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return time;
}

uint64_t doAccessMap(std::map<int,int> &example) {
    int count = 1000;
    int n = example.size();
    int value;
    int key;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, n - 1);
    uint64_t time = 0;
    while (count) {
        key = dist(rd);
        if (example.find(key) == example.end()) {
            continue;
        }
        --count;
        auto start = std::chrono::steady_clock::now();
        value = example.at(key);
        auto end = std::chrono::steady_clock::now();
        Q_DECL_UNUSED(value);
        time += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
    return time;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Analyst analyst;

    for (int n = 500; n <= 10000; n += 500) {
        std::vector<int> example = doVector(n);
        analyst.addNewStatistics("SortVector", doSortingVector(example), n);
    }

    for (int n = 500; n <= 10000; n += 500) {
        std::list<int> example = doList(n);
        analyst.addNewStatistics("SortList", doSortingList(example), n);
    }

    for (int n = 500; n <= 10000; n += 500) {
        std::deque<int> exampleInsertionDeque = doDeque();
        analyst.addNewStatistics("InsertoinDequeBefore", doInsertionDequeBefore(exampleInsertionDeque, n), n);
    }

    for (int n = 500; n <= 10000; n += 500) {
        std::deque<int> exampleInsertionDeque = doDeque();
        analyst.addNewStatistics("InsertoinDequeAfter", doInsertionDequeAfter(exampleInsertionDeque, n), n);
    }


    for (int n = 500; n <= 10000; n += 500) {
        std::list<int> exampleInsertionList = doList(1000);
        analyst.addNewStatistics("InsertoinListBefore", doInsertionListBefore(exampleInsertionList, n), n);
    }


    for (int n = 500; n <= 10000; n += 500) {
        std::list<int> exampleInsertionList = doList(1000);
        analyst.addNewStatistics("InsertoinListAfter", doInsertionListAfter(exampleInsertionList, n), n);
    }


    for (int n = 500; n <= 10000; n += 500) {
        std::deque<int> exampleInsertionDeque = doDeque();
        analyst.addNewStatistics("InsertoinDequeRandom", doInsertionDequeRandom(exampleInsertionDeque, n), n);
    }

    for (int n = 500; n <= 10000; n += 500) {
        std::list<int> exampleInsertionList = doList(1000);
        analyst.addNewStatistics("InsertoinListRandom", doInsertionListRandom(exampleInsertionList, n), n);
    }


    for (int n = 500; n <= 10000; n += 500) {
        std::queue<int> exampleInsertionQueue = doQueue();
        analyst.addNewStatistics("InsertoinQueue", doInsertionQueue(exampleInsertionQueue, n), n);
    }

    for (int n = 500; n <= 10000; n += 500) {
        std::vector<int> example = doVector(n);
        analyst.addNewStatistics("AccessVector", doAccessVector(example), n);
    }

    for (int n = 500; n <= 10000; n += 500) {
        std::map<int, int> example = doMap(n);
        analyst.addNewStatistics("AccessMap", doAccessMap(example), n);
    }

    analyst.showStatistics("SortVector");
    analyst.showStatistics("SortList");
    analyst.showStatistics("InsertoinDequeBefore");
    analyst.showStatistics("InsertoinDequeAfter");
    analyst.showStatistics("InsertoinListAfter");
    analyst.showStatistics("InsertoinListBefore");
    analyst.showStatistics("InsertoinDequeRandom");
    analyst.showStatistics("InsertoinListRandom");
    analyst.showStatistics("InsertoinQueue");
    analyst.showStatistics("AccessVector");
    analyst.showStatistics("AccessMap");

    return a.exec();
}
