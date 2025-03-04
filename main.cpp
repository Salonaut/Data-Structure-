#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "Deque.h"
#include "QueueWithTwoStack.h"
#include "BinaryTree.h"
#include "GeneralTree.h"

int main() {

    int arr[] {5,12,7,1,3,41,5,3,98};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (auto i : arr) {
        cout << i << " ";
    }

    binaryTreeSort(arr, size);

    cout << endl;

    for (auto i : arr) {
        cout << i << " ";
    }






    return 0;
}
