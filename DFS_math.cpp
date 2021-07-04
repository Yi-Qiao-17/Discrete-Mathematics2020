#include<iostream>
using namespace std;
#define LEN 101

int main(){
	int test;
	cin >> test;
	int value = test;
	int* p = nullptr;
	p = new int[test]();
	while (test > 0) {
		test--;
		int vertex,edge;
		cin >> vertex >> edge;
		int array[LEN][LEN] = { NULL };//[直][橫]

		for (int i = 0; i < vertex; i++) {
			for (int j = 0; j < vertex; j++) {
				array[i][j] = 0;
			}
		}
		while (edge > 0) {
			edge--;
			int v1, v2;
			cin >> v1 >> v2;
			array[v1][v2] = 1;
			array[v2][v1] = 1;
		}
		int jugement = 0;
		int juge = 0;
		//先查直
		for (int i = 0; i < vertex; i++) {
			int time = 0;
			for (int j = 0; j < vertex; j++) {
				if (array[j][i] == 1)time++;
			}
			if (time == 0) {
				jugement = 1;
				p[test] = 1;
				juge = 1;
				//cout << "disconnected" << endl;
				break;
			}
		}
		//再查橫
		if (juge == 0) {
			for (int i = 0; i < vertex; i++) {
				int time2 = 0;
				for (int j = 0; j < vertex; j++) {
					if (array[i][j] == 1)time2++;
				}
				if (time2 == 0) {
					jugement = 1;
					p[test] = 1;
					//cout << "disconnected" << endl;
					break;
				}
			}
		}
		if (jugement == 0)p[test] = 0;
			//cout << "connected" << endl;
		
	}
	for (int i = value - 1; i > -1; i--) {
		if(p[i]==1)cout<<"disconnected" << endl;
		else cout<< "connected" << endl;
	}
	delete[]p;

	return 0;
}