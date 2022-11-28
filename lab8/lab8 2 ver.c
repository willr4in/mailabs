#include <stdio.h>
#include <math.h>

int abs(int a) {
	if (a > 0) {
		return a;
	}
	else if (a == 0) {
		return 0;
	}
	else {
		return -a;
	}
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	unsigned int n_amount = 1, x_num1 = 1, y_num2 = 1, m_sum_num1 = 0, u_sum_num2 = 0, c_sum = 0, d = pow(10, 8);
	// в переменную d будем записывать разницу между минимальной разницей 2 введенных чисел
	scanf_s("%d", &n_amount);
	while (n_amount != 0) {
		scanf_s("%d", &x_num1);
		scanf_s("%d", &y_num2);
		if (x_num1 > y_num2) {
			m_sum_num1 = m_sum_num1 + x_num1;
		}
		else {
			u_sum_num2 = u_sum_num2 + y_num2;
		}
		c_sum = m_sum_num1 + u_sum_num2;
		n_amount--;
		if (abs(x_num1 - y_num2) % 5 != 0) {
			d = min(d, abs(x_num1 - y_num2));
		}
	}
	if (c_sum % 5 != 0) {
		printf("сумма не делится на 5 %d", c_sum);
	}
	else {
		printf("сумма делилась на 5 %d", c_sum - d);
	}
	return 0;
}
