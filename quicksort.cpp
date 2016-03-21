#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void quicksort(vector<T>& vec, const int first, const int last)
{
  if (first >= last) return;

  int left  = first;
  int right = last;
  const int pivot = vec[first + (last - first) / 2];  // center

  while (true) {
    print(vec, left, right);
    while (vec[left] < pivot) left++;
    while (pivot < vec[right]) right--;

    if (left >= right) break;

    swap(vec[left], vec[right]);
    left++; right--;
  }

  quicksort(vec, first, left - 1);
  quicksort(vec, right + 1, last);
}

template <class T>
void quicksort(vector<T>& vec)
{
  quicksort(vec, 0, vec.size() - 1);
}

int main()
{
  vector<int> nums = { 2, 5, 3, 4, 1, 4, 9, 7, 0 };
  quicksort(nums);

  for (int n : nums) cout << n << " ";
  cout << endl;

  return 0;
}
