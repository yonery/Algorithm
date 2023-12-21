// 14891 톱니바퀴 (C++)

#include <stdio.h>
#include <math.h>
int whl[5][8];
void turn_on(int num, int turn)
{
	if (turn == 1) {
		int rm = whl[num][7];
		for (int i = 7; i > 0; i--) {
			whl[num][i] = whl[num][i-1];
		}
		whl[num][0] = rm;
		return;
	}
	if (turn == -1) {
		int rm = whl[num][0];
		for (int i = 1; i < 8; i++) {
			whl[num][i - 1] = whl[num][i];
		}
		whl[num][7] = rm;
		return;
	}
}

int main()
{

	int T;
	int tmp;
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &tmp);
		for (int j = 0; j < 8; j++) {
			whl[i][j] = tmp / (int)pow(10, (7-j));
			tmp = tmp % (int)(pow(10, (7 - j)));
		}
	}

	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int flag1 = 0, flag2 = 0, flag3 = 0;
		if (whl[1][2] != whl[2][6])
			flag1 = 1;
		if (whl[2][2] != whl[3][6])
			flag2 = 1;
		if (whl[3][2] != whl[4][6])
			flag3 = 1;

		int a, b;
		scanf("%d %d", &a, &b);

		switch (a) {
		case 1:
			if (flag1 == 1) {
				if (flag2 == 1) {
					if (flag3 == 1) {
						turn_on(4, b*(-1));
					}
					turn_on(3, b);
				}
				turn_on(2, b*(-1));
			}
			turn_on(1, b);
			break;
		case 2:
			if (flag1 == 1) {
				turn_on(1, b*(-1));
			}
			if (flag2 == 1) {
				if (flag3 == 1) {
					turn_on(4, b);
				}
				turn_on(3, b*(-1));
			}
			turn_on(2, b);
			break;
		case 3 :
			if (flag3 == 1) {
				turn_on(4, b*(-1));
			}
			if (flag2 == 1) {
				if (flag1 == 1) {
					turn_on(1, b);
				}
				turn_on(2, b*(-1));
			}
			turn_on(3, b);
			break;
		case 4 :
			if (flag3 == 1) {
				if (flag2 == 1) {
					if (flag1 == 1) {
						turn_on(1, b*(-1));
					}
					turn_on(2, b);
				}
				turn_on(3, b*(-1));
			}
			turn_on(4, b);
			break;
		default:
			break;
		}

	}
	int sum = 0;
	for (int i = 1; i <= 4; i++)
		sum += whl[i][0]*pow(2, i-1);
	printf("%d", sum);
    return 0;
}

