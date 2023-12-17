#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> maxDeque;

    for (int i = 0; i < nums.size(); ++i) {
        // Видаляємо елементи, які вийшли за межі поточного вікна
        while (!maxDeque.empty() && maxDeque.front() < i - k + 1) {
            maxDeque.pop_front();
        }

        // Видаляємо елементи, які менше поточного елемента nums[i]
        while (!maxDeque.empty() && nums[i] > nums[maxDeque.back()]) {
            maxDeque.pop_back();
        }

        // Додаємо поточний індекс у вікно
        maxDeque.push_back(i);

        // Додаємо максимальний елемент у вікні до результату
        if (i >= k - 1) {
            result.push_back(nums[maxDeque.front()]);
        }
    }

    return result;
}

int main() {
    // Приклад використання
    std::vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;

    std::vector<int> result = maxSlidingWindow(nums, k);

    // Виведення результату
    std::cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
