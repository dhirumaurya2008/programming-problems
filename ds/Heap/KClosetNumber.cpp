/*Problem - Given a sorted integer array, find the k closest elements to target in the array where k and target are given positive integers.
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void findKClosestElements(int arr[], int arr_size, int target, int k)
{

   priority_queue<pair<int, int>> pq;
   vector<int> vec;

   for (int i =0; i<k; i++)
   {
       pq.push(make_pair(abs(target - arr[i]), arr[i]));
   }

   for (int i = k; i<arr_size-1; i++)
   {
       pq.push(make_pair(abs(target - arr[i]), arr[i]));
       pq.pop();

   }
   while (pq.size() > 0) {
    vec.push_back(pq.top().second);
    pq.pop();
   }
   cout << k << " closet elements are from << " << target << " :- " << endl ;
   for (int i = 0; i<k; i++)
        cout << vec[i] << " ";

  return ;

}
int main()
{
    int nums[] = { 10, 12, 15, 17, 18, 20, 25 };
    int n = sizeof(nums) / sizeof(nums[0]);

    int target = 16, k = 4;
    cout << "Given Array " << endl ;
    for (int i = 0; i <n ; i++)
        cout << nums[i] << " " ;

    findKClosestElements(nums, n, target, k);
    #if 0
    cout << k << " closet elements are from << " << target << " :- " << endl ;

    for (int i = 0; i<k; i++)
        cout << vec[i] << " ";
        #endif

    return 0;
}
