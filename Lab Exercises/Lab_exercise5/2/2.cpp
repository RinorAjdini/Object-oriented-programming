#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{
    private:
        double real;
        double imaginary;
    public:
        void setReal(float real){
            this->real=real;
        }
        void setImaginary(float imaginary){
            this->imaginary=imaginary;
        }
        ComplexNumber(){
            this->real=0;
            this->imaginary=0;
        }
        ComplexNumber(float real, float imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }
        double module(){
            return sqrt(pow(real, 2) + pow(imaginary, 2));
        }
        ComplexNumber &operator=(const ComplexNumber &num){
            if(this==&num) return *this;
            this->real = num.real;
            this->imaginary = num.imaginary;
            return *this;
        }
        friend ostream &operator<<(ostream &os, ComplexNumber &num){
            if(num.real) os<<num.real;
            if(num.real && num.imaginary) os<<"+";
            if(num.imaginary) os<<num.imaginary<<"i"<<endl;
            return os;
        }
        ComplexNumber &operator+(ComplexNumber &num){
            this->real += num.real;
            this->imaginary += num.imaginary;
            return *this;
        }
        ComplexNumber &operator-(ComplexNumber &num){
            this->real -= num.real;
            this->imaginary -= num.imaginary;
            return *this;
        }
        ComplexNumber &operator*(ComplexNumber &num){
            this->real *= num.real;
            this->imaginary *= num.imaginary;
            return *this;
        }
        ComplexNumber &operator/(ComplexNumber &num){
            this->real /= num.real;
            this->imaginary /= num.imaginary;
            return *this;
        }
        bool operator==(ComplexNumber &num){
            return real==num.real && imaginary==num.imaginary;
        }
        bool operator<(ComplexNumber &num){
            if(real<num.real) return true;
            else if(real>num.real) return false;
            return imaginary<num.imaginary;
        }
        bool operator>(ComplexNumber &num){
            if(real>num.real) return true;
            else if(real<num.real) return false;
            return imaginary>num.imaginary;
        }
};

class Equation{
    private:
        ComplexNumber *nums;
        char *operators;
    public:
        friend istream &operator>>(istream &is, Equation &eq){
            char znak = 't';
            float num;
            int index = 0;
            while(znak!='='){
                ComplexNumber *temp = new ComplexNumber[index+1];
                char *opTemp = new char[index+1];
                for(int i=0;i<index;i++){
                    temp[i]=eq.nums[i];
                    opTemp[i]=eq.operators[i];
                }

                is>>num;
                temp[index].setReal(num);
                is>>num;
                temp[index].setImaginary(num);
                is>>znak;
                opTemp[index] = znak;
                index++;

                eq.nums = temp;
                eq.operators = opTemp;
            }
            return is;
        }
        ComplexNumber result(){
            int index = 0;
            ComplexNumber result = this->nums[0];
            while (this->operators[index]!='='){
                switch (this->operators[index]){
                    case '+':
                        result=result+this->nums[index+1];
                        break;
                    case '-':
                        result=result-this->nums[index+1];
                        break;
                    case '*':
                        result=result*this->nums[index+1];
                        break;
                    case '/':
                        result=result/this->nums[index+1];
                        break;
                }
                index++;
            }
            return result;
        }
        double sumModules(){
            double sum = 0;
            sum+=this->nums[0].module();
            for(int i=0;this->operators[i]!='=';i++){
                sum+=this->nums[i+1].module();
            }
            return sum;
        }
};


// Не го менувајте main методот.

int main() {
	int testCase;
	double real, imaginary;
	ComplexNumber first, second, result;

	cin >> testCase;

	if (testCase <= 8) {
		cin >> real;
		cin >> imaginary;
		first = ComplexNumber(real, imaginary);
		cin >> real;
		cin >> imaginary;
		second = ComplexNumber(real, imaginary);
	}

	if (testCase == 1) {
		cout << "===== OPERATOR + =====" << endl;
		result = first + second;
		cout << result;
	}
	else if (testCase == 2) {
		cout << "===== OPERATOR - =====" << endl;
		result = first - second;
		cout << result;
	}
	else if (testCase == 3) {
		cout << "===== OPERATOR * =====" << endl;
		result = first * second;
		cout << result;
	}
	else if (testCase == 4) {
		cout << "===== OPERATOR / =====" << endl;
		result = first / second;
		cout << result;
	}
	else if (testCase == 5) {
		cout << "===== OPERATOR == =====" << endl;
		cout << first;
		cout << second;
		if (first == second)
			cout << "EQUAL" << endl;
		else
			cout << "NOT EQUAL" << endl;
	}
	else if (testCase == 6) {
		cout << "===== OPERATOR > =====" << endl;
		cout << first;
		cout << second;
		if (first > second)
			cout << "FIRST GREATER THAN SECOND" << endl;
		else
			cout << "FIRST LESSER THAN SECOND" << endl;
	}
	else if (testCase == 7) {
		cout << "===== OPERATOR < =====" << endl;
		cout << first;
		cout << second;
		if (first < second)
			cout << "FIRST LESSER THAN SECOND" << endl;
		else
			cout << "FIRST GREATER THAN SECOND" << endl;
	}
	else if (testCase == 8) {
		cout << "===== MODULE =====" << endl;
		double module = first.module();
		cout << first;
		cout << "Module: " << module << endl;
		cout << second;
		module = second.module();
		cout << "Module: " << module << endl;
	}
	else if (testCase == 9) {
		cout << "===== OPERATOR >> & SUM OF MODULES =====" << endl;
		Equation equation;
		cin >> equation;
		cout << equation.sumModules();
	}
	else if (testCase == 10) {
		cout << "===== EQUATION RESULT =====" << endl;
		Equation equation;
		cin >> equation;
		result = equation.result();
		cout << result;
	}
	return 0;
}
