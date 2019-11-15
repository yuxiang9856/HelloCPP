#include <iostream>
#include <cstring>

using namespace std;

#define NUM 2
#define LEN 30


/*
*In the merge step, the array will be divided by two arrays merged 
*and sorted in ascending order. The one on the left is called the left array, 
*and the one on the right is called the right array.
*/
void merge(char *ms, int startIndex, int midIndex, int endIndex) {
	if (endIndex <= startIndex) {
		return;
	}
	int len_L = midIndex - startIndex + 1 + 1;
	int len_R = endIndex - midIndex + 1;
	char L[len_L];
	char R[len_R];
	for (int i = 0; i < len_L - 1; i++) {
		L[i] = ms[startIndex + i];
	}
	for (int i = 0; i < len_R - 1; i++) {
		R[i] = ms[midIndex + 1 + i];
	}
       
    int i = 0;
    int j = 0;
	for (int k = startIndex; k <= endIndex; k++) {
		if (L[i] < R[i]) {
			ms[k] = L[i];
			i++;
		} else {
			ms[k] = R[j];
			j++;
		}
	}

}

void merger(char a[], int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = l;
	char b[r - l + 1];
	while (i <= m && j <= r) {
		if(a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
	}

	if(i > m)
    {
        for(int p = j; p <= r; p ++)
        {
            b[k++] = a[p];
        }
    }
    else
    {
        for(int p = i; p <= m; p ++)
        {
            b[k++] = a[p];
        }
    }

    //把b[]中排好的元素copy到a[]中
    for(int q = l; q <= r; q ++)
    {
        a[q] = b[q];
    }
}

void mergeSort(char *ms, int startIndex, int endIndex) {
    //If the sequence is divided into the smallest unit (a number), the partition is stopped.
	if (endIndex - startIndex > 0) {
		mergeSort(ms, startIndex, (startIndex + endIndex) / 2);//left partition
		mergeSort(ms, (startIndex+endIndex) / 2 + 1, endIndex);//right partition
		merger(ms, startIndex, (startIndex + endIndex) / 2, endIndex);//merge
	}
	//cout << "The String after mergeSort:" << '\n';
}




int main() {
	char g[7] = {'g','a','n','d','a','l','f'};
	mergeSort(g,0,6);
	cout << "String g after mergeSort:" << '\n';
    for (int i = 0; i < 7; i++) {
    	cout << g[i];
	}
	cout << '\n';
	return 0;
}

