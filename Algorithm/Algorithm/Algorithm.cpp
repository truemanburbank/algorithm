#include <iostream>
#include <vector>
using namespace std;

// capacity와 size의 차이
// capacity는 배열의 용량
// size는 배열의 원소 수
// capacity == size이면 capacity = 1.5 * capacity로
// capacity를 증가시킨다.

// reserve와 resize의 차이
// reserve는 용량과 관계 있고
// resize는 원소의 개수와 관련 있다.
// resize 할 시 현재 배열의 capacity가 resize할 size보다 작으면
// capacity == resize의 size로 바뀐다.

template<typename T>
class Vector
{
public:
    Vector()
    {

    }

    ~Vector()
    {
        if (_data)
            delete[] _data;
    }

    // 삽입
    void push_back(const T& value)
    {
        // 배열이 꽉 찼으면 capacity를 늘린 새 배열에 
        // 원래의 원소 복사 후 그 뒤 새로운 원소도 삽입
        if (_size == _capacity)
        {
            // 증설 작업
            int newCapacity = static_cast<int>(_capacity * 1.5);

            // 1.5를 곱했는데도 new가 기존 것과 같을 경우 임의로 newCapacity 값을 증가
            if (newCapacity == _capacity)
                newCapacity++;

            // 자리 증설
            reserve(newCapacity);
        }

        // 데이터 저장
        _data[_size] = value;

        // 데이터 개수 증가
        _size++;
    }

    // capacity를 예약하는 함수
    void reserve(int capacity)
    {
        // 이미 우리가 가진 capacity가 더 클 경우, 무시
        if (_capacity >= capacity)
            return;

        _capacity = capacity;

        T* newData = new T[_capacity];

        // 기존 데이터 복사
        for (int i = 0; i < _size; i++)
        {
            newData[i] = _data[i];
        }

        // 원래의 데이터 자리 날림
        if (_data)  // NULL 체크
            delete[] _data;

        // 교체
        _data = newData;
    }

    T& operator[](const int pos) { return _data[pos]; }

    int size() { return _size; }
    int capacity() { return _capacity; }

    void clear()
    {
        if (_data)
        {
            delete[] _data;
            _data = new T[_capacity];
        }

        _size = 0;
    }

private:
    T* _data = nullptr; // 동적 배열의 시작 위치
    int _size = 0;
    int _capacity = 0;
};

int main()
{
    vector<int> v;

    v.resize(10); // _size와 연관, capacity가 모자라면 자동으로 capacity == size
    cout << v.size() << " " << v.capacity() << endl;

    // 초반 증설 오버헤드를 줄이기 위해
    v.reserve(100); // _capacity와 연관
    cout << v.size() << " " << v.capacity() << endl;

    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);

        // size: 현재 벡터에 할당된 원소 수
        // capacity: 예약된 총 공간
        cout << v.size() << " " << v.capacity() << endl;
    }

    // 한 번 늘어난 capacity는 어지간하면 줄어들지 않는다.
    v.clear();
    cout << v.size() << " " << v.capacity() << endl;
}
