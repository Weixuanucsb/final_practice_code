#include <iostream>

using namespace std;

void printReverseArray(int* a, int size){

	for(int i = 0; i < size; i++){
		cout << a[size-1-i] << " ";
	}

	cout << endl;
}

void printReverseArrayRec(int* a, int size){
	if(size == 0) return;
	else{
		printReverseArrayRec(a+1, size-1);
		cout << a[0] << " ";
	}

}

int main(){

	int arr1[] = {20,40,60,80};

	printReverseArray(arr1,4);

	printReverseArrayRec(arr1,4);

	cout << "\n";

	return 0;


}
