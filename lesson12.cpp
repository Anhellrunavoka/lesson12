#include <iostream>
using namespace std;
//void Mnozh(int a) {
//    cout << "Number pomnozhit na 5: " << a*5 <<endl;
//}
//void Mnozh_na_seb(int a) {
//    cout << "Number pomnozhit na sebe: " << a * a << endl;
//}
//int main()
//{
//    srand(time(NULL));
//    for (int i = 0; i < 4; i++) {
//        int choice = rand();
//        void(*print)(int) = choice % 2 == 0 ?
//            Mnozh : Mnozh_na_seb;
//         print(3);
//    }
//}
class Koreni {
public:
	virtual void kor() = 0;
};
class Line_rivn :public Koreni {
	double a;
	double b;
public:
	Line_rivn(double a, double b):a(a),b(b){}
	virtual void kor() {
		double x;
		x = b / a;
		if (a != 0) cout << "Koren liniynogo rivnyannya: " << x << endl;
	}
};
class Kvadr_rivn :public Koreni {
	double a;
	double b;
	double c;
public:
	Kvadr_rivn(double a, double b, double c) :a(a), b(b),c(c) {}
	virtual void kor() {
		double x1,x2;
		double D;
		D = b * b - 4 * a * c;
		x1 = -1*(b + sqrt(D)) / 2 * a;
		x2 = -1 *(b - sqrt(D)) / 2 * a;
		if (D>=0) cout << "Koreni kvadrartnogo rivnyannya rivnyannya: " << x1<<" , "<< x2 << endl;
	}
};
int main() {
	Koreni* koren[2];
	koren[0]=new Line_rivn(5,-9);
	koren[1] = new Kvadr_rivn (6, -10, 3);

	for (int i = 0; i < 2; i++) {
		koren[i]->kor();
	}
	for (int i = 0; i < 2; i++) {
		delete koren[i];
	}
	return 0;
}
