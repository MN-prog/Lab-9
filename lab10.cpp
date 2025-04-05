#include <iostream>

template <typename T>
class MyPriorityQueue 
{
    T* data;
    size_t count;
    size_t capacity;

    void expand() {
        size_t temp = capacity * 2;
        T* newData = new T[temp];
        for(size_t i = 0; i < count; ++i){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = temp;

    }
    void reorder(){
        for (size_t i = 0; i < count; ++i){
            for (size_t j = i + 1; j < count; ++j){
                if (data[i] < data[j]){
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }
public:
    MyPriorityQueue(size_t startcapacity = 6) : count(0), capacity(startcapacity){
        data = new T [capacity];
    } 

    ~MyPriorityQueue() {
        delete[] data;
    }

    void push(const T& item){
        if (count >= capacity)
            expand();
        data[count++] = item;
        reorder(); 
    }

    T pop(){
        if(count == 0){ 
            std::cerr << "error: queue is empty.\n";
            return T();
        }
        T temp =  data[0];
        for (size_t i = 0; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        --count;
        return temp;
    }   

    T peek() const{
        if(count == 0){
            std::cerr << "error: queue is empty.\n";
            return T();
        }
        return data[0];
    }

    size_t size(){
        return count;
    }

    friend std::ostream& operator<<(std::ostream& a, const MyPriorityQueue<T>& temp){
        for (size_t i = 0; i < temp.count; ++i){
            a << temp.data[i] << " ";
        }
        return a;
    }
};

int main()
{
    MyPriorityQueue<int> queue;
    queue.push(10);
    queue.push(15);
    queue.push(20);
    queue.push(111111);

    std::cout << "Queue after pushes: " << queue << std::endl;
    std::cout << "Peek: " << queue.peek() << std::endl;
    queue.pop();
    std::cout << "Queue after pop: " << queue << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    return 0;
}